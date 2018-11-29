Imports System.Net.Http
Imports System.Text
Imports System.Threading
Imports System.Web.Script.Serialization

Public Class GameplayForm

    Public Structure GameMove
        Public PlayerSymbol As String
        Public SelectedTile As Integer
    End Structure

    Public Enum GameDifficulty
        Easy
        Hard
    End Enum

    'HTTP data structures
    Private client As HttpClient
    Private serverURI As UriBuilder
    Private server As String

    'Game data structures
    Private currentPlayer As String
    Private numPlayers As Integer
    Private boardstate(8) As String
    Private moveNum As Integer
    Private ackCounter As Integer
    Private MoveInProgress As Boolean
    Private difficulty As GameDifficulty
    Private addImage As Boolean
    Private threadRunning As Boolean
    Private addImageStartTime As DateTime

    Public Sub New(ByVal numPlay As Integer, ByVal diff As GameDifficulty)

        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D

        ' This call is required by the designer.
        InitializeComponent()

        'set current player to X (starting)
        currentPlayer = "X"

        'set number of players and difficulty
        numPlayers = numPlay
        difficulty = diff
        MoveInProgress = False

        beamerBox.Visible = False
        addImage = False

        'reset all tiles
        ResetTiles()

        'set status label
        status.Text = "Waiting for player: " + currentPlayer
        picstatus.Text = "Waiting for move"
        picstatus.BackColor = Color.Yellow

        'set http connection
        client = New HttpClient()
        serverURI = New UriBuilder()
        serverURI.Host = "192.168.1.100"
        serverURI.Port = "2000"
        server = serverURI.ToString()

        'spin up thread for polling status
        threadRunning = True
        Dim pollThread As Thread = New Thread(AddressOf statusPoll)
        pollThread.IsBackground = True
        pollThread.Start()

        ackCounter = 0

    End Sub

    'thread function for polling server
    Private Sub statusPoll()
        Dim pictimer As New Stopwatch
        While threadRunning
            GetServerInfo()
            If addImage Then
                addPicture()
                addImage = False
                pictimer.Start()
            End If
            If pictimer.ElapsedMilliseconds > 4800 Then
                Me.Invoke(Sub() beamerBox.Visible = False)
                pictimer.Reset()
            End If
            System.Threading.Thread.Sleep(250)
        End While
    End Sub

    Private Async Sub GetServerInfo()
        Dim statusStr As String = "{""Source"":""GUI"", ""Type"":""Status""}"
        Dim statusMsg As HttpContent = New StringContent(statusStr, Encoding.UTF8, "application/json")
        Dim parser As New JavaScriptSerializer()
        Dim resp As HttpResponseMessage
        Dim respStr As String = ""
        Dim FSRdata As UInt16
        Dim roverPos As Integer
        Dim badconnection As Boolean = False
        Dim currentLabel As Label
        Try
            resp = Await client.PostAsync(server, statusMsg)
            respStr = Await resp.Content.ReadAsStringAsync()
            Me.Invoke(Sub() picstatus.Text = "Server Connected")
            Me.Invoke(Sub() picstatus.BackColor = Color.Green)
        Catch ex As Exception
            badconnection = True
        End Try
        Try
            'Parse JSON message
            Dim jsonMsg = parser.DeserializeObject(respStr)
            If Not Convert.ToInt32(jsonMsg("Ackno")) = ackCounter Then
                ackCounter = Convert.ToInt32(jsonMsg("Ackno"))
                If MoveInProgress Then
                    MoveInProgress = False
                    EnableButtons()
                    NextMove()
                End If
            End If
            roverPos = Convert.ToInt32(jsonMsg("RoverPosition"))
            moveRover(roverPos)
            FSRdata = Convert.ToUInt16(jsonMsg("FSR"))
            For i As Integer = 0 To 9
                currentLabel = Me.Controls.Find("sensor" + i.ToString(), True).FirstOrDefault()
                If ((FSRdata >> i) And 1) = 1 Then
                    Me.Invoke(Sub() currentLabel.BackColor = Color.Red)
                Else
                    Me.Invoke(Sub() currentLabel.BackColor = Color.Black)
                End If
            Next
        Catch ex As Exception
            badconnection = True
        End Try
        If badconnection Then
            Try
                Me.Invoke(Sub() picstatus.Text = "Bad Server Connection")
                Me.Invoke(Sub() picstatus.BackColor = Color.Red)
            Catch ex As Exception
                'no handling
            End Try
        End If
    End Sub

    Private Sub moveRover(ByRef position As Integer)
        Dim pos As Point
        Select Case position
            Case 0
                pos = New Point(264, 277)
            Case 1
                pos = New Point(328, 277)
            Case 2
                pos = New Point(388, 277)
            Case 3
                pos = New Point(461, 277)
            Case 4
                pos = New Point(536, 277)
            Case 5
                pos = New Point(536, 210)
            Case 6
                pos = New Point(536, 142)
            Case 7
                pos = New Point(536, 77)
            Case 8
                pos = New Point(536, 1)
            Case 9
                pos = New Point(461, 1)
            Case 10
                pos = New Point(388, 1)
            Case 11
                pos = New Point(328, 1)
            Case 12
                pos = New Point(264, 1)
            Case 13
                pos = New Point(264, 77)
            Case 14
                pos = New Point(264, 142)
            Case 15
                pos = New Point(264, 210)
            Case Else
                pos = New Point(264, 277)
        End Select
        Me.Invoke(Sub() roverImg.Location = pos)
    End Sub

    Public Sub NextMove()
        Dim AIMove As GameMove
        Dim AITile As Button

        If MoveInProgress Then
            status.Text = "Move in progress"
            Exit Sub
        End If

        'check for three in a row
        If ThreeInRow() = True Then
            DisableButtons()
            addImage = True
            Exit Sub
        End If

        'switch current player
        If currentPlayer = "X" Then
            currentPlayer = "O"
        Else
            currentPlayer = "X"
        End If

        'check for AI move
        If numPlayers = 1 And currentPlayer = "O" Then
            AIMove = PerformAIMove()
            AITile = Me.Controls.Find("tile" + AIMove.SelectedTile.ToString(), True).FirstOrDefault()
            Me.Invoke(Sub() AITile.Text = AIMove.PlayerSymbol)
            Me.Invoke(Sub() AITile.Enabled = False)
            currentPlayer = "X"
            'check for three in a row
            If ThreeInRow() = True Then
                DisableButtons()
                addPicture()
                Exit Sub
            End If
        Else
            Me.Invoke(Sub() status.Text = "Waiting for player: " + currentPlayer)
        End If

        If moveNum = 8 Then
            Me.Invoke(Sub() status.Text = "Game Over!")
        End If

    End Sub

    Private Sub addPicture()
        If numPlayers = 1 And Not status.Text.IndexOf("X") = -1 Then
            Me.Invoke(Sub() beamerBox.Visible = True)
        End If
    End Sub

    Private Function ThreeInRow() As Boolean
        Dim found As Boolean = False
        If boardstate(0) = boardstate(1) And boardstate(1) = boardstate(2) And boardstate(0) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile0.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile1.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile2.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(0) + " wins!")
        ElseIf boardstate(3) = boardstate(4) And boardstate(4) = boardstate(5) And boardstate(5) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile3.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile4.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile5.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(5) + " wins!")
        ElseIf boardstate(6) = boardstate(7) And boardstate(7) = boardstate(8) And boardstate(8) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile6.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile7.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile8.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(8) + " wins!")
        ElseIf boardstate(0) = boardstate(4) And boardstate(4) = boardstate(8) And boardstate(0) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile0.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile4.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile8.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(0) + " wins!")
        ElseIf boardstate(2) = boardstate(4) And boardstate(4) = boardstate(6) And boardstate(2) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile2.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile4.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile6.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(2) + " wins!")
        ElseIf boardstate(0) = boardstate(3) And boardstate(3) = boardstate(6) And boardstate(0) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile0.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile3.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile6.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(0) + " wins!")
        ElseIf boardstate(1) = boardstate(4) And boardstate(4) = boardstate(7) And boardstate(1) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile1.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile4.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile7.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(1) + " wins!")
        ElseIf boardstate(2) = boardstate(5) And boardstate(5) = boardstate(8) And boardstate(5) <> "Empty" Then
            found = True
            Me.Invoke(Sub() tile2.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile8.BackColor = Color.LightGreen)
            Me.Invoke(Sub() tile5.BackColor = Color.LightGreen)
            Me.Invoke(Sub() status.Text = "Player " + boardstate(3) + " wins!")
        End If
        Return found
    End Function

    Private Sub ResetTiles()
        'Set all tiles to empty and enable all
        Dim myControlToFind As Button
        Dim controlString As String

        For i As Integer = 0 To 8
            boardstate(i) = "Empty"
        Next
        currentPlayer = "X"

        moveNum = 0

        For i As Integer = 0 To 8
            controlString = "tile" + i.ToString()
            myControlToFind = Me.Controls.Find(controlString, True).FirstOrDefault()
            myControlToFind.Text = ""
            myControlToFind.Enabled = True
            myControlToFind.Font = New Font("Comic Sans MS", 36, FontStyle.Bold)
            myControlToFind.BackColor = Color.Transparent
        Next
    End Sub

    Public Function PerformAIMove() As GameMove
        Dim AIMove As GameMove
        Dim randomMove As New List(Of Integer)
        'AI is always player 2 and O
        AIMove.PlayerSymbol = "O"
        'For easy pick random available space
        If difficulty = GameDifficulty.Easy Then
            For i As Integer = 0 To 8
                If boardstate(i) = "Empty" Then
                    randomMove.Add(i)
                End If
            Next
            AIMove.SelectedTile = randomMove(New Random().Next(0, randomMove.Count - 1))
        End If
        'For hard pick tile based on priority logic
        If difficulty = GameDifficulty.Hard Then
            AIMove.SelectedTile = GetAIMove()
        End If
        SetMove(AIMove)
        Return AIMove
    End Function

    Private Function GetAIMove() As Integer
        Dim priority(8) As Integer
        Dim maxPri As Integer
        Dim maxList As New List(Of Integer)
        Dim i As Integer

        'set all tiles to 1
        For i = 0 To 8
            priority(i) = 1
        Next

        'set corners to 2
        priority(0) = 2
        priority(2) = 2
        priority(6) = 2
        priority(8) = 2

        'block forks
        If boardstate(0) = "X" Or boardstate(2) = "X" Or boardstate(6) = "X" Or boardstate(8) = "X" Then
            priority(1) = 5
            priority(7) = 5
            priority(3) = 5
            priority(5) = 5
        End If

        'set center tile to 5
        priority(4) = 6

        'set corner with two adjacent x to 7
        If boardstate(1) = "X" And boardstate(5) = "X" Then
            priority(0) = 7
        End If
        If boardstate(1) = "X" And boardstate(3) = "X" Then
            priority(2) = 7
        End If
        If boardstate(5) = "X" And boardstate(7) = "X" Then
            priority(6) = 7
        End If
        If boardstate(7) = "X" And boardstate(3) = "X" Then
            priority(8) = 7
        End If

        'set win condition spaces to 9, block win to 8
        'tile 0
        If boardstate(1) = boardstate(2) Then
            If boardstate(1) = "X" Then
                priority(0) = 8
            ElseIf boardstate(1) = "O" Then
                priority(0) = 9
            End If
        End If
        If boardstate(5) = boardstate(6) Then
            If boardstate(5) = "X" Then
                priority(0) = 8
            ElseIf boardstate(5) = "O" Then
                priority(0) = 9
            End If
        End If
        If boardstate(4) = boardstate(8) Then
            If boardstate(4) = "X" Then
                priority(0) = 8
            ElseIf boardstate(4) = "O" Then
                priority(0) = 9
            End If
        End If

        'tile1
        If boardstate(0) = boardstate(2) Then
            If boardstate(0) = "X" Then
                priority(1) = 8
            ElseIf boardstate(0) = "O" Then
                priority(1) = 9
            End If
        End If
        If boardstate(4) = boardstate(7) Then
            If boardstate(4) = "X" Then
                priority(1) = 8
            ElseIf boardstate(4) = "O" Then
                priority(1) = 9
            End If
        End If

        'tile2
        If boardstate(0) = boardstate(1) Then
            If boardstate(0) = "X" Then
                priority(2) = 8
            ElseIf boardstate(0) = "O" Then
                priority(2) = 9
            End If
        End If
        If boardstate(3) = boardstate(8) Then
            If boardstate(3) = "X" Then
                priority(2) = 8
            ElseIf boardstate(3) = "O" Then
                priority(2) = 9
            End If
        End If
        If boardstate(4) = boardstate(6) Then
            If boardstate(4) = "X" Then
                priority(2) = 8
            ElseIf boardstate(4) = "O" Then
                priority(2) = 9
            End If
        End If

        'tile3
        If boardstate(2) = boardstate(8) Then
            If boardstate(2) = "X" Then
                priority(3) = 8
            ElseIf boardstate(2) = "O" Then
                priority(3) = 9
            End If
        End If
        If boardstate(5) = boardstate(4) Then
            If boardstate(5) = "X" Then
                priority(3) = 8
            ElseIf boardstate(5) = "O" Then
                priority(3) = 9
            End If
        End If

        'tile4
        If boardstate(0) = boardstate(8) Then
            If boardstate(0) = "X" Then
                priority(4) = 8
            ElseIf boardstate(0) = "O" Then
                priority(4) = 9
            End If
        End If
        If boardstate(2) = boardstate(6) Then
            If boardstate(2) = "X" Then
                priority(4) = 8
            ElseIf boardstate(2) = "O" Then
                priority(4) = 9
            End If
        End If
        If boardstate(3) = boardstate(5) Then
            If boardstate(3) = "X" Then
                priority(4) = 8
            ElseIf boardstate(3) = "O" Then
                priority(4) = 9
            End If
        End If
        If boardstate(1) = boardstate(7) Then
            If boardstate(1) = "X" Then
                priority(4) = 8
            ElseIf boardstate(1) = "O" Then
                priority(4) = 9
            End If
        End If

        'tile5
        If boardstate(0) = boardstate(6) Then
            If boardstate(0) = "X" Then
                priority(5) = 8
            ElseIf boardstate(0) = "O" Then
                priority(5) = 9
            End If
        End If
        If boardstate(4) = boardstate(3) Then
            If boardstate(4) = "X" Then
                priority(5) = 8
            ElseIf boardstate(4) = "O" Then
                priority(5) = 9
            End If
        End If

        'tile6
        If boardstate(0) = boardstate(5) Then
            If boardstate(0) = "X" Then
                priority(6) = 8
            ElseIf boardstate(0) = "O" Then
                priority(6) = 9
            End If
        End If
        If boardstate(7) = boardstate(8) Then
            If boardstate(7) = "X" Then
                priority(6) = 8
            ElseIf boardstate(7) = "O" Then
                priority(6) = 9
            End If
        End If
        If boardstate(4) = boardstate(2) Then
            If boardstate(4) = "X" Then
                priority(6) = 8
            ElseIf boardstate(4) = "O" Then
                priority(6) = 9
            End If
        End If

        'tile7
        If boardstate(6) = boardstate(8) Then
            If boardstate(6) = "X" Then
                priority(7) = 8
            ElseIf boardstate(6) = "O" Then
                priority(7) = 9
            End If
        End If
        If boardstate(1) = boardstate(4) Then
            If boardstate(1) = "X" Then
                priority(7) = 8
            ElseIf boardstate(1) = "O" Then
                priority(7) = 9
            End If
        End If

        'tile8
        If boardstate(2) = boardstate(3) Then
            If boardstate(2) = "X" Then
                priority(8) = 8
            ElseIf boardstate(2) = "O" Then
                priority(8) = 9
            End If
        End If
        If boardstate(6) = boardstate(7) Then
            If boardstate(6) = "X" Then
                priority(8) = 8
            ElseIf boardstate(6) = "O" Then
                priority(8) = 9
            End If
        End If
        If boardstate(0) = boardstate(4) Then
            If boardstate(0) = "X" Then
                priority(8) = 8
            ElseIf boardstate(0) = "O" Then
                priority(8) = 9
            End If
        End If

        'set all occupied spaces to 0
        For i = 0 To 8
            If Not boardstate(i) = "Empty" Then
                priority(i) = 0
            End If
        Next

        'get index of max priority
        maxPri = 0
        For i = 0 To 8
            If priority(i) > maxPri Then
                maxList.Clear()
                maxList.Add(i)
                maxPri = priority(i)
            ElseIf priority(i) = maxPri Then
                maxList.Add(i)
            End If
        Next

        'get random
        Return maxList(New Random().Next(0, maxList.Count - 1))

    End Function

    Public Sub SetMove(ByVal move As GameMove)
        If Not boardstate(move.SelectedTile) = "Empty" Then
            MsgBox("ERROR: Tile already taken")
            Exit Sub
        End If

        boardstate(move.SelectedTile) = move.PlayerSymbol
        SendMoveToServer(move)
        DisableButtons()
        MoveInProgress = True
    End Sub

    Private Async Sub SendMoveToServer(ByVal currentMove As GameMove)
        Dim moveStr As String = "{""Source"":""GUI"", ""Type"":""Move"", ""Tile"":""" + currentMove.SelectedTile.ToString() + """, ""Symbol"":""" + currentMove.PlayerSymbol + """, ""MoveNumber"":""" + moveNum.ToString() + """}"
        Dim moveMsg As HttpContent = New StringContent(moveStr, Encoding.UTF8, "application/json")
        Dim parser As New JavaScriptSerializer()
        Dim resp As HttpResponseMessage
        Dim respStr As String = ""
        Dim serverMovenum As Integer
        Dim badconnection As Boolean = False
        'send the move to the server
        Try
            resp = Await client.PostAsync(server, moveMsg)
            respStr = Await resp.Content.ReadAsStringAsync()
        Catch ex As Exception
            badconnection = True
        End Try
        Try
            'Parse JSON message
            Dim jsonMsg = parser.DeserializeObject(respStr)
            serverMovenum = Convert.ToInt32(jsonMsg("MoveNumber"))
            If serverMovenum = moveNum Then
                Me.Invoke(Sub() picstatus.Text = "Server Recieved Move")
                Me.Invoke(Sub() picstatus.BackColor = Color.Green)
            Else
                Me.Invoke(Sub() picstatus.Text = "Bad move number received - " + jsonMsg("MoveNumber").ToString())
                Me.Invoke(Sub() picstatus.BackColor = Color.Red)
            End If
        Catch ex As Exception
            badconnection = True
        End Try
        If badconnection Then
            Try
                Me.Invoke(Sub() picstatus.Text = "No Server Connection")
                Me.Invoke(Sub() picstatus.BackColor = Color.Red)
            Catch ex As Exception
                'Do nothing
            End Try
        End If
        moveNum = moveNum + 1
    End Sub

    Private Sub DisableButtons()
        Dim Tile As Button
        Dim controlString As String
        For i As Integer = 0 To 8
            controlString = "tile" + i.ToString()
            Tile = Me.Controls.Find(controlString, True).FirstOrDefault()
            Me.Invoke(Sub() Tile.Enabled = False)
        Next
    End Sub

    Private Sub EnableButtons()
        Dim Tile As Button
        Dim controlString As String
        For i As Integer = 0 To 8
            controlString = "tile" + i.ToString()
            Tile = Me.Controls.Find(controlString, True).FirstOrDefault()
            If Tile.Text = "" Then
                Me.Invoke(Sub() Tile.Enabled = True)
            End If
        Next
    End Sub

    Private Sub resetButton_Click(sender As Object, e As EventArgs) Handles resetButton.Click
        currentPlayer = "X"
        For i As Integer = 0 To 8
            boardstate(i) = "Empty"
        Next

        ResetTiles()
        MoveInProgress = False
        beamerBox.Visible = False
        addImage = False
        status.Text = "Waiting for player: " + currentPlayer

    End Sub

    Private Sub closing_handler(sender As Object, e As EventArgs) Handles Me.FormClosing
        threadRunning = False
        SetupForm.Show()
    End Sub

    Private Sub tile0_Click(sender As Object, e As EventArgs) Handles tile0.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 0})
        tile0.Enabled = False
        tile0.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile1_Click(sender As Object, e As EventArgs) Handles tile1.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 1})
        tile1.Enabled = False
        tile1.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile2_Click(sender As Object, e As EventArgs) Handles tile2.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 2})
        tile2.Enabled = False
        tile2.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile3_Click(sender As Object, e As EventArgs) Handles tile3.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 3})
        tile3.Enabled = False
        tile3.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile4_Click(sender As Object, e As EventArgs) Handles tile4.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 4})
        tile4.Enabled = False
        tile4.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile5_Click(sender As Object, e As EventArgs) Handles tile5.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 5})
        tile5.Enabled = False
        tile5.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile6_Click(sender As Object, e As EventArgs) Handles tile6.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 6})
        tile6.Enabled = False
        tile6.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile7_Click(sender As Object, e As EventArgs) Handles tile7.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 7})
        tile7.Enabled = False
        tile7.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile8_Click(sender As Object, e As EventArgs) Handles tile8.Click
        'send the selected player move
        SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 8})
        tile8.Enabled = False
        tile8.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

End Class