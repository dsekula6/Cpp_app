object FormRegister: TFormRegister
  Left = 0
  Top = 0
  Caption = 'Register'
  ClientHeight = 232
  ClientWidth = 248
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 28
    Top = 38
    Width = 77
    Height = 23
    Caption = 'Username'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 28
    Top = 75
    Width = 70
    Height = 23
    Caption = 'Password'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditUsername: TEdit
    Left = 113
    Top = 35
    Width = 105
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clInactiveCaptionText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TextHint = 'username'
  end
  object EditPassword: TEdit
    Left = 113
    Top = 72
    Width = 105
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clInactiveCaptionText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    PasswordChar = '*'
    TabOrder = 1
    TextHint = 'password'
  end
  object ButtonRegister: TButton
    Left = 28
    Top = 136
    Width = 190
    Height = 33
    Caption = 'Register'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonRegisterClick
  end
  object SQLQuery1: TFDQuery
    Connection = FormLogin.SqlfreehostingConnection
    Left = 24
    Top = 18
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = FormLogin.CryptographicLibrary1
    Left = 96
    Top = 18
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.ECB'
  end
end
