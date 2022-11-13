//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Book.h>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *BookCover;
	TEdit *TitleField;
	TEdit *AuthorField;
	TLabel *AuthorLabel;
	TEdit *SeriesField;
	TLabel *SeriesLabel;
	TComboBox *GenreSelect;
	TLabel *GenreLabel;
	TLabel *DescriptionLabel;
	TDateTimePicker *ReleaseDateField;
	TLabel *ReleaseDateLabel;
	TEdit *LocationField;
	TLabel *LocationLabel;
	TLabel *RatingLabel;
	TEdit *RatingField;
	TButton *EditButton;
	TEdit *CoverPathField;
	TMemo *DescriptionField;
	TButton *SaveButton;
	void __fastcall EditButtonClick(TObject *Sender);
private:	// User declarations
    bool editing = false;
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
    __fastcall void load_book(const Book& book);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
