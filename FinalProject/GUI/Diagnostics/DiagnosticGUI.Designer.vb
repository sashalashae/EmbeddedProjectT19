<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class DiagnosticGUI
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.serverStatus = New System.Windows.Forms.Label()
        Me.sensor5 = New System.Windows.Forms.Label()
        Me.sensor6 = New System.Windows.Forms.Label()
        Me.sensor7 = New System.Windows.Forms.Label()
        Me.sensor8 = New System.Windows.Forms.Label()
        Me.sensor9 = New System.Windows.Forms.Label()
        Me.sensor4 = New System.Windows.Forms.Label()
        Me.sensor0 = New System.Windows.Forms.Label()
        Me.sensor1 = New System.Windows.Forms.Label()
        Me.sensor2 = New System.Windows.Forms.Label()
        Me.sensor3 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 9)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(74, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Server Status:"
        '
        'serverStatus
        '
        Me.serverStatus.BackColor = System.Drawing.SystemColors.ControlLightLight
        Me.serverStatus.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.serverStatus.Location = New System.Drawing.Point(92, 9)
        Me.serverStatus.Name = "serverStatus"
        Me.serverStatus.Size = New System.Drawing.Size(150, 16)
        Me.serverStatus.TabIndex = 1
        Me.serverStatus.Text = "Label2"
        '
        'sensor5
        '
        Me.sensor5.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor5.Location = New System.Drawing.Point(12, 37)
        Me.sensor5.Name = "sensor5"
        Me.sensor5.Size = New System.Drawing.Size(300, 3)
        Me.sensor5.TabIndex = 2
        Me.sensor5.Text = "Label2"
        '
        'sensor6
        '
        Me.sensor6.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor6.Location = New System.Drawing.Point(12, 56)
        Me.sensor6.Name = "sensor6"
        Me.sensor6.Size = New System.Drawing.Size(300, 3)
        Me.sensor6.TabIndex = 3
        Me.sensor6.Text = "Label2"
        '
        'sensor7
        '
        Me.sensor7.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor7.Location = New System.Drawing.Point(12, 186)
        Me.sensor7.Name = "sensor7"
        Me.sensor7.Size = New System.Drawing.Size(300, 3)
        Me.sensor7.TabIndex = 4
        Me.sensor7.Text = "Label2"
        '
        'sensor8
        '
        Me.sensor8.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor8.Location = New System.Drawing.Point(12, 317)
        Me.sensor8.Name = "sensor8"
        Me.sensor8.Size = New System.Drawing.Size(300, 3)
        Me.sensor8.TabIndex = 5
        Me.sensor8.Text = "Label2"
        '
        'sensor9
        '
        Me.sensor9.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor9.Location = New System.Drawing.Point(12, 334)
        Me.sensor9.Name = "sensor9"
        Me.sensor9.Size = New System.Drawing.Size(300, 3)
        Me.sensor9.TabIndex = 6
        Me.sensor9.Text = "Label2"
        '
        'sensor4
        '
        Me.sensor4.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor4.Location = New System.Drawing.Point(309, 37)
        Me.sensor4.Name = "sensor4"
        Me.sensor4.Size = New System.Drawing.Size(3, 300)
        Me.sensor4.TabIndex = 7
        Me.sensor4.Text = "Label2"
        '
        'sensor0
        '
        Me.sensor0.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor0.Location = New System.Drawing.Point(12, 37)
        Me.sensor0.Name = "sensor0"
        Me.sensor0.Size = New System.Drawing.Size(3, 300)
        Me.sensor0.TabIndex = 8
        Me.sensor0.Text = "Label2"
        '
        'sensor1
        '
        Me.sensor1.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor1.Location = New System.Drawing.Point(30, 37)
        Me.sensor1.Name = "sensor1"
        Me.sensor1.Size = New System.Drawing.Size(3, 300)
        Me.sensor1.TabIndex = 9
        Me.sensor1.Text = "Label2"
        '
        'sensor2
        '
        Me.sensor2.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor2.Location = New System.Drawing.Point(153, 37)
        Me.sensor2.Name = "sensor2"
        Me.sensor2.Size = New System.Drawing.Size(3, 300)
        Me.sensor2.TabIndex = 10
        Me.sensor2.Text = "Label2"
        '
        'sensor3
        '
        Me.sensor3.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.sensor3.Location = New System.Drawing.Point(290, 37)
        Me.sensor3.Name = "sensor3"
        Me.sensor3.Size = New System.Drawing.Size(3, 300)
        Me.sensor3.TabIndex = 11
        Me.sensor3.Text = "Label2"
        '
        'DiagnosticGUI
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(565, 354)
        Me.Controls.Add(Me.sensor3)
        Me.Controls.Add(Me.sensor2)
        Me.Controls.Add(Me.sensor1)
        Me.Controls.Add(Me.sensor0)
        Me.Controls.Add(Me.sensor4)
        Me.Controls.Add(Me.sensor9)
        Me.Controls.Add(Me.sensor8)
        Me.Controls.Add(Me.sensor7)
        Me.Controls.Add(Me.sensor6)
        Me.Controls.Add(Me.sensor5)
        Me.Controls.Add(Me.serverStatus)
        Me.Controls.Add(Me.Label1)
        Me.Name = "DiagnosticGUI"
        Me.Text = "Diagnostics"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents serverStatus As Label
    Friend WithEvents sensor5 As Label
    Friend WithEvents sensor6 As Label
    Friend WithEvents sensor7 As Label
    Friend WithEvents sensor8 As Label
    Friend WithEvents sensor9 As Label
    Friend WithEvents sensor4 As Label
    Friend WithEvents sensor0 As Label
    Friend WithEvents sensor1 As Label
    Friend WithEvents sensor2 As Label
    Friend WithEvents sensor3 As Label
End Class
