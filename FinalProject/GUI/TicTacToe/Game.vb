Imports System.Net.Http
Imports System.Text

Public Structure GameMove
    Public PlayerSymbol As String
    Public SelectedTile As Integer
End Structure

Public Enum GameDifficulty
    Easy
    Hard
End Enum

Public Class Game

    Private m_difficulty As GameDifficulty
    Private m_numPlayers As Integer
    Private m_boardstate(8) As String
    Private m_moveNum As Integer
    Private m_moveDone As Boolean

    'HTTP data structures
    Private client As HttpClient

    Private serverURI As UriBuilder
    Private server As String

    Sub New()
        'set initial board values
        For i As Integer = 0 To 8
            m_boardstate(i) = "Empty"
        Next
        'single player mode
        m_numPlayers = 1
        'hard difficulty
        m_difficulty = GameDifficulty.Hard
        'set initial move number to 0
        m_moveNum = 0
        'set move done to false
        m_moveDone = False
        'set http connection
        client = New HttpClient()
        serverURI = New UriBuilder()
        serverURI.Host = "192.168.1.100"
        serverURI.Port = "2000"
        server = serverURI.ToString()
    End Sub

    Public Sub ResetBoard()
        'clear board values
        For i As Integer = 0 To 8
            m_boardstate(i) = "Empty"
        Next
    End Sub

    Public Function PerformAIMove() As GameMove
        Dim AIMove As GameMove
        'AI is always player 2 and O
        AIMove.PlayerSymbol = "O"
        'For easy pick random available space
        If m_difficulty = GameDifficulty.Easy Then
            For i As Integer = 0 To 8
                If m_boardstate(i) = "Empty" Then
                    AIMove.SelectedTile = i
                    Exit For
                End If
            Next
        End If
        'For hard pick tile based on priority logic
        If m_difficulty = GameDifficulty.Hard Then
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
        If m_boardstate(0) = "O" And m_boardstate(1) = "O" Then
            priority(2) = 9
        End If
        If m_boardstate(5) = "O" And m_boardstate(8) = "O" Then
            priority(2) = 9
        End If

        'set all occupied spaces to 0
        For i = 0 To 8
            If Not m_boardstate(i) = "Empty" Then
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

    Public Function SetMove(ByVal move As GameMove) As Boolean
        If Not m_boardstate(move.SelectedTile) = "Empty" Then
            MsgBox("ERROR: Tile already taken")
            Return False
        End If
        m_boardstate(move.SelectedTile) = move.PlayerSymbol
        'send move to the server
        SendMoveToServer(move)
        m_moveDone = False
        While m_moveDone = False

        End While
        m_moveNum = m_moveNum + 1
        Return True
    End Function

    Private Async Sub SendMoveToServer(ByVal currentMove As GameMove)
        Dim roverDone As String = "{""Source"":""GUI"", ""Type"":""RoverStatus""}"
        Dim moveString As String = "{""Source"":""GUI"", ""Type"":""Move"", ""Tile"":""" + currentMove.SelectedTile.ToString() + """, ""Symbol"":""" + currentMove.PlayerSymbol + """, ""MoveNumber"":""" + m_moveNum.ToString() + """}"
        Dim response As HttpResponseMessage
        Dim responseString As String
        Dim validMessage As Boolean = False
        Dim moveDone As Boolean = False
        Dim content As HttpContent = New StringContent(moveString, Encoding.UTF8, "application/json")
        Dim movetimer As New Stopwatch()
        movetimer.Start()
        'send message to the server and make sure it sends correct response
        While Not validMessage
            Try
                response = Await client.PostAsync(server, content)
                responseString = Await response.Content.ReadAsStringAsync()
                If Convert.ToInt32(responseString) = m_moveNum Then
                    validMessage = True
                Else
                    MsgBox("Invalid Server Response " + responseString + " received, retrying")
                End If
            Catch ex As Exception
                MsgBox("Server connection failed, retrying")
            End Try
        End While
        MsgBox("Move sent to server successfully")
        'wait for rover to finish move (poll once per second)
        content = New StringContent(roverDone, Encoding.UTF8, "application/json")
        While Not moveDone
            Try
                response = Await client.PostAsync(server, content)
                responseString = Await response.Content.ReadAsStringAsync()
                If responseString = "Done" Then
                    moveDone = True
                End If
            Catch ex As Exception
                MsgBox("Server connection failed, retrying")
            End Try
            System.Threading.Thread.Sleep(1000)
        End While
        movetimer.Stop()
        MsgBox("Rover move complete, " + (movetimer.ElapsedMilliseconds() / 1000).ToString() + "s elapsed")
        m_moveDone = True
    End Sub

    Public Property Difficulty As GameDifficulty
        Get
            Return m_difficulty
        End Get
        Set(value As GameDifficulty)
            m_difficulty = value
        End Set
    End Property

    Public Property NumPlayers As Integer
        Get
            Return m_numPlayers
        End Get
        Set(value As Integer)
            If value > 2 Or value < 1 Then
                MsgBox("ERROR: Invalid Number of players, defaulting to 1")
                m_numPlayers = 1
            Else
                m_numPlayers = value
            End If
        End Set
    End Property

End Class

