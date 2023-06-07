object FormSettings: TFormSettings
  Left = 0
  Top = 0
  Caption = 'Postavke'
  ClientHeight = 372
  ClientWidth = 369
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = True
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 20
  object LabelFontSize: TLabel
    Left = 56
    Top = 56
    Width = 56
    Height = 20
    Caption = 'Veli'#269'ina fonta'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelTheme: TLabel
    Left = 64
    Top = 90
    Width = 45
    Height = 20
    Caption = 'Tema'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelUsername: TLabel
    Left = 24
    Top = 272
    Width = 118
    Height = 20
    Caption = 'Promjena kor. imena'
    OnDblClick = LabelUsernameDblClick
  end
  object LabelImageDir: TLabel
    Left = 53
    Top = 229
    Width = 107
    Height = 20
    Caption = 'Direktorij slika'
    OnClick = LabelImageDirClick
  end
  object ComboBoxFontSize: TComboBox
    Left = 151
    Top = 53
    Width = 161
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'srednje'
    Items.Strings = (
      'malo'
      'srednje'
      'veliko')
  end
  object ComboBoxTheme: TComboBox
    Left = 151
    Top = 87
    Width = 161
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = 'svijetlo'
    Items.Strings = (
      'svijetlo'
      'tamno')
  end
  object ButtonSave: TButton
    Left = 80
    Top = 160
    Width = 217
    Height = 49
    Caption = 'Spremi'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonSaveClick
  end
  object EditUsername: TEdit
    Left = 166
    Top = 269
    Width = 145
    Height = 28
    TabOrder = 3
    Visible = False
  end
  object EditImageDir: TEdit
    Left = 166
    Top = 226
    Width = 145
    Height = 28
    TabOrder = 4
    Visible = False
  end
  object Codec1: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 56
    Top = 24
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-128'
    ChainId = 'native.ECB'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 125
    Top = 20
  end
end
