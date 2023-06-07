object FormHome: TFormHome
  Left = 0
  Top = 0
  Caption = 'MyAlbums'
  ClientHeight = 774
  ClientWidth = 1244
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -15
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = True
  Position = poDesigned
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 20
  object Label2: TLabel
    Left = 136
    Top = -24
    Width = 74
    Height = 20
    Caption = 'My Albums'
    Color = clWhite
    ParentColor = False
  end
  object Label3: TLabel
    Left = 272
    Top = 240
    Width = 61
    Height = 20
    Caption = 'idalbums'
    FocusControl = DBEdit1
  end
  object Label4: TLabel
    Left = 22
    Top = 300
    Width = 37
    Height = 20
    Caption = 'name'
    FocusControl = DBEdit2
  end
  object Label5: TLabel
    Left = 20
    Top = 360
    Width = 33
    Height = 20
    Caption = 'artist'
    FocusControl = DBEdit3
  end
  object Label6: TLabel
    Left = 20
    Top = 420
    Width = 55
    Height = 20
    Caption = 'coverUrl'
    FocusControl = DBEdit4
  end
  object Label8: TLabel
    Left = 20
    Top = 479
    Width = 90
    Height = 20
    Caption = 'tracklistCount'
    FocusControl = DBEdit5
  end
  object Label7: TLabel
    Left = 22
    Top = 539
    Width = 45
    Height = 20
    Caption = 'variant'
  end
  object Image2: TImage
    Left = 28
    Top = 32
    Width = 165
    Height = 89
    Stretch = True
  end
  object Label9: TLabel
    Left = 28
    Top = 119
    Width = 88
    Height = 20
    Caption = 'Logged in as:'
  end
  object LabelUsername: TLabel
    Left = 28
    Top = 142
    Width = 64
    Height = 20
    Caption = 'username'
  end
  object Label10: TLabel
    Left = 28
    Top = 168
    Width = 47
    Height = 20
    Caption = 'user id:'
  end
  object LabelUserId: TLabel
    Left = 81
    Top = 168
    Width = 40
    Height = 20
    Caption = 'userId'
  end
  object Label11: TLabel
    Left = 20
    Top = 599
    Width = 47
    Height = 20
    Caption = 'bodovi'
  end
  object Image3: TImage
    Left = 236
    Top = 32
    Width = 138
    Height = 130
  end
  object Label12: TLabel
    Left = 218
    Top = 168
    Width = 172
    Height = 20
    Caption = 'Album Cover (my albums)'
    Color = clWhite
    ParentColor = False
  end
  object LabelSortBy: TLabel
    Left = 28
    Top = 194
    Width = 50
    Height = 20
    Caption = 'Sort by:'
  end
  object LabelFilter: TLabel
    Left = 8
    Top = 236
    Width = 83
    Height = 20
    Caption = 'Filter Variant'
  end
  object Label13: TLabel
    Left = 272
    Top = 194
    Width = 86
    Height = 20
    Caption = 'AlbumCount:'
  end
  object LabelAlbumCount: TLabel
    Left = 364
    Top = 194
    Width = 4
    Height = 20
  end
  object ButtonSettings: TButton
    Left = 28
    Top = 262
    Width = 165
    Height = 36
    Caption = 'Settings'
    TabOrder = 0
    OnClick = ButtonSettingsClick
  end
  object Memo1: TMemo
    Left = 8
    Top = 279
    Width = 29
    Height = 31
    TabOrder = 1
    Visible = False
  end
  object ButtonRate: TButton
    Left = 20
    Top = 659
    Width = 190
    Height = 33
    Caption = 'Rate Album'
    TabOrder = 2
    OnClick = ButtonRateClick
  end
  object ButtonSearch: TButton
    Left = 48
    Top = 698
    Width = 326
    Height = 41
    Caption = 'Search'
    TabOrder = 3
    OnClick = ButtonSearchClick
  end
  object DBEdit1: TDBEdit
    Left = 236
    Top = 266
    Width = 164
    Height = 28
    Color = clWhite
    DataField = 'idalbums'
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object DBEdit2: TDBEdit
    Left = 20
    Top = 326
    Width = 380
    Height = 28
    Color = clWhite
    DataField = 'name'
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object DBEdit3: TDBEdit
    Left = 20
    Top = 386
    Width = 380
    Height = 28
    Color = clWhite
    DataField = 'artist'
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object DBEdit4: TDBEdit
    Left = 20
    Top = 446
    Width = 380
    Height = 28
    Color = clWhite
    DataField = 'coverUrl'
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object DBEdit5: TDBEdit
    Left = 20
    Top = 505
    Width = 380
    Height = 28
    Color = clWhite
    DataField = 'tracklistCount'
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object ButtonExportXML: TButton
    Left = 406
    Top = 645
    Width = 206
    Height = 36
    Caption = 'Export albums as XML'
    TabOrder = 9
    OnClick = ButtonExportXMLClick
  end
  object ButtonExportJSON: TButton
    Left = 618
    Top = 645
    Width = 249
    Height = 36
    Caption = 'Export albums as JSON'
    TabOrder = 10
    OnClick = ButtonExportJSONClick
  end
  object DBGrid1: TDBGrid
    Left = 406
    Top = 56
    Width = 771
    Height = 537
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    Options = [dgEditing, dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    TabOrder = 11
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clBlack
    TitleFont.Height = -15
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'idalbums'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'name'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'artist'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'coverUrl'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'albumCover'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'tracklistCount'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'albumVariant'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'bodovi'
        ReadOnly = False
        Width = 90
        Visible = True
      end>
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 20
    Top = 565
    Width = 380
    Height = 28
    Color = clWhite
    DataField = 'albumVariant'
    DataSource = DataSourceQuery
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = []
    KeyField = 'variant'
    ListField = 'variant'
    ListSource = DataSource2
    ParentFont = False
    TabOrder = 12
  end
  object Edit2: TEdit
    Left = 22
    Top = 625
    Width = 188
    Height = 28
    TabOrder = 13
  end
  object DBNavigator1: TDBNavigator
    Left = 406
    Top = 599
    Width = 750
    Height = 40
    DataSource = DataSourceQuery
    TabOrder = 14
  end
  object ButtonRemoveImage: TButton
    Left = 873
    Top = 645
    Width = 290
    Height = 36
    Caption = 'Remove image from albums'
    TabOrder = 15
    OnClick = ButtonRemoveImageClick
  end
  object ComboBoxSortBy: TComboBox
    Left = 136
    Top = 194
    Width = 112
    Height = 28
    TabOrder = 16
    OnChange = ComboBoxSortByChange
    Items.Strings = (
      'idalbums'
      'name'
      'artist'
      'albumVariant'
      'bodovi')
  end
  object ComboBoxFilter: TComboBox
    Left = 136
    Top = 228
    Width = 112
    Height = 28
    TabOrder = 17
    OnExit = ComboBoxFilterExit
    Items.Strings = (
      'albumVariant = '#39'anniv.'#39
      'albumVariant = '#39'japanese'#39
      'albumVariant = '#39'regular'#39
      'albumVariant = '#39'EP'#39
      'albumVariant = '#39'single'#39
      'albumVariant = '#39'remaster'#39)
  end
  object ButtonAllImages: TButton
    Left = 873
    Top = 687
    Width = 290
    Height = 33
    Caption = 'Download all images'
    TabOrder = 18
    OnClick = ButtonAllImagesClick
  end
  object ProgressBar1: TProgressBar
    Left = 416
    Top = 687
    Width = 451
    Height = 33
    TabOrder = 19
  end
  object ButtonHRV: TButton
    Left = 162
    Top = 127
    Width = 50
    Height = 25
    Caption = 'HRV'
    TabOrder = 20
    OnClick = ButtonHRVClick
  end
  object ButtonENG: TButton
    Left = 163
    Top = 158
    Width = 49
    Height = 25
    Caption = 'ENG'
    TabOrder = 21
    OnClick = ButtonENGClick
  end
  object ButtonDeleteAlbum: TButton
    Left = 218
    Top = 659
    Width = 182
    Height = 33
    Caption = 'Delete Album'
    TabOrder = 22
    OnClick = ButtonDeleteAlbumClick
  end
  object ButtonDeleteAccount: TButton
    Left = 1046
    Top = 16
    Width = 131
    Height = 34
    Caption = 'Delete Account'
    TabOrder = 23
    OnClick = ButtonDeleteAccountClick
  end
  object Button1: TButton
    Left = 304
    Top = 446
    Width = 145
    Height = 65
    Caption = 'Button1'
    TabOrder = 24
  end
  object Button2: TButton
    Left = 560
    Top = 726
    Width = 169
    Height = 35
    Caption = 'Button2'
    TabOrder = 25
  end
  object DataSource1: TDataSource
    DataSet = FDTable1
    Left = 634
    Top = 142
  end
  object FDTable1: TFDTable
    IndexFieldNames = 'idalbums'
    Connection = SqlfreehostingConnection
    TableName = 'x5CKIvN4hP.albums'
    Left = 363
    Top = 81
    object FDTable1idalbums: TFDAutoIncField
      FieldName = 'idalbums'
      Origin = 'idalbums'
      ReadOnly = True
    end
    object FDTable1name: TStringField
      FieldName = 'name'
      Origin = '`name`'
      Required = True
      Size = 45
    end
    object FDTable1artist: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'artist'
      Origin = 'artist'
      Size = 45
    end
    object FDTable1coverUrl: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'coverUrl'
      Origin = 'coverUrl'
      Size = 255
    end
    object FDTable1albumCover: TBlobField
      AutoGenerateValue = arDefault
      FieldName = 'albumCover'
      Origin = 'albumCover'
    end
    object FDTable1tracklistCount: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'tracklistCount'
      Origin = 'tracklistCount'
    end
    object FDTable1albumVariant: TStringField
      FieldName = 'albumVariant'
      Size = 10
    end
  end
  object SQLQuery1: TFDQuery
    Connection = SqlfreehostingConnection
    Left = 277
    Top = 149
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 20
    Top = 5
    object LinkControlToField3: TLinkControlToField
      Category = 'Quick Bindings'
      DataSource = BindSourceDB1
      FieldName = 'albumCover'
      Control = Image3
      Track = False
    end
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Method = sslvSSLv23
    SSLOptions.SSLVersions = [sslvTLSv1, sslvTLSv1_1, sslvTLSv1_2]
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 366
    Top = 65
  end
  object SqlfreehostingConnection: TFDConnection
    Params.Strings = (
      'User_Name=x5CKIvN4hP'
      'Database=x5CKIvN4hP'
      'Server=remotemysql.com'
      'Password=Vg7Hvluky9'
      'DriverID=MySQL')
    LoginPrompt = False
    Left = 607
    Top = 79
  end
  object FDTable2: TFDTable
    IndexFieldNames = 'idvariant'
    Connection = SqlfreehostingConnection
    TableName = 'variant'
    Left = 418
    Top = 156
  end
  object DataSource2: TDataSource
    DataSet = FDTable2
    Left = 566
    Top = 92
  end
  object TestQuery1: TFDQuery
    Connection = SqlfreehostingConnection
    ResourceOptions.AssignedValues = [rvCmdExecMode]
    UpdateOptions.AssignedValues = [uvUpdateMode, uvRefreshMode, uvCheckReadOnly, uvUpdateNonBaseFields]
    UpdateOptions.UpdateTableName = 'x5CKIvN4hP.albums'
    SQL.Strings = (
      'SELECT albums.*, ocjene.bodovi FROM albums INNER JOIN'
      'ocjene ON albums.idalbums = ocjene.idAlbum INNER JOIN'
      'users ON ocjene.idUser = users.id'
      'WHERE users.id = 1; ')
    Left = 403
    Top = 28
    object TestQuery1idalbums: TFDAutoIncField
      FieldName = 'idalbums'
      Origin = 'idalbums'
      ProviderFlags = [pfInWhere, pfInKey]
      ReadOnly = True
    end
    object TestQuery1name: TStringField
      FieldName = 'name'
      Origin = '`name`'
      Required = True
      Size = 45
    end
    object TestQuery1artist: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'artist'
      Origin = 'artist'
      Size = 45
    end
    object TestQuery1coverUrl: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'coverUrl'
      Origin = 'coverUrl'
      Size = 255
    end
    object TestQuery1albumCover: TBlobField
      AutoGenerateValue = arDefault
      FieldName = 'albumCover'
      Origin = 'albumCover'
    end
    object TestQuery1tracklistCount: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'tracklistCount'
      Origin = 'tracklistCount'
    end
    object TestQuery1albumVariant: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'albumVariant'
      Origin = 'albumVariant'
      Size = 10
    end
    object TestQuery1bodovi: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'bodovi'
      Origin = 'bodovi'
      ProviderFlags = [pfInUpdate]
      ReadOnly = True
    end
  end
  object DataSourceQuery: TDataSource
    DataSet = TestQuery1
    Left = 465
    Top = 63
  end
  object BindSourceDB1: TBindSourceDB
    DataSet = TestQuery1
    ScopeMappings = <>
    Left = 344
    Top = 102
  end
end
