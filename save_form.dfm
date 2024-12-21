object SaveForm: TSaveForm
  Left = 0
  Top = 0
  Caption = #1056#1072#1073#1086#1090#1072' '#1089' '#1076#1072#1085#1085#1099#1084#1080
  ClientHeight = 398
  ClientWidth = 754
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnClose = Close_ReF
  TextHeight = 13
  object DataPan: TPanel
    Left = 0
    Top = 0
    Width = 754
    Height = 398
    Align = alClient
    TabOrder = 0
    object prdlbl: TLabel
      Left = 8
      Top = 229
      Width = 44
      Height = 13
      Caption = #1055#1088#1086#1076#1091#1082#1090
    end
    object Label2: TLabel
      Left = 8
      Top = 288
      Width = 47
      Height = 13
      Caption = #1047#1072#1082#1072#1079#1095#1080#1082
    end
    object type_pb: TPaintBox
      Left = 336
      Top = 10
      Width = 409
      Height = 179
      OnPaint = TupePaint
    end
    object llbl: TLabel
      Left = 8
      Top = 345
      Width = 66
      Height = 13
      Caption = #1056#1103#1076'-'#1089#1090#1077#1083#1083#1072#1078
    end
    object Label1: TLabel
      Left = 336
      Top = 10
      Width = 46
      Height = 13
      Caption = #1053#1072' '#1082#1072#1088#1090#1077
    end
    object okey: TLabel
      Left = 440
      Top = 195
      Width = 177
      Height = 19
      Caption = #1054#1089#1086#1073#1099#1077' '#1093#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 440
      Top = 229
      Width = 31
      Height = 13
      Caption = 'Label3'
      Visible = False
    end
    object Label4: TLabel
      Left = 552
      Top = 288
      Width = 31
      Height = 13
      Caption = 'Label3'
      Visible = False
    end
    object Label5: TLabel
      Left = 336
      Top = 288
      Width = 31
      Height = 13
      Caption = 'Label3'
      Visible = False
    end
    object Label6: TLabel
      Left = 552
      Top = 345
      Width = 31
      Height = 13
      Caption = 'Label3'
      Visible = False
    end
    object Label7: TLabel
      Left = 336
      Top = 345
      Width = 31
      Height = 13
      Caption = 'Label3'
      Visible = False
    end
    object type_grp: TRadioGroup
      Left = 8
      Top = 10
      Width = 193
      Height = 146
      Caption = #1058#1080#1087' '#1090#1086#1074#1072#1088#1072
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Courier'
      Font.Style = []
      Items.Strings = (
        #1055#1086#1076#1076#1086#1085
        #1041#1086#1095#1082#1072
        #1050#1086#1088#1086#1073#1082#1072)
      ParentFont = False
      TabOrder = 0
      OnClick = Reapint
    end
    object zak_ed: TEdit
      Left = 8
      Top = 307
      Width = 193
      Height = 21
      TabOrder = 1
    end
    object prod_ed: TEdit
      Left = 8
      Top = 248
      Width = 193
      Height = 21
      TabOrder = 2
    end
    object spot_ed: TEdit
      Left = 8
      Top = 364
      Width = 193
      Height = 21
      TabOrder = 3
    end
    object Par1: TEdit
      Left = 440
      Top = 248
      Width = 177
      Height = 21
      Enabled = False
      TabOrder = 4
      OnKeyPress = Filters_Ok
    end
    object Par2: TEdit
      Left = 336
      Top = 307
      Width = 193
      Height = 21
      Enabled = False
      TabOrder = 5
      OnKeyPress = Filters_Ok
    end
    object Par3: TEdit
      Left = 336
      Top = 364
      Width = 193
      Height = 21
      Enabled = False
      TabOrder = 6
      OnKeyPress = Filters_Ok
    end
    object Par4: TEdit
      Left = 552
      Top = 307
      Width = 193
      Height = 21
      Enabled = False
      TabOrder = 7
      OnKeyPress = Filters_Ok
    end
    object Par5: TEdit
      Left = 552
      Top = 364
      Width = 193
      Height = 21
      Enabled = False
      TabOrder = 8
      OnKeyPress = Filters_Ok
    end
    object ComboPar5: TComboBox
      Left = 552
      Top = 364
      Width = 193
      Height = 21
      Style = csDropDownList
      Enabled = False
      TabOrder = 9
      Visible = False
      Items.Strings = (
        #1053#1077' '#1093#1088#1091#1087#1082#1080#1081
        #1061#1088#1091#1087#1082#1080#1081
        #1054#1095#1077#1085#1100' '#1093#1088#1091#1087#1082#1080#1081)
    end
    object GoBTN: TButton
      Left = 255
      Top = 10
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 10
      OnClick = SaveBTN
    end
  end
end
