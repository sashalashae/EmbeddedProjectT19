<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class SetupForm
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
        Me.startButton = New System.Windows.Forms.Button()
        Me.numPlayers = New System.Windows.Forms.ComboBox()
        Me.difficulty = New System.Windows.Forms.ComboBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.compDifficulty = New System.Windows.Forms.Label()
        Me.credits = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(62, 9)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(161, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Welcome to Rover Tic-Tac-Toe!"
        '
        'startButton
        '
        Me.startButton.Location = New System.Drawing.Point(15, 124)
        Me.startButton.Name = "startButton"
        Me.startButton.Size = New System.Drawing.Size(107, 58)
        Me.startButton.TabIndex = 1
        Me.startButton.Text = "Start Game!"
        Me.startButton.UseVisualStyleBackColor = True
        '
        'numPlayers
        '
        Me.numPlayers.FormattingEnabled = True
        Me.numPlayers.Location = New System.Drawing.Point(148, 38)
        Me.numPlayers.Name = "numPlayers"
        Me.numPlayers.Size = New System.Drawing.Size(121, 21)
        Me.numPlayers.TabIndex = 2
        '
        'difficulty
        '
        Me.difficulty.FormattingEnabled = True
        Me.difficulty.Location = New System.Drawing.Point(148, 80)
        Me.difficulty.Name = "difficulty"
        Me.difficulty.Size = New System.Drawing.Size(121, 21)
        Me.difficulty.TabIndex = 3
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(12, 41)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(96, 13)
        Me.Label2.TabIndex = 4
        Me.Label2.Text = "Number of Players:"
        '
        'compDifficulty
        '
        Me.compDifficulty.AutoSize = True
        Me.compDifficulty.Location = New System.Drawing.Point(12, 83)
        Me.compDifficulty.Name = "compDifficulty"
        Me.compDifficulty.Size = New System.Drawing.Size(130, 13)
        Me.compDifficulty.TabIndex = 5
        Me.compDifficulty.Text = "Computer Player Difficulty:"
        '
        'credits
        '
        Me.credits.Location = New System.Drawing.Point(162, 124)
        Me.credits.Name = "credits"
        Me.credits.Size = New System.Drawing.Size(107, 58)
        Me.credits.TabIndex = 6
        Me.credits.Text = "Credits"
        Me.credits.UseVisualStyleBackColor = True
        '
        'SetupForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(286, 194)
        Me.Controls.Add(Me.credits)
        Me.Controls.Add(Me.compDifficulty)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.difficulty)
        Me.Controls.Add(Me.numPlayers)
        Me.Controls.Add(Me.startButton)
        Me.Controls.Add(Me.Label1)
        Me.Name = "SetupForm"
        Me.Text = "Game Setup"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents startButton As Button
    Friend WithEvents numPlayers As ComboBox
    Friend WithEvents difficulty As ComboBox
    Friend WithEvents Label2 As Label
    Friend WithEvents compDifficulty As Label
    Friend WithEvents credits As Button
End Class
