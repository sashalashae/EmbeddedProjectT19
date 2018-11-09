Imports System.Net.Http
Imports System.Text
Imports System.Threading

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
            If Not Convert.ToInt32(responseString) = commandNum Then
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
        Try
            response = Await client.PostAsync(server, content)
            responseString = Await response.Content.ReadAsStringAsync()
            MsgBox("Server Response: " + responseString)
        Catch ex As Exception
            MsgBox("ERROR: Server Not Connected")
        End Try
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
            Me.Invoke(Sub() picStatus.Text = "ERROR: No server Connection")
            Me.Invoke(Sub() picStatus.BackColor = Color.Red)
        End Try
        If responseString = "True" Then
            Me.Invoke(Sub() picStatus.Text = "PIC Busy")
            Me.Invoke(Sub() picStatus.BackColor = Color.Yellow)
        ElseIf responseString = "False" Then
            Me.Invoke(Sub() picStatus.Text = "PIC Idle")
            Me.Invoke(Sub() picStatus.BackColor = Color.Green)
        Else
            Me.Invoke(Sub() picStatus.Text = "ERROR: Unknown Message")
            Me.Invoke(Sub() picStatus.BackColor = Color.Red)
        End If
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

        'spin up thread for polling status
        Dim pollThread As Thread = New Thread(AddressOf statusPoll)
        pollThread.Start()

    End Sub

    Private Sub statusPoll()
        While True
            GetPicStatus()
            commandNum = commandNum + 1
            System.Threading.Thread.Sleep(1000)
        End While
    End Sub

    Private Sub reset_Click(sender As Object, e As EventArgs) Handles reset.Click
        commandNum = 0
        commandLabel.Text = commandNum.ToString()
        ResetCommandNum()
    End Sub

End Class
