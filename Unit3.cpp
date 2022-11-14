//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Book.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::AddButtonClick(TObject *Sender)
{
	if(this->TitleField->Text.IsEmpty()) {
        MessageDlg(
			"Title can't be empty!",
			mtError, TMsgDlgButtons() << mbOK,
			0
		);
		return;
	}

	if(this->AuthorField->Text.IsEmpty()) {
		MessageDlg(
			"Author can't be empty!",
			mtError, TMsgDlgButtons() << mbOK,
			0
		);
		return;
	}

	if(this->cover_path == "") {
        MessageDlg(
			"No cover selected!",
			mtError, TMsgDlgButtons() << mbOK,
			0
		);
        return;
    }

    Book result;
	result.title = this->TitleField->Text;
	result.author = this->AuthorField->Text;
	result.series = this->SeriesField->Text;
	result.genre = this->GenreSelect->Items->operator[](
		this->GenreSelect->ItemIndex
	);
	result.description = this->DescriptionField->Text;
	result.release_date = DateToStr(
		this->ReleaseDateField->Date,
		TFormatSettings::Create("pl-PL")
	);
	if(this->LocationField->Text == "borrowed") {
		result.location = "";
	} else {
		result.location = this->LocationField->Text;
	}
	auto rating = StrToInt(this->RatingField->Text);
	if(rating < 1) {
		MessageDlg(
			"Rating has to be between 1-5. Capping to 1.",
			mtError, TMsgDlgButtons() << mbOK,
			0
		);
		rating = 1;
	}
	if(rating > 5) {
		MessageDlg(
			"Rating has to be between 1-5. Capping to 5.",
			mtError, TMsgDlgButtons() << mbOK,
			0
		);
		rating = 5;
	}
	result.rating = rating;

	result.cover_path = this->cover_path;

	this->added = true;
    this->book = result;
	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CoverButtonClick(TObject *Sender)
{
	if(this->CoverDialog->Execute()) {
		if(!FileExists(this->CoverDialog->FileName)) {
			MessageDlg(
				"Such file doesn't exist!",
				mtError, TMsgDlgButtons() << mbOK,
				0
			);
		} else {
			this->cover_path = this->CoverDialog->FileName;
        }
    }
}
//---------------------------------------------------------------------------
