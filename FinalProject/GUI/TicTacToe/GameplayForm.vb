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
    Private moveDone As Boolean
    Private difficulty As GameDifficulty
    Private threadRunning As Boolean

    Public Sub New(ByVal numPlay As Integer, ByVal diff As GameDifficulty)

        ' This call is required by the designer.
        InitializeComponent()

        'set current player to X (starting)
        currentPlayer = "X"

        'set number of players and difficulty
        numPlayers = numPlay
        difficulty = diff

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

    End Sub

    'thread function for polling server
    Private Sub statusPoll()
        While threadRunning
            GetServerInfo()
            System.Threading.Thread.Sleep(500)
        End While
    End Sub

    Private Async Sub GetServerInfo()
        moveDone = True
        Dim statusStr As String = "{""Source"":""GUI"", ""Type"":""Status""}"
        Dim statusMsg As HttpContent = New StringContent(statusStr, Encoding.UTF8, "application/json")
        Dim parser As New JavaScriptSerializer()
        Dim resp As HttpResponseMessage
        Dim respStr As String = ""
        Dim FSRdata As UInt16
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
            If Convert.ToInt32(jsonMsg("Ackno")) > ackCounter Then
                ackCounter = Convert.ToInt32(jsonMsg("Ackno"))
                moveDone = True
            End If
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

    Public Sub NextMove()
        Dim AIMove As GameMove
        Dim AITile As Button

        'check for three in a row
        If ThreeInRow() = True Then
            DisableButtons()
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
            AITile.Text = AIMove.PlayerSymbol
            AITile.Enabled = False
            currentPlayer = "X"
            'check for three in a row
            If ThreeInRow() = True Then
                DisableButtons()
                Exit Sub
            End If
        Else
            status.Text = "Waiting for player: " + currentPlayer
        End If

        If moveNum = 8 Then
            status.Text = "Game Over!"
        End If

    End Sub

    Private Function ThreeInRow() As Boolean
        Dim found As Boolean = False
        If boardstate(0) = boardstate(1) And boardstate(1) = boardstate(2) And boardstate(0) <> "Empty" Then
            found = True
            tile0.BackColor = Color.LightGreen
            tile1.BackColor = Color.LightGreen
            tile2.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(0) + " wins!"
        ElseIf boardstate(3) = boardstate(4) And boardstate(4) = boardstate(5) And boardstate(5) <> "Empty" Then
            found = True
            tile3.BackColor = Color.LightGreen
            tile4.BackColor = Color.LightGreen
            tile5.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(5) + " wins!"
        ElseIf boardstate(6) = boardstate(7) And boardstate(7) = boardstate(8) And boardstate(8) <> "Empty" Then
            found = True
            tile6.BackColor = Color.LightGreen
            tile7.BackColor = Color.LightGreen
            tile8.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(8) + " wins!"
        ElseIf boardstate(0) = boardstate(4) And boardstate(4) = boardstate(8) And boardstate(0) <> "Empty" Then
            found = True
            tile0.BackColor = Color.LightGreen
            tile4.BackColor = Color.LightGreen
            tile8.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(0) + " wins!"
        ElseIf boardstate(2) = boardstate(4) And boardstate(4) = boardstate(6) And boardstate(2) <> "Empty" Then
            found = True
            tile2.BackColor = Color.LightGreen
            tile4.BackColor = Color.LightGreen
            tile6.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(2) + " wins!"
        ElseIf boardstate(0) = boardstate(3) And boardstate(3) = boardstate(6) And boardstate(0) <> "Empty" Then
            found = True
            tile0.BackColor = Color.LightGreen
            tile3.BackColor = Color.LightGreen
            tile6.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(0) + " wins!"
        ElseIf boardstate(1) = boardstate(4) And boardstate(4) = boardstate(7) And boardstate(1) <> "Empty" Then
            found = True
            tile1.BackColor = Color.LightGreen
            tile4.BackColor = Color.LightGreen
            tile7.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(1) + " wins!"
        ElseIf boardstate(2) = boardstate(5) And boardstate(5) = boardstate(8) And boardstate(5) <> "Empty" Then
            found = True
            tile2.BackColor = Color.LightGreen
            tile8.BackColor = Color.LightGreen
            tile5.BackColor = Color.LightGreen
            status.Text = "Player " + boardstate(5) + " wins!"
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
        Next
    End Sub

    Public Function PerformAIMove() As GameMove
        Dim AIMove As GameMove
        'AI is always player 2 and O
        AIMove.PlayerSymbol = "O"
        'For easy pick random available space
        If difficulty = GameDifficulty.Easy Then
            For i As Integer = 0 To 8
                If boardstate(i) = "Empty" Then
                    AIMove.SelectedTile = i
                    Exit For
                End If
            Next
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
        Dim maxPri, maxInd As Integer
        Dim i As Integer

        'set tiles with potential to win as 6

        'set center tile to 7

        'set block win condition spaces to 8

        'set win condition spaces to 9
        If boardstate(0) = "O" And boardstate(1) = "O" Then
            priority(2) = 9
        End If
        If boardstate(5) = "O" And boardstate(8) = "O" Then
            priority(2) = 9
        End If

        'set all occupied spaces to 0
        For i = 0 To 8
            If Not boardstate(i) = "Empty" Then
                priority(i) = 0
            End If
        Next

        'get index of max priority
        maxInd = 0
        maxPri = 0
        For i = 0 To 8
            If priority(i) > maxPri Then
                maxPri = priority(i)
                maxInd = i
            End If
        Next
        Return maxInd

    End Function

    Public Sub SetMove(ByVal move As GameMove)
        If Not boardstate(move.SelectedTile) = "Empty" Then
            MsgBox("ERROR: Tile already taken")
            Exit Sub
        End If

        boardstate(move.SelectedTile) = move.PlayerSymbol
        SendMoveToServer(move)
        DisableButtons()
        moveDone = False
        While Not moveDone
            System.Threading.Thread.Sleep(100)
        End While
        EnableButtons()
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
            Tile.Enabled = False
        Next
    End Sub

    Private Sub EnableButtons()
        Dim Tile As Button
        Dim controlString As String
        For i As Integer = 0 To 8
            controlString = "tile" + i.ToString()
            Tile = Me.Controls.Find(controlString, True).FirstOrDefault()
            If Tile.Text = "" Then
                Tile.Enabled = True
            End If
        Next
    End Sub

    Private Sub resetButton_Click(sender As Object, e As EventArgs) Handles resetButton.Click
        threadRunning = False
        SetupForm.Show()
        Me.Close()
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