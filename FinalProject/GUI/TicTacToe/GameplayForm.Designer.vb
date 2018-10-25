<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class GameplayForm
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
        Me.moveProg = New System.Windows.Forms.ProgressBar()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'tile0
        '
        Me.tile0.Location = New System.Drawing.Point(16, 12)
        Me.tile0.Name = "tile0"
        Me.tile0.Size = New System.Drawing.Size(75, 75)
        Me.tile0.TabIndex = 0
        Me.tile0.Text = "Button1"
        Me.tile0.UseVisualStyleBackColor = True
        '
        'tile8
        '
        Me.tile8.Location = New System.Drawing.Point(178, 174)
        Me.tile8.Name = "tile8"
        Me.tile8.Size = New System.Drawing.Size(75, 75)
        Me.tile8.TabIndex = 2
        Me.tile8.Text = "Button3"
        Me.tile8.UseVisualStyleBackColor = True
        '
        'tile7
        '
        Me.tile7.Location = New System.Drawing.Point(97, 174)
        Me.tile7.Name = "tile7"
        Me.tile7.Size = New System.Drawing.Size(75, 75)
        Me.tile7.TabIndex = 3
        Me.tile7.Text = "Button4"
        Me.tile7.UseVisualStyleBackColor = True
        '
        'tile6
        '
        Me.tile6.Location = New System.Drawing.Point(16, 174)
        Me.tile6.Name = "tile6"
        Me.tile6.Size = New System.Drawing.Size(75, 75)
        Me.tile6.TabIndex = 4
        Me.tile6.Text = "Button5"
        Me.tile6.UseVisualStyleBackColor = True
        '
        'tile5
        '
        Me.tile5.Location = New System.Drawing.Point(178, 93)
        Me.tile5.Name = "tile5"
        Me.tile5.Size = New System.Drawing.Size(75, 75)
        Me.tile5.TabIndex = 5
        Me.tile5.Text = "Button6"
        Me.tile5.UseVisualStyleBackColor = True
        '
        'tile3
        '
        Me.tile3.Location = New System.Drawing.Point(16, 93)
        Me.tile3.Name = "tile3"
        Me.tile3.Size = New System.Drawing.Size(75, 75)
        Me.tile3.TabIndex = 6
        Me.tile3.Text = "Button7"
        Me.tile3.UseVisualStyleBackColor = True
        '
        'tile4
        '
        Me.tile4.Location = New System.Drawing.Point(97, 93)
        Me.tile4.Name = "tile4"
        Me.tile4.Size = New System.Drawing.Size(75, 75)
        Me.tile4.TabIndex = 7
        Me.tile4.Text = "Button8"
        Me.tile4.UseVisualStyleBackColor = True
        '
        'tile2
        '
        Me.tile2.Location = New System.Drawing.Point(178, 12)
        Me.tile2.Name = "tile2"
        Me.tile2.Size = New System.Drawing.Size(75, 75)
        Me.tile2.TabIndex = 8
        Me.tile2.Text = "Button9"
        Me.tile2.UseVisualStyleBackColor = True
        '
        'tile1
        '
        Me.tile1.Location = New System.Drawing.Point(97, 12)
        Me.tile1.Name = "tile1"
        Me.tile1.Size = New System.Drawing.Size(75, 75)
        Me.tile1.TabIndex = 9
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
        Me.resetButton.Location = New System.Drawing.Point(89, 315)
        Me.resetButton.Name = "resetButton"
        Me.resetButton.Size = New System.Drawing.Size(75, 42)
        Me.resetButton.TabIndex = 12
        Me.resetButton.Text = "Restart Game"
        Me.resetButton.UseVisualStyleBackColor = True
        '
        'moveProg
        '
        Me.moveProg.Location = New System.Drawing.Point(97, 286)
        Me.moveProg.Name = "moveProg"
        Me.moveProg.Size = New System.Drawing.Size(156, 23)
        Me.moveProg.TabIndex = 13
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(10, 289)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(81, 13)
        Me.Label2.TabIndex = 14
        Me.Label2.Text = "Move Progress:"
        '
        'GameplayForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(268, 362)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.moveProg)
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
    Friend WithEvents moveProg As ProgressBar
    Friend WithEvents Label2 As Label
End Class
