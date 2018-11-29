Public Class SetupForm
    Private diff As GameplayForm.GameDifficulty
    Private m_numPlayers As Integer

    Private Sub SetupForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        numPlayers.Items.Add("1")
        numPlayers.Items.Add("2")
        difficulty.Items.Add("Easy")
        difficulty.Items.Add("Hard")
        difficulty.SelectedIndex = 0
        numPlayers.SelectedIndex = 1

        compDifficulty.Visible = False
        difficulty.Visible = False
    End Sub

    Private Sub showDiff(sender As Object, e As EventArgs) Handles numPlayers.SelectedIndexChanged
        If numPlayers.SelectedIndex = 1 Then
            compDifficulty.Visible = False
            difficulty.Visible = False
        Else
            compDifficulty.Visible = True
            difficulty.Visible = True
        End If
    End Sub

    Private Sub startButton_Click(sender As Object, e As EventArgs) Handles startButton.Click
        If difficulty.SelectedItem = "Easy" Then
            diff = GameplayForm.GameDifficulty.Easy
        Else
            diff = GameplayForm.GameDifficulty.Hard
        End If
        If numPlayers.SelectedItem = "1" Then
            m_numPlayers = 1
        Else
            m_numPlayers = 2
        End If
        Dim gameForm As New GameplayForm(m_numPlayers, diff)
        Me.Hide()
        gameForm.Show()
    End Sub

    Private Sub credits_Click(sender As Object, e As EventArgs) Handles credits.Click
        Dim creditform As New Credits
        Me.Hide()
        creditform.Show()
    End Sub

End Class
