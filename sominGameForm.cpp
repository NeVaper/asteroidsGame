//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sominGameForm.h"
#include "game.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainForm *mainForm;
//---------------------------------------------------------------------------
__fastcall TmainForm::TmainForm(TComponent* Owner)
        : TForm(Owner) {
        hScore = 0;
        mainForm->DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall TmainForm::FormResize(TObject *Sender) {
        mainForm->ClientWidth = WIDTH;
        mainForm->ClientHeight = HEIGHT;
}
//---------------------------------------------------------------------------

void __fastcall TmainForm::FormClose(TObject *Sender, TCloseAction &Action) {
        if(m_game) {
                m_game->terminateLoop();
        }
}
//---------------------------------------------------------------------------

TPoint TmainForm::getMouse() {
        TPoint pos = Mouse->CursorPos;
        pos.x -= mainForm->Left;
        pos.y -= mainForm->Top;
        pos.y -= mainForm->Height - mainForm->ClientHeight;
        // I dont know why i need add -8
        pos.x -= 8;
        pos.y -= 8;
        return pos;
}


void __fastcall TmainForm::canvasImgMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {
        m_game->m_player->pew();
}
//---------------------------------------------------------------------------



void __fastcall TmainForm::startBtnClick(TObject *Sender) {
        hideElements();

        canvasImg->Enabled = true;

        m_game = new Game(canvasImg);
        int score = m_game->playGame();
        if (score > hScore) {
                AnsiString caption = "Higest score: ";
                caption += AnsiString(score);
                highScore->Caption = caption;
        }

        canvasImg->Enabled = false;
        showElements();
}
//---------------------------------------------------------------------------

void TmainForm::hideElements() {
        startBtn->Visible = false;
        highScore->Visible = false;
}

void TmainForm::showElements() {
        startBtn->Visible = true;
        highScore->Visible = true;
}


