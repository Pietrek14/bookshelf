object MainPage: TMainPage
  Left = 0
  Top = 0
  Caption = 'Bookshelf'
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
    Left = 369
    Top = 27
    Width = 33
    Height = 13
    Caption = 'Genre:'
  end
  object SearchByLabel: TLabel
    Left = 168
    Top = 27
    Width = 52
    Height = 13
    Caption = 'Search By:'
  end
  object SearchBar: TEdit
    Left = 0
    Top = 0
    Width = 550
    Height = 21
    Align = alTop
    TabOrder = 0
    TextHint = #55357#56590' Search'
    OnChange = SearchBarChange
  end
  object GenreSelect: TComboBox
    Left = 408
    Top = 24
    Width = 134
    Height = 21
    ItemIndex = 0
    TabOrder = 1
    Text = 'All'
    OnChange = SearchBarChange
    Items.Strings = (
      'All'
      'Comedy'
      'Drama'
      'Horror'
      'Thriller'
      'Science-Fiction'
      'Fantasy'
      'Children'
      'Other')
  end
  object BookPanel: TGridPanel
    Left = 0
    Top = 51
    Width = 550
    Height = 294
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
    TabOrder = 2
  end
  object AddBookButton: TButton
    Left = 8
    Top = 24
    Width = 73
    Height = 21
    Caption = 'Add Book'
    TabOrder = 3
    OnClick = AddBookButtonClick
  end
  object SearchBySelect: TComboBox
    Left = 226
    Top = 24
    Width = 127
    Height = 21
    ItemIndex = 0
    TabOrder = 4
    Text = 'All'
    OnChange = SearchBarChange
    Items.Strings = (
      'All'
      'Title'
      'Series'
      'Author'
      'Description'
      'Release Date')
  end
end
