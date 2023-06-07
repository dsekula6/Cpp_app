object FormLogin: TFormLogin
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Prijava'
  ClientHeight = 379
  ClientWidth = 261
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 15
  object LabelUsername: TLabel
    Left = 0
    Top = 152
    Width = 77
    Height = 23
    Caption = 'Korisni'#269'ko ime'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelPassword: TLabel
    Left = 28
    Top = 187
    Width = 70
    Height = 23
    Caption = 'Lozinka'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Image1: TImage
    Left = 28
    Top = 24
    Width = 190
    Height = 105
    Stretch = True
  end
  object LabelUserId: TLabel
    Left = 94
    Top = 343
    Width = 34
    Height = 15
    Caption = 'Label1'
    Visible = False
  end
  object EditUsername: TEdit
    Left = 113
    Top = 147
    Width = 105
    Height = 31
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clInactiveCaptionText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TextHint = 'korisni'#269'ko ime'
  end
  object EditPassword: TEdit
    Left = 113
    Top = 184
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
    TextHint = 'lozinka'
  end
  object ButtonLogin: TButton
    Left = 28
    Top = 253
    Width = 190
    Height = 36
    Caption = 'Prijava'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonLoginClick
  end
  object ButtonRegister: TButton
    Left = 28
    Top = 312
    Width = 190
    Height = 25
    Caption = 'Registracija'
    TabOrder = 3
    OnClick = ButtonRegisterClick
  end
  object SQLQuery1: TFDQuery
    Connection = SqlfreehostingConnection
    Left = 77
    Top = 18
  end
  object SqlfreehostingConnection: TFDConnection
    Params.Strings = (
      'User_Name=x5CKIvN4hP'
      'Database=x5CKIvN4hP'
      'Server=remotemysql.com'
      'Password=Vg7Hvluky9'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 26
    Top = 20
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 125
    Top = 20
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 53
    Top = 63
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.ECB'
  end
end
