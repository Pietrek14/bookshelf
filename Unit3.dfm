object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Adding Book'
  ClientHeight = 274
  ClientWidth = 452
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object TitleLabel: TLabel
    Left = 16
    Top = 8
    Width = 24
    Height = 13
    Caption = 'Title:'
  end
  object AuthorLabel: TLabel
    Left = 227
    Top = 8
    Width = 37
    Height = 13
    Caption = 'Author:'
  end
  object SeriesLabel: TLabel
    Left = 8
    Top = 35
    Width = 33
    Height = 13
    Caption = 'Series:'
  end
  object GenreLabel: TLabel
    Left = 231
    Top = 35
    Width = 33
    Height = 13
    Caption = 'Genre:'
  end
  object DescriptionLabel: TLabel
    Left = 46
    Top = 59
    Width = 57
    Height = 13
    Caption = 'Description:'
  end
  object ReleaseDateLabel: TLabel
    Left = 8
    Top = 151
    Width = 68
    Height = 13
    Caption = 'Release Date:'
  end
  object LocationLabel: TLabel
    Left = 32
    Top = 181
    Width = 44
    Height = 13
    Caption = 'Location:'
  end
  object RatingLabel: TLabel
    Left = 41
    Top = 208
    Width = 35
    Height = 13
    Caption = 'Rating:'
  end
  object CoverLabel: TLabel
    Left = 43
    Top = 235
    Width = 33
    Height = 13
    Caption = 'Cover:'
  end
  object TitleField: TEdit
    Left = 46
    Top = 5
    Width = 155
    Height = 21
    TabOrder = 0
  end
  object AuthorField: TEdit
    Left = 270
    Top = 5
    Width = 153
    Height = 21
    TabOrder = 1
  end
  object SeriesField: TEdit
    Left = 46
    Top = 32
    Width = 155
    Height = 21
    TabOrder = 2
  end
  object GenreSelect: TComboBox
    Left = 270
    Top = 32
    Width = 153
    Height = 21
    ItemIndex = 7
    TabOrder = 3
    Text = 'Other'
    Items.Strings = (
      'Comedy'
      'Drama'
      'Horror'
      'Thriller'
      'Science-Fiction'
      'Fantasy'
      'Children'
      'Other')
  end
  object DescriptionField: TMemo
    Left = 46
    Top = 78
    Width = 377
    Height = 67
    TabOrder = 4
  end
  object ReleaseDateField: TDateTimePicker
    Left = 82
    Top = 151
    Width = 153
    Height = 21
    Date = 44878.000000000000000000
    Time = 0.601873101848468700
    TabOrder = 5
  end
  object LocationField: TEdit
    Left = 82
    Top = 178
    Width = 153
    Height = 21
    Hint = 'po'#380'yczone'
    TabOrder = 6
  end
  object RatingField: TEdit
    Left = 82
    Top = 205
    Width = 17
    Height = 21
    Alignment = taCenter
    MaxLength = 1
    NumbersOnly = True
    TabOrder = 7
  end
  object CoverPathField: TEdit
    Left = 82
    Top = 232
    Width = 161
    Height = 21
    TabOrder = 8
  end
  object AddButton: TButton
    Left = 348
    Top = 230
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 9
    OnClick = AddButtonClick
  end
end
