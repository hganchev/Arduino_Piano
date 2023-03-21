'
'

Imports System
Imports System.IO.Ports



Public Class Form1

    Dim comPORT As String
    Dim receivedData As String

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Timer1.Enabled = False
        comPORT = ""
        For Each sp As String In My.Computer.Ports.SerialPortNames
            comPort_ComboBox.Items.Add(sp)
        Next
    End Sub


    Private Sub comPort_ComboBox_SelectedIndexChanged(sender As Object, e As EventArgs) Handles comPort_ComboBox.SelectedIndexChanged
        If (comPort_ComboBox.SelectedItem <> "") Then
            comPORT = comPort_ComboBox.SelectedItem
        End If
    End Sub


    Private Sub connect_BTN_Click(sender As Object, e As EventArgs) Handles connect_BTN.Click
        If (connect_BTN.Text = "Connect") Then
            If (comPORT <> "") Then
                SerialPort1.Close()
                SerialPort1.PortName = comPORT
                SerialPort1.BaudRate = 9600
                SerialPort1.DataBits = 8
                SerialPort1.Parity = Parity.None
                SerialPort1.StopBits = StopBits.One
                SerialPort1.Handshake = Handshake.None
                SerialPort1.Encoding = System.Text.Encoding.Default 'very important!
                SerialPort1.ReadTimeout = 10000

                SerialPort1.Open()
                connect_BTN.Text = "Dis-connect"
                Timer1.Enabled = True
                Timer_LBL.Text = "Timer: ON"
            End If
        Else
            SerialPort1.Close()
            connect_BTN.Text = "Connect"
            Timer1.Enabled = False
            Timer_LBL.Text = "Timer: OFF"

        End If


    End Sub


    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        receivedData = ReceiveSerialData()
        RichTextBox1.Text &= receivedData
    End Sub


    Function ReceiveSerialData() As String
        Dim Incoming As String
        Try
            Incoming = SerialPort1.ReadExisting()

            If Incoming = "Do" Then
                PlayBackgroundSoundFileDo()
            ElseIf Incoming = "Re" Then
                PlayBackgroundSoundFileRe()
            ElseIf Incoming = "Mi" Then
                PlayBackgroundSoundFileMi()
            ElseIf Incoming = "Fa" Then
                PlayBackgroundSoundFileFa()
            ElseIf Incoming = "Sol" Then
                PlayBackgroundSoundFileSol()
            ElseIf Incoming = "La" Then
                PlayBackgroundSoundFileLa()
            ElseIf Incoming = "Si" Then
                PlayBackgroundSoundFileSi()
                'ElseIf Incoming = "DO" Then
                'PlayBackgroundSoundFileDo1()
            End If
            If Incoming Is Nothing Then
                Return "nothing" & vbCrLf
            Else
                Return Incoming
            End If
        Catch ex As TimeoutException
            Return "Error: Serial Port read timed out."
        End Try

    End Function



    Sub PlayBackgroundSoundFileDo()
        My.Computer.Audio.Play("..\..\PianoChards\major A middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    Sub PlayBackgroundSoundFileRe()
        My.Computer.Audio.Play("..\..\PianoChards\major B middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    Sub PlayBackgroundSoundFileMi()
        My.Computer.Audio.Play("..\..\PianoChards\major C middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    Sub PlayBackgroundSoundFileFa()
        My.Computer.Audio.Play("..\..\PianoChards\major D middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    Sub PlayBackgroundSoundFileSol()
        My.Computer.Audio.Play("..\..\PianoChards\major E middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    Sub PlayBackgroundSoundFileLa()
        My.Computer.Audio.Play("..\..\PianoChards\major F middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    Sub PlayBackgroundSoundFileSi()
        My.Computer.Audio.Play("..\..\PianoChards\major G middle.wav")
        'AudioPlayMode.WaitToComplete)
    End Sub

    ' Sub PlayBackgroundSoundFileDo1()
    ' My.Computer.Audio.Play("C:\Users\hrist\Desktop\PianoChards\Grand Piano - Fazioli - major A middle.wav")
    'AudioPlayMode.WaitToComplete)
    ' End Sub



    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        RichTextBox1.Text = ""
    End Sub
End Class
