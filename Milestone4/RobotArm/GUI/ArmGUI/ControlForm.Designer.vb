﻿<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ControlForm
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
        Me.drawX = New System.Windows.Forms.Button()
        Me.drawO = New System.Windows.Forms.Button()
        Me.checkConnection = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.commandLabel = New System.Windows.Forms.Label()
        Me.reset = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'drawX
        '
        Me.drawX.Location = New System.Drawing.Point(12, 12)
        Me.drawX.Name = "drawX"
        Me.drawX.Size = New System.Drawing.Size(75, 75)
        Me.drawX.TabIndex = 0
        Me.drawX.Text = "Draw X"
        Me.drawX.UseVisualStyleBackColor = True
        '
        'drawO
        '
        Me.drawO.Location = New System.Drawing.Point(93, 12)
        Me.drawO.Name = "drawO"
        Me.drawO.Size = New System.Drawing.Size(75, 75)
        Me.drawO.TabIndex = 1
        Me.drawO.Text = "Draw O"
        Me.drawO.UseVisualStyleBackColor = True
        '
        'checkConnection
        '
        Me.checkConnection.Location = New System.Drawing.Point(174, 12)
        Me.checkConnection.Name = "checkConnection"
        Me.checkConnection.Size = New System.Drawing.Size(75, 75)
        Me.checkConnection.TabIndex = 2
        Me.checkConnection.Text = "Check Connection"
        Me.checkConnection.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 109)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(97, 13)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "Command Number:"
        '
        'commandLabel
        '
        Me.commandLabel.AutoSize = True
        Me.commandLabel.Location = New System.Drawing.Point(115, 109)
        Me.commandLabel.Name = "commandLabel"
        Me.commandLabel.Size = New System.Drawing.Size(39, 13)
        Me.commandLabel.TabIndex = 4
        Me.commandLabel.Text = "Label2"
        '
        'reset
        '
        Me.reset.Location = New System.Drawing.Point(255, 12)
        Me.reset.Name = "reset"
        Me.reset.Size = New System.Drawing.Size(75, 75)
        Me.reset.TabIndex = 5
        Me.reset.Text = "Reset Command Number"
        Me.reset.UseVisualStyleBackColor = True
        '
        'ControlForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(345, 138)
        Me.Controls.Add(Me.reset)
        Me.Controls.Add(Me.commandLabel)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.checkConnection)
        Me.Controls.Add(Me.drawO)
        Me.Controls.Add(Me.drawX)
        Me.Name = "ControlForm"
        Me.Text = "Arm Control"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents drawX As Button
    Friend WithEvents drawO As Button
    Friend WithEvents checkConnection As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents commandLabel As Label
    Friend WithEvents reset As Button
End Class
