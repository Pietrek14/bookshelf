object MainPage: TMainPage
  Left = 0
  Top = 0
  Caption = 'Bookshelf'
  ClientHeight = 340
  ClientWidth = 551
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
    Width = 551
    Height = 21
    Align = alTop
    TabOrder = 0
    TextHint = #55357#56590' Search'
    ExplicitWidth = 473
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
    Height = 319
    Align = alLeft
    ItemHeight = 13
    TabOrder = 2
    ExplicitLeft = 152
    ExplicitTop = 128
    ExplicitHeight = 97
  end
end
