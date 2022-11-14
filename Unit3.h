//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "Book.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TEdit *TitleField;
	TLabel *TitleLabel;
	TEdit *AuthorField;
	TLabel *AuthorLabel;
	TEdit *SeriesField;
	TLabel *SeriesLabel;
	TComboBox *GenreSelect;
	TLabel *GenreLabel;
	TLabel *DescriptionLabel;
	TMemo *DescriptionField;
	TDateTimePicker *ReleaseDateField;
	TLabel *ReleaseDateLabel;
	TEdit *LocationField;
	TLabel *LocationLabel;
	TLabel *RatingLabel;
	TEdit *RatingField;
	TLabel *CoverLabel;
	TButton *AddButton;
	TOpenPictureDialog *CoverDialog;
	TButton *CoverButton;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall CoverButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	bool added = false;
    UnicodeString cover_path = "";
	Book book;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
