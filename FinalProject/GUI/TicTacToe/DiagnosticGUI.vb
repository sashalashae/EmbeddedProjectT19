Imports System.Net.Http
Imports System.Text
Imports System.Threading
Imports System.Web.Script.Serialization

Public Class DiagnosticGUI

    'HTTP data structures
    Private client As HttpClient
    Private serverURI As UriBuilder
    Private server As String

    Sub New()

        ' This call is required by the designer.
        InitializeComponent()

        ' Add any initialization after the InitializeComponent() call.

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

    Private Async Sub GetServerInfo()
        Dim respStr As String = ""
        Dim resp As HttpResponseMessage
        Dim FSRdata As UInt16
        Dim fsrStr As String
        Dim currentLabel As Label
        Dim parser As New JavaScriptSerializer()
        Dim contentStr As String = "{""Source"":""GUI"", ""Type"":""Status""}"
        Dim content As HttpContent = New StringContent(contentStr, Encoding.UTF8, "application/json")
        Try
            resp = Await client.PostAsync(server, content)
            respStr = Await resp.Content.ReadAsStringAsync()
            Me.Invoke(Sub() serverStatus.Text = "Server Connected!")
            Me.Invoke(Sub() serverStatus.BackColor = Color.Green)
        Catch ex As Exception
            Me.Invoke(Sub() serverStatus.Text = "No Server Connection")
            Me.Invoke(Sub() serverStatus.BackColor = Color.Red)
        End Try
        Try
            'Parse JSON message
            Dim jsonMsg = parser.DeserializeObject(respStr)
            FSRdata = Convert.ToUInt16(jsonMsg("FSR"))
        Catch ex As Exception
            Me.Invoke(Sub() serverStatus.Text = "Bad JSON received")
            Me.Invoke(Sub() serverStatus.BackColor = Color.Red)
        End Try
        For i As Integer = 0 To 9
            currentLabel = Me.Controls.Find("sensor" + i.ToString(), True).FirstOrDefault()
            If ((FSRdata >> i) And 1) = 1 Then
                Me.Invoke(Sub() currentLabel.BackColor = Color.Red)
            Else
                Me.Invoke(Sub() currentLabel.BackColor = Color.Black)
            End If
        Next
    End Sub

    Private Sub statusPoll()
        While True
            GetServerInfo()
            System.Threading.Thread.Sleep(250)
        End While
    End Sub

End Class
