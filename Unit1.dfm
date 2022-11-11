object MainPage: TMainPage
  Left = 0
  Top = 0
  Caption = ';'
  ClientHeight = 346
  ClientWidth = 550
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = load_books
  PixelsPerInch = 96
  TextHeight = 13
  object GenreLabel: TLabel
    Left = 329
    Top = 27
    Width = 33
    Height = 13
    Caption = 'Genre:'
  end
  object SearchBar: TEdit
    Left = 0
    Top = 0
    Width = 550
    Height = 21
    Align = alTop
    TabOrder = 0
    TextHint = #55357#56590' Search'
  end
  object Genre: TComboBox
    Left = 368
    Top = 24
    Width = 183
    Height = 21
    ItemIndex = 0
    TabOrder = 1
    Text = 'All'
    Items.Strings = (
      'All')
  end
  object BookList: TListBox
    Left = 0
    Top = 21
    Width = 121
    Height = 325
    Align = alLeft
    ItemHeight = 13
    TabOrder = 2
  end
  object BookPanel: TGridPanel
    Left = 127
    Top = 56
    Width = 423
    Height = 290
    ColumnCollection = <
      item
        Value = 25.000000000000000000
      end
      item
        Value = 25.000000000000000000
      end
      item
        Value = 25.000000000000000000
      end
      item
        Value = 25.000000000000000000
      end>
    ControlCollection = <>
    Padding.Left = 10
    Padding.Top = 10
    Padding.Right = 10
    Padding.Bottom = 10
    RowCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    TabOrder = 3
  end
end
