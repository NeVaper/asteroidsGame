object mainForm: TmainForm
  Left = 318
  Top = 123
  Width = 936
  Height = 679
  Caption = 'Somin Asteroids'
  Color = clBackground
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object canvasImg: TImage
    Left = 0
    Top = 0
    Width = 920
    Height = 640
    Align = alClient
    Enabled = False
    OnMouseDown = canvasImgMouseDown
  end
  object highScore: TLabel
    Left = 338
    Top = 240
    Width = 245
    Height = 33
    Alignment = taCenter
    AutoSize = False
    Caption = 'Higest score: 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS Sans Serif'
    Font.Pitch = fpVariable
    Font.Style = []
    ParentFont = False
    Layout = tlCenter
  end
  object startBtn: TLabel
    Left = 416
    Top = 200
    Width = 84
    Height = 46
    Caption = 'Start'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = startBtnClick
  end
end
