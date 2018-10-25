Public Class GameplayForm

    Private m_game As Game
    Private currentPlayer As String

    Public Sub New(ByRef newGame As Game)

        ' This call is required by the designer.
        InitializeComponent()

        ' Add any initialization after the InitializeComponent() call.
        m_game = newGame

        'set current player to X (starting)
        currentPlayer = "X"

        'reset all tiles
        ResetTiles()

        status.Text = "Waiting for player: " + currentPlayer

    End Sub

    Public Sub NextMove()
        Dim AIMove As GameMove
        Dim AITile As Button
        'switch current player
        If currentPlayer = "X" Then
            currentPlayer = "O"
        Else
            currentPlayer = "X"
        End If

        'check for AI move
        If m_game.NumPlayers = 1 And currentPlayer = "O" Then
            AIMove = m_game.PerformAIMove()
            AITile = Me.Controls.Find("tile" + AIMove.SelectedTile.ToString(), True).FirstOrDefault()
            AITile.Text = AIMove.PlayerSymbol
            AITile.Enabled = False
        Else
            status.Text = "Waiting for player: " + currentPlayer
        End If
    End Sub

    Private Sub ResetTiles()
        'Set all tiles to empty and enable all
        Dim myControlToFind As Button
        Dim controlString As String
        For i As Integer = 0 To 8
            controlString = "tile" + i.ToString()
            myControlToFind = Me.Controls.Find(controlString, True).FirstOrDefault()
            myControlToFind.Text = ""
            myControlToFind.Enabled = True
            myControlToFind.Font = New Font("Comic Sans MS", 36, FontStyle.Bold)
        Next
    End Sub

    Private Sub resetButton_Click(sender As Object, e As EventArgs) Handles resetButton.Click
        SetupForm.Show()
        Me.Close()
    End Sub

    Private Sub tile0_Click(sender As Object, e As EventArgs) Handles tile0.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 0})
        tile0.Enabled = False
        tile0.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile1_Click(sender As Object, e As EventArgs) Handles tile1.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 1})
        tile1.Enabled = False
        tile1.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile2_Click(sender As Object, e As EventArgs) Handles tile2.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 2})
        tile2.Enabled = False
        tile2.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile3_Click(sender As Object, e As EventArgs) Handles tile3.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 3})
        tile3.Enabled = False
        tile3.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile4_Click(sender As Object, e As EventArgs) Handles tile4.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 4})
        tile4.Enabled = False
        tile4.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile5_Click(sender As Object, e As EventArgs) Handles tile5.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 5})
        tile5.Enabled = False
        tile5.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile6_Click(sender As Object, e As EventArgs) Handles tile6.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 6})
        tile6.Enabled = False
        tile6.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile7_Click(sender As Object, e As EventArgs) Handles tile7.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 7})
        tile7.Enabled = False
        tile7.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub

    Private Sub tile8_Click(sender As Object, e As EventArgs) Handles tile8.Click
        'send the selected player move
        m_game.SetMove(New GameMove With {.PlayerSymbol = currentPlayer, .SelectedTile = 8})
        tile8.Enabled = False
        tile8.Text = currentPlayer
        'Move to next move
        NextMove()
    End Sub
End Class