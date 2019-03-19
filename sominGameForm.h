//---------------------------------------------------------------------------

#ifndef sominGameFormH
#define sominGameFormH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "spaceShip.h"
#include "game.h"

//---------------------------------------------------------------------------
class TmainForm : public TForm
{
__published:	// IDE-managed Components
        TImage *canvasImg;
        TLabel *startBtn;
        TLabel *highScore;
        void __fastcall FormResize(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall canvasImgMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall startBtnClick(TObject *Sender);
private:	// User declarations
        int hScore;

        void hideElements();
        void showElements();
public:		// User declarations
        Game *m_game;

        TPoint getMouse();
        __fastcall TmainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainForm *mainForm;
//---------------------------------------------------------------------------
#endif
