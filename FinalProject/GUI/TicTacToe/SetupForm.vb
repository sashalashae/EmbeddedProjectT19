Public Class SetupForm
    Private m_game As Game
    Private Sub SetupForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        numPlayers.Items.Add("1")
        numPlayers.Items.Add("2")
        difficulty.Items.Add("Easy")
        difficulty.Items.Add("Hard")
        difficulty.SelectedIndex = 0
        numPlayers.SelectedIndex = 0
    End Sub

    Private Sub startButton_Click(sender As Object, e As EventArgs) Handles startButton.Click
        m_game = New Game()
        If difficulty.SelectedItem = "Easy" Then
            m_game.Difficulty = GameDifficulty.Easy
        Else
            m_game.Difficulty = GameDifficulty.Hard
        End If
        If numPlayers.SelectedItem = "1" Then
            m_game.NumPlayers = 1
        Else
            m_game.NumPlayers = 2
        End If
        Dim gameForm As New GameplayForm(m_game)
        Me.Hide()
        gameForm.Show()
    End Sub
End Class
