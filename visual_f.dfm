object VisualForm: TVisualForm
  Left = 0
  Top = 0
  Caption = #1055#1083#1072#1085' '#1087#1086#1084#1077#1097#1077#1085#1080#1103
  ClientHeight = 434
  ClientWidth = 767
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnClose = FormClose
  TextHeight = 13
  object paint_pn: TPanel
    Left = 0
    Top = 0
    Width = 767
    Height = 434
    Align = alClient
    TabOrder = 0
    object paint_ctrl: TPageControl
      Left = 1
      Top = 1
      Width = 765
      Height = 432
      ActivePage = ent_ext
      Align = alClient
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Courier'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      object inv_z: TTabSheet
        Caption = #1048#1085#1074#1077#1085#1090#1072#1088#1080#1079#1072#1094#1080#1103
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Courier'
        Font.Style = []
        ParentFont = False
        object Inventory: TPanel
          AlignWithMargins = True
          Left = 10
          Top = 10
          Width = 737
          Height = 383
          Margins.Left = 10
          Margins.Top = 10
          Margins.Right = 10
          Margins.Bottom = 10
          Align = alClient
          Color = clActiveBorder
          ParentBackground = False
          TabOrder = 0
          object InventoryControl: TPanel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 221
            Height = 375
            Align = alLeft
            Color = clInactiveCaption
            ParentBackground = False
            TabOrder = 0
            object Label1: TLabel
              Left = 32
              Top = 29
              Width = 96
              Height = 13
              Caption = #1058#1080#1087' '#1101#1083#1077#1084#1077#1085#1090#1072
            end
            object Label2: TLabel
              Left = 32
              Top = 79
              Width = 168
              Height = 26
              Caption = #1053#1072#1078#1084#1080#1090#1077' '#1076#1083#1103' '#1088#1072#1089#1089#1095#1077#1090#1072#13#10#1086#1087#1090#1080#1084#1072#1083#1100#1085#1086#1075#1086' '#1084#1072#1088#1096#1088#1091#1090#1072
            end
            object StartBtn: TButton
              Left = 166
              Top = 46
              Width = 27
              Height = 25
              Caption = '>'
              TabOrder = 0
              StyleName = 'Windows'
              OnClick = Invent
            end
            object ComboBox1: TComboBox
              Left = 32
              Top = 48
              Width = 128
              Height = 21
              Style = csDropDownList
              TabOrder = 1
              Items.Strings = (
                #1041#1086#1095#1082#1072
                #1055#1086#1076#1076#1086#1085
                #1050#1086#1088#1086#1073#1082#1072)
            end
          end
          object InventoryV: TListView
            AlignWithMargins = True
            Left = 231
            Top = 4
            Width = 502
            Height = 375
            Align = alClient
            Columns = <
              item
                AutoSize = True
                Caption = #1055#1086#1089#1083#1077#1076#1086#1074#1072#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1089#1073#1086#1088#1072
              end>
            GridLines = True
            ParentShowHint = False
            ShowHint = False
            TabOrder = 1
            ViewStyle = vsReport
          end
        end
      end
      object ent_ext: TTabSheet
        Caption = #1054#1090#1075#1088#1091#1079#1082#1072
        ImageIndex = 2
        object prim_pan: TPanel
          Left = 0
          Top = 0
          Width = 757
          Height = 403
          Align = alClient
          TabOrder = 0
          object ext_pb: TPaintBox
            Left = 1
            Top = 1
            Width = 551
            Height = 335
            Align = alClient
            OnPaint = DrawField
            ExplicitLeft = 320
            ExplicitTop = 39
            ExplicitWidth = 281
            ExplicitHeight = 210
          end
          object legend_pb: TPaintBox
            Left = 552
            Top = 1
            Width = 204
            Height = 335
            Align = alRight
            Anchors = [akTop, akRight]
            OnPaint = DrawLegend
            ExplicitHeight = 401
          end
          object jap1: TPanel
            Left = 1
            Top = 336
            Width = 755
            Height = 66
            Align = alBottom
            Color = clBtnShadow
            ParentBackground = False
            TabOrder = 0
            object Label3: TLabel
              Left = 383
              Top = 16
              Width = 176
              Height = 13
              Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1088#1077#1087#1103#1090#1089#1090#1074#1080#1081
            end
            object OkParty: TEdit
              Left = 256
              Top = 14
              Width = 121
              Height = 21
              TabOrder = 0
              Text = '-1'
              OnKeyPress = Startin
            end
            object Button1: TButton
              Left = 40
              Top = 6
              Width = 17
              Height = 19
              Caption = '^'
              TabOrder = 1
              OnClick = Button1Click
            end
            object Button2: TButton
              Left = 63
              Top = 31
              Width = 17
              Height = 19
              Caption = '>'
              TabOrder = 2
              OnClick = Button2Click
            end
            object Button3: TButton
              Left = 17
              Top = 31
              Width = 17
              Height = 19
              Caption = '<'
              TabOrder = 3
              OnClick = Button3Click
            end
            object Button4: TButton
              Left = 40
              Top = 31
              Width = 17
              Height = 19
              Caption = 'v'
              TabOrder = 4
              OnClick = Button4Click
            end
          end
        end
      end
    end
  end
end
