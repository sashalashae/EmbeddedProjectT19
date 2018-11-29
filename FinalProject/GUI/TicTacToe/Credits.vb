Public Class Credits
    Private Sub closing_handler(sender As Object, e As EventArgs) Handles Me.FormClosing
        SetupForm.Show()
    End Sub
End Class