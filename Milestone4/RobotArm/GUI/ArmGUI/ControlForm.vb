Imports System.Net.Http
Imports System.Text

Public Class ControlForm

    Private commandNum As Integer
    Private command As String

    'HTTP data structures
    Private client As HttpClient
    Private serverURI As UriBuilder
    Private server As String

    Private Sub drawX_Click(sender As Object, e As EventArgs) Handles drawX.Click
        commandNum = commandNum + 1
        commandLabel.Text = commandNum.ToString()
        command = "drawX"
        SendMove()
    End Sub

    Private Sub drawO_Click(sender As Object, e As EventArgs) Handles drawO.Click
        commandNum = commandNum + 1
        commandLabel.Text = commandNum.ToString()
        command = "drawO"
        SendMove()
    End Sub

    Private Sub checkConnection_Click(sender As Object, e As EventArgs) Handles checkConnection.Click
        commandNum = commandNum + 1
        commandLabel.Text = commandNum.ToString()
        CheckServerConnection()
    End Sub

    Private Async Sub SendMove()
        Dim responseString As String = ""
        Dim response As HttpResponseMessage
        Dim content As HttpContent = New StringContent(command, Encoding.UTF8, "application/json")
        Try
            response = Await client.PostAsync(server, content)
            responseString = Await response.Content.ReadAsStringAsync()
        Catch ex As Exception
            MsgBox("ERROR: Connection Failed")
        End Try
        Try
            If Convert.ToInt32(responseString) = commandNum Then
                MsgBox("Command Received Successfully")
            Else
                Throw New Exception
            End If
        Catch ex As Exception
            MsgBox("ERROR: Command Missed - Expected: " + commandNum.ToString() + " Received: " + responseString)
        End Try

    End Sub

    Private Async Sub CheckServerConnection()
        Dim responseString As String
        Dim response As HttpResponseMessage
        Dim content As HttpContent = New StringContent("checkConnection", Encoding.UTF8, "application/json")
        response = Await client.PostAsync(server, content)
        responseString = Await response.Content.ReadAsStringAsync()
        MsgBox("Server Response: " + responseString)
    End Sub

    Private Async Sub ResetCommandNum()
        Dim responseString As String = ""
        Dim response As HttpResponseMessage
        Dim content As HttpContent = New StringContent("resetNumber", Encoding.UTF8, "application/json")
        Try
            response = Await client.PostAsync(server, content)
            responseString = Await response.Content.ReadAsStringAsync()
        Catch ex As Exception
            MsgBox("ERROR: Connection Failed")
        End Try
        Try
            If Convert.ToInt32(responseString) = commandNum Then
                MsgBox("Command Number Reset Successfully")
            Else
                Throw New Exception
            End If
        Catch ex As Exception
            MsgBox("ERROR: Command Number not reset - " + responseString)
        End Try

    End Sub

    Private Async Sub GetPicStatus()
        Dim responseString As String = ""
        Dim response As HttpResponseMessage
        Dim content As HttpContent = New StringContent("getpicbusy", Encoding.UTF8, "application/json")
        Try
            response = Await client.PostAsync(server, content)
            responseString = Await response.Content.ReadAsStringAsync()
        Catch ex As Exception
            MsgBox("ERROR: Connection Failed")
        End Try
        MsgBox("PIC Busy: " + responseString)
    End Sub

    Private Sub ControlForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'init command number to 1
        commandNum = 0
        commandLabel.Text = commandNum.ToString()

        'configure connection
        client = New HttpClient()
        serverURI = New UriBuilder()
        serverURI.Host = "192.168.1.100"
        serverURI.Port = "2000"
        server = serverURI.ToString()
    End Sub

    Private Sub reset_Click(sender As Object, e As EventArgs) Handles reset.Click
        commandNum = 0
        commandLabel.Text = commandNum.ToString()
        ResetCommandNum()
    End Sub

    Private Sub getStatus_Click(sender As Object, e As EventArgs) Handles getStatus.Click
        commandNum = commandNum + 1
        commandLabel.Text = commandNum.ToString()
        GetPicStatus()
    End Sub
End Class
