object Form16: TForm16
  Left = 0
  Top = 0
  Caption = 'Server MainFrom'
  ClientHeight = 166
  ClientWidth = 332
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object cxButton1: TcxButton
    Left = 8
    Top = 39
    Width = 75
    Height = 25
    Caption = 'cxButton1'
    TabOrder = 0
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'cxButton1'
    TabOrder = 1
    OnClick = cxButton2Click
  end
  object cxButton3: TcxButton
    Left = 8
    Top = 70
    Width = 75
    Height = 25
    Caption = 'cxButton1'
    TabOrder = 2
    OnClick = cxButton3Click
  end
  object cxMemo1: TcxMemo
    Left = 89
    Top = 8
    Lines.Strings = (
      'cxMemo1')
    TabOrder = 3
    Height = 122
    Width = 237
  end
end
