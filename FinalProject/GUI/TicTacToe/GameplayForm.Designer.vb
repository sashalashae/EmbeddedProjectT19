<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class GameplayForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
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
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.tile0 = New System.Windows.Forms.Button()
        Me.tile8 = New System.Windows.Forms.Button()
        Me.tile7 = New System.Windows.Forms.Button()
        Me.tile6 = New System.Windows.Forms.Button()
        Me.tile5 = New System.Windows.Forms.Button()
        Me.tile3 = New System.Windows.Forms.Button()
        Me.tile4 = New System.Windows.Forms.Button()
        Me.tile2 = New System.Windows.Forms.Button()
        Me.tile1 = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.status = New System.Windows.Forms.Label()
        Me.resetButton = New System.Windows.Forms.Button()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.picstatus = New System.Windows.Forms.Label()
        Me.sensor5 = New System.Windows.Forms.Label()
        Me.sensor6 = New System.Windows.Forms.Label()
        Me.sensor8 = New System.Windows.Forms.Label()
        Me.sensor9 = New System.Windows.Forms.Label()
        Me.sensor7 = New System.Windows.Forms.Label()
        Me.sensor0 = New System.Windows.Forms.Label()
        Me.sensor1 = New System.Windows.Forms.Label()
        Me.sensor4 = New System.Windows.Forms.Label()
        Me.sensor3 = New System.Windows.Forms.Label()
        Me.sensor2 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'tile0
        '
        Me.tile0.Location = New System.Drawing.Point(16, 12)
        Me.tile0.Name = "tile0"
        Me.tile0.Size = New System.Drawing.Size(75, 75)
        Me.tile0.TabIndex = 0
        Me.tile0.TabStop = False
        Me.tile0.Text = "Button1"
        Me.tile0.UseVisualStyleBackColor = True
        '
        'tile8
        '
        Me.tile8.Location = New System.Drawing.Point(178, 174)
        Me.tile8.Name = "tile8"
        Me.tile8.Size = New System.Drawing.Size(75, 75)
        Me.tile8.TabIndex = 2
        Me.tile8.TabStop = False
        Me.tile8.Text = "Button3"
        Me.tile8.UseVisualStyleBackColor = True
        '
        'tile7
        '
        Me.tile7.Location = New System.Drawing.Point(97, 174)
        Me.tile7.Name = "tile7"
        Me.tile7.Size = New System.Drawing.Size(75, 75)
        Me.tile7.TabIndex = 3
        Me.tile7.TabStop = False
        Me.tile7.Text = "Button4"
        Me.tile7.UseVisualStyleBackColor = True
        '
        'tile6
        '
        Me.tile6.Location = New System.Drawing.Point(16, 174)
        Me.tile6.Name = "tile6"
        Me.tile6.Size = New System.Drawing.Size(75, 75)
        Me.tile6.TabIndex = 4
        Me.tile6.TabStop = False
        Me.tile6.Text = "Button5"
        Me.tile6.UseVisualStyleBackColor = True
        '
        'tile5
        '
        Me.tile5.Location = New System.Drawing.Point(178, 93)
        Me.tile5.Name = "tile5"
        Me.tile5.Size = New System.Drawing.Size(75, 75)
        Me.tile5.TabIndex = 5
        Me.tile5.TabStop = False
        Me.tile5.Text = "Button6"
        Me.tile5.UseVisualStyleBackColor = True
        '
        'tile3
        '
        Me.tile3.Location = New System.Drawing.Point(16, 93)
        Me.tile3.Name = "tile3"
        Me.tile3.Size = New System.Drawing.Size(75, 75)
        Me.tile3.TabIndex = 6
        Me.tile3.TabStop = False
        Me.tile3.Text = "Button7"
        Me.tile3.UseVisualStyleBackColor = True
        '
        'tile4
        '
        Me.tile4.Location = New System.Drawing.Point(97, 93)
        Me.tile4.Name = "tile4"
        Me.tile4.Size = New System.Drawing.Size(75, 75)
        Me.tile4.TabIndex = 7
        Me.tile4.TabStop = False
        Me.tile4.Text = "Button8"
        Me.tile4.UseVisualStyleBackColor = True
        '
        'tile2
        '
        Me.tile2.Location = New System.Drawing.Point(178, 12)
        Me.tile2.Name = "tile2"
        Me.tile2.Size = New System.Drawing.Size(75, 75)
        Me.tile2.TabIndex = 8
        Me.tile2.TabStop = False
        Me.tile2.Text = "Button9"
        Me.tile2.UseVisualStyleBackColor = True
        '
        'tile1
        '
        Me.tile1.Location = New System.Drawing.Point(97, 12)
        Me.tile1.Name = "tile1"
        Me.tile1.Size = New System.Drawing.Size(75, 75)
        Me.tile1.TabIndex = 9
        Me.tile1.TabStop = False
        Me.tile1.Text = "Button10"
        Me.tile1.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 264)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(71, 13)
        Me.Label1.TabIndex = 10
        Me.Label1.Text = "Game Status:"
        '
        'status
        '
        Me.status.BackColor = System.Drawing.SystemColors.ButtonHighlight
        Me.status.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.status.Location = New System.Drawing.Point(97, 264)
        Me.status.Name = "status"
        Me.status.Size = New System.Drawing.Size(156, 16)
        Me.status.TabIndex = 11
        Me.status.Text = "Label2"
        '
        'resetButton
        '
        Me.resetButton.Location = New System.Drawing.Point(97, 329)
        Me.resetButton.Name = "resetButton"
        Me.resetButton.Size = New System.Drawing.Size(75, 42)
        Me.resetButton.TabIndex = 12
        Me.resetButton.Text = "Restart Game"
        Me.resetButton.UseVisualStyleBackColor = True
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(13, 295)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(74, 13)
        Me.Label2.TabIndex = 13
        Me.Label2.Text = "Server Status:"
        '
        'picstatus
        '
        Me.picstatus.BackColor = System.Drawing.SystemColors.ButtonHighlight
        Me.picstatus.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.picstatus.Location = New System.Drawing.Point(97, 294)
        Me.picstatus.Name = "picstatus"
        Me.picstatus.Size = New System.Drawing.Size(156, 16)
        Me.picstatus.TabIndex = 14
        Me.picstatus.Text = "Label2"
        '
        'sensor5
        '
        Me.sensor5.BackColor = System.Drawing.Color.Black
        Me.sensor5.Location = New System.Drawing.Point(273, 12)
        Me.sensor5.Name = "sensor5"
        Me.sensor5.Size = New System.Drawing.Size(300, 7)
        Me.sensor5.TabIndex = 15
        '
        'sensor6
        '
        Me.sensor6.BackColor = System.Drawing.Color.Black
        Me.sensor6.Location = New System.Drawing.Point(273, 29)
        Me.sensor6.Name = "sensor6"
        Me.sensor6.Size = New System.Drawing.Size(300, 7)
        Me.sensor6.TabIndex = 16
        '
        'sensor8
        '
        Me.sensor8.BackColor = System.Drawing.Color.Black
        Me.sensor8.Location = New System.Drawing.Point(273, 288)
        Me.sensor8.Name = "sensor8"
        Me.sensor8.Size = New System.Drawing.Size(300, 7)
        Me.sensor8.TabIndex = 17
        '
        'sensor9
        '
        Me.sensor9.BackColor = System.Drawing.Color.Black
        Me.sensor9.Location = New System.Drawing.Point(273, 305)
        Me.sensor9.Name = "sensor9"
        Me.sensor9.Size = New System.Drawing.Size(300, 7)
        Me.sensor9.TabIndex = 18
        '
        'sensor7
        '
        Me.sensor7.BackColor = System.Drawing.Color.Black
        Me.sensor7.Location = New System.Drawing.Point(273, 161)
        Me.sensor7.Name = "sensor7"
        Me.sensor7.Size = New System.Drawing.Size(300, 7)
        Me.sensor7.TabIndex = 19
        '
        'sensor0
        '
        Me.sensor0.BackColor = System.Drawing.Color.Black
        Me.sensor0.Location = New System.Drawing.Point(273, 12)
        Me.sensor0.Name = "sensor0"
        Me.sensor0.Size = New System.Drawing.Size(7, 300)
        Me.sensor0.TabIndex = 20
        '
        'sensor1
        '
        Me.sensor1.BackColor = System.Drawing.Color.Black
        Me.sensor1.Location = New System.Drawing.Point(291, 12)
        Me.sensor1.Name = "sensor1"
        Me.sensor1.Size = New System.Drawing.Size(7, 300)
        Me.sensor1.TabIndex = 21
        '
        'sensor4
        '
        Me.sensor4.BackColor = System.Drawing.Color.Black
        Me.sensor4.Location = New System.Drawing.Point(566, 12)
        Me.sensor4.Name = "sensor4"
        Me.sensor4.Size = New System.Drawing.Size(7, 300)
        Me.sensor4.TabIndex = 22
        '
        'sensor3
        '
        Me.sensor3.BackColor = System.Drawing.Color.Black
        Me.sensor3.Location = New System.Drawing.Point(548, 12)
        Me.sensor3.Name = "sensor3"
        Me.sensor3.Size = New System.Drawing.Size(7, 300)
        Me.sensor3.TabIndex = 23
        '
        'sensor2
        '
        Me.sensor2.BackColor = System.Drawing.Color.Black
        Me.sensor2.Location = New System.Drawing.Point(409, 12)
        Me.sensor2.Name = "sensor2"
        Me.sensor2.Size = New System.Drawing.Size(7, 300)
        Me.sensor2.TabIndex = 24
        '
        'GameplayForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(593, 378)
        Me.Controls.Add(Me.sensor2)
        Me.Controls.Add(Me.sensor3)
        Me.Controls.Add(Me.sensor4)
        Me.Controls.Add(Me.sensor1)
        Me.Controls.Add(Me.sensor0)
        Me.Controls.Add(Me.sensor7)
        Me.Controls.Add(Me.sensor9)
        Me.Controls.Add(Me.sensor8)
        Me.Controls.Add(Me.sensor6)
        Me.Controls.Add(Me.sensor5)
        Me.Controls.Add(Me.picstatus)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.resetButton)
        Me.Controls.Add(Me.status)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.tile1)
        Me.Controls.Add(Me.tile2)
        Me.Controls.Add(Me.tile4)
        Me.Controls.Add(Me.tile3)
        Me.Controls.Add(Me.tile5)
        Me.Controls.Add(Me.tile6)
        Me.Controls.Add(Me.tile7)
        Me.Controls.Add(Me.tile8)
        Me.Controls.Add(Me.tile0)
        Me.Name = "GameplayForm"
        Me.Text = "Rover Tic-Tac-Toe"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents tile0 As Button
    Friend WithEvents tile8 As Button
    Friend WithEvents tile7 As Button
    Friend WithEvents tile6 As Button
    Friend WithEvents tile5 As Button
    Friend WithEvents tile3 As Button
    Friend WithEvents tile4 As Button
    Friend WithEvents tile2 As Button
    Friend WithEvents tile1 As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents status As Label
    Friend WithEvents resetButton As Button
    Friend WithEvents Label2 As Label
    Friend WithEvents picstatus As Label
    Friend WithEvents sensor5 As Label
    Friend WithEvents sensor6 As Label
    Friend WithEvents sensor8 As Label
    Friend WithEvents sensor9 As Label
    Friend WithEvents sensor7 As Label
    Friend WithEvents sensor0 As Label
    Friend WithEvents sensor1 As Label
    Friend WithEvents sensor4 As Label
    Friend WithEvents sensor3 As Label
    Friend WithEvents sensor2 As Label
End Class
