object MainStorageForm: TMainStorageForm
  Left = 0
  Top = 0
  BorderWidth = 15
  Caption = #1057#1080#1089#1090#1077#1084#1072' '#1091#1087#1088#1072#1074#1083#1085#1077#1085#1080#1103' '#1089#1082#1083#1072#1076#1086#1084
  ClientHeight = 431
  ClientWidth = 745
  Color = clBtnShadow
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Courier'
  Font.Style = []
  OnShow = LetsShow
  TextHeight = 13
  object main_panel_c: TPanel
    Left = 0
    Top = 0
    Width = 745
    Height = 431
    Align = alClient
    BorderWidth = 10
    Color = clSkyBlue
    ParentBackground = False
    TabOrder = 0
    object main_panel_top: TPanel
      Left = 11
      Top = 11
      Width = 723
      Height = 46
      Align = alTop
      Anchors = []
      Color = clBtnShadow
      ParentBackground = False
      TabOrder = 0
      DesignSize = (
        723
        46)
      object vis_b: TButton
        Left = 7
        Top = 19
        Width = 193
        Height = 21
        Anchors = [akLeft]
        Caption = #1054#1090#1088#1080#1089#1086#1074#1072#1090#1100' '#1087#1086#1084#1077#1097#1077#1085#1080#1077
        TabOrder = 0
        OnClick = VisualFormActive
      end
      object reed_b: TButton
        Left = 303
        Top = 19
        Width = 145
        Height = 21
        Anchors = [akLeft]
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1075#1086#1090#1086#1074#1086#1077
        TabOrder = 1
        OnClick = reed_bClick
      end
      object save_b: TButton
        Left = 206
        Top = 19
        Width = 91
        Height = 21
        Anchors = [akLeft]
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        TabOrder = 2
        OnClick = SaveActive
      end
      object close_btn: TButton
        Left = 640
        Top = 19
        Width = 75
        Height = 21
        Anchors = [akTop, akRight]
        Caption = #1042#1099#1093#1086#1076
        TabOrder = 3
        OnClick = Closing
      end
    end
    object main_panel_bot: TPanel
      Left = 11
      Top = 390
      Width = 723
      Height = 30
      Align = alBottom
      Anchors = [akTop]
      Color = clBtnShadow
      ParentBackground = False
      TabOrder = 1
    end
    object pg_ctr_main: TPageControl
      Left = 11
      Top = 57
      Width = 723
      Height = 333
      ActivePage = alcoritm
      Align = alClient
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Courier'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object tovar_sh: TTabSheet
        Caption = #1058#1086#1074#1072#1088#1099
        object Splitter1: TSplitter
          Left = 153
          Top = 0
          Height = 304
          AutoSnap = False
          MinSize = 50
          ExplicitLeft = 129
          ExplicitTop = -2
        end
        object main_lv_tov: TListView
          Left = 156
          Top = 0
          Width = 559
          Height = 304
          Align = alClient
          Columns = <
            item
              Caption = #8470
            end
            item
              AutoSize = True
              Caption = #1055#1072#1088#1090#1080#1103
            end
            item
              AutoSize = True
              Caption = #1055#1088#1086#1076#1091#1082#1090
            end
            item
              AutoSize = True
              Caption = #1047#1072#1082#1072#1079#1095#1080#1082
            end
            item
              AutoSize = True
              Caption = #1055#1086#1079#1080#1094#1080#1103
            end
            item
              AutoSize = True
              Caption = #1059#1087#1072#1082#1086#1074#1082#1072
            end
            item
              AutoSize = True
              Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086
            end
            item
              AutoSize = True
              Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077
            end
            item
              AutoSize = True
              Caption = #1062#1077#1085#1072' '#1089#1086#1076#1077#1088#1078#1072#1085#1080#1103
            end>
          GridLines = True
          HideSelection = False
          MultiSelect = True
          RowSelect = True
          ParentShowHint = False
          PopupMenu = popup_menu
          ShowWorkAreas = True
          ShowHint = True
          TabOrder = 0
          ViewStyle = vsReport
        end
        object main_pan_tov: TPanel
          Left = 0
          Top = 0
          Width = 153
          Height = 304
          Align = alLeft
          Color = clWhite
          ParentBackground = False
          TabOrder = 1
          OnResize = MainPanResize
          object main_tov_fnd_lb: TLabel
            Left = 3
            Top = 16
            Width = 45
            Height = 16
            Caption = #1055#1086#1080#1089#1082
            Color = clMedGray
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clBlack
            Font.Height = -16
            Font.Name = 'Courier'
            Font.Style = []
            ParentColor = False
            ParentFont = False
          end
          object Label1: TLabel
            Left = 0
            Top = 121
            Width = 80
            Height = 13
            Caption = #1047#1072#1087#1080#1089#1072#1090#1100' '#1074
          end
          object main_tov_fn: TEdit
            Left = 2
            Top = 38
            Width = 148
            Height = 21
            TabOrder = 0
            OnEnter = FindActive
            OnExit = FindExit
            OnKeyDown = ClFindS
            OnKeyUp = ClFindUNSHIFT
          end
          object main_tov_sort_btn: TButton
            Left = 3
            Top = 65
            Width = 114
            Height = 25
            Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100
            TabOrder = 1
            OnClick = Sortyrovka
          end
          object sort_flag: TButton
            Left = 123
            Top = 65
            Width = 24
            Height = 25
            Caption = '^'
            TabOrder = 2
            OnClick = SortType
          end
          object sort_combo: TComboBox
            Left = 2
            Top = 96
            Width = 148
            Height = 21
            Style = csDropDownList
            TabOrder = 3
            Items.Strings = (
              #1055#1086' '#1085#1072#1079#1074#1072#1085#1080#1102
              #1055#1086' '#1094#1077#1085#1077' '#1089#1086#1076#1077#1088#1078#1072#1085#1080#1103)
          end
          object log_edO: TEdit
            Left = 0
            Top = 140
            Width = 102
            Height = 21
            TabOrder = 4
            Text = 'example'
            OnEnter = FindActive
            OnExit = FindExit
            OnKeyDown = ClFindS
            OnKeyUp = ClFindUNSHIFT
          end
          object Button3: TButton
            Left = 64
            Top = 16
            Width = 83
            Height = 16
            Caption = #1055#1086#1080#1089#1082#1072#1090#1100
            TabOrder = 5
            OnClick = Fresh
          end
        end
      end
      object player: TTabSheet
        Caption = #1047#1072#1082#1072#1079#1095#1080#1082#1080
        ImageIndex = 2
        object Personal_panel: TPanel
          Left = 0
          Top = 0
          Width = 153
          Height = 304
          Align = alLeft
          TabOrder = 0
          object Label2: TLabel
            Left = 3
            Top = 59
            Width = 24
            Height = 13
            Caption = #1048#1084#1103
          end
          object Сообщение: TLabel
            Left = 3
            Top = 105
            Width = 72
            Height = 13
            Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1077
          end
          object Label3: TLabel
            Left = 0
            Top = 8
            Width = 24
            Height = 13
            Caption = #1051#1086#1075
          end
          object name_fl: TEdit
            Left = 0
            Top = 78
            Width = 102
            Height = 21
            TabOrder = 0
            Text = #1052#1080#1093#1072#1080#1083
            OnEnter = FindActive
            OnExit = FindExit
            OnKeyDown = ClFindS
            OnKeyUp = ClFindUNSHIFT
          end
          object text_fl: TEdit
            Left = 3
            Top = 124
            Width = 102
            Height = 21
            TabOrder = 1
            OnEnter = FindActive
            OnExit = FindExit
            OnKeyDown = ClFindS
            OnKeyUp = ClFindUNSHIFT
          end
          object Button1: TButton
            Left = 111
            Top = 124
            Width = 36
            Height = 21
            Caption = '>'
            TabOrder = 2
            OnClick = AddChat
          end
          object log_ed: TEdit
            Left = 3
            Top = 32
            Width = 102
            Height = 21
            TabOrder = 3
            Text = 'log1'
            OnEnter = FindActive
            OnExit = FindExit
            OnKeyDown = ClFindS
            OnKeyUp = ClFindUNSHIFT
          end
          object Button2: TButton
            Left = 111
            Top = 27
            Width = 36
            Height = 21
            Caption = '>'
            TabOrder = 4
            OnClick = ReChat
          end
        end
        object chat_lv: TListView
          Left = 153
          Top = 0
          Width = 562
          Height = 304
          Margins.Left = 10
          Margins.Top = 10
          Margins.Right = 10
          Margins.Bottom = 60
          Align = alClient
          Anchors = []
          Columns = <
            item
              AutoSize = True
              Caption = #1048#1084#1103
            end
            item
              Caption = #1057#1086#1086#1073#1097#1077#1085#1080#1077
              Width = 500
            end>
          GridLines = True
          TabOrder = 1
          ViewStyle = vsReport
        end
      end
      object alcoritm: TTabSheet
        Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1079#1072#1082#1072#1079#1099
        ImageIndex = 2
        object ListView1: TListView
          Left = 299
          Top = 0
          Width = 416
          Height = 304
          Align = alRight
          Columns = <
            item
              AutoSize = True
              Caption = #1047#1072#1082#1072#1079#1095#1080#1082#1080
            end
            item
              AutoSize = True
              Caption = #1044#1072#1090#1072' '#1089#1076#1072#1095#1080
            end>
          TabOrder = 0
          ViewStyle = vsReport
        end
        object Button4: TButton
          Left = 274
          Top = 3
          Width = 19
          Height = 25
          Caption = '>'
          TabOrder = 1
          OnClick = Button4Click
        end
        object Edit1: TEdit
          Left = 66
          Top = 34
          Width = 202
          Height = 21
          TabOrder = 2
          OnKeyPress = Edit1KeyPress
        end
        object Button5: TButton
          Left = 66
          Top = 3
          Width = 202
          Height = 25
          Caption = #1057#1086#1073#1088#1072#1090#1100' '#1079#1072#1082#1072#1079#1099
          TabOrder = 3
          OnClick = Button5Click
        end
      end
    end
  end
  object load_chat_t: TTimer
    Interval = 10000
    OnTimer = ChatLoad
    Left = 717
    Top = 403
  end
  object popup_menu: TPopupActionBar
    Left = 503
    Top = 162
  end
  object OpenDialog1: TOpenDialog
    Left = 223
    Top = 258
  end
end
