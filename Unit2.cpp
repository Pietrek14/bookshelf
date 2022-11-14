//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

__fastcall void TForm2::load_book(const Book& book) {
	// Fill in the data
	this->Caption = book.title;

	this->TitleField->Text = book.title;
	this->AuthorField->Text = book.author;
	this->SeriesField->Text = book.series;

	bool genre_found = false;

	for(int i = 0; i < this->GenreSelect->Items->Count && !genre_found; i++) {
    	auto genre = this->GenreSelect->Items->operator[](i);
		if(genre == book.genre) {
			this->GenreSelect->ItemIndex = i;
            genre_found = true;
        }
	}

	if(!genre_found) {
		this->GenreSelect->ItemIndex =
            this->GenreSelect->Items->Count - 1;
	}

    this->DescriptionField->Text = book.description;

	this->ReleaseDateField->Date = StrToDate(
		book.release_date,
		TFormatSettings::Create("pl-PL")
	);

	this->LocationField->Text =
		book.location == ""
			? "borrowed"
			: book.location;

	this->RatingField->Text = IntToStr(book.rating);

	// Load the cover image
    this->load_book_cover(book.cover_path);
}
void __fastcall TForm2::EditButtonClick(TObject *Sender)
{
	this->editing = !this->editing;
    this->changed = true;

    this->TitleField->Enabled = this->editing;
    this->AuthorField->Enabled = this->editing;
    this->SeriesField->Enabled = this->editing;
    this->GenreSelect->Enabled = this->editing;
    this->DescriptionField->Enabled = this->editing;
    this->ReleaseDateField->Enabled = this->editing;
    this->LocationField->Enabled = this->editing;
    this->RatingField->Enabled = this->editing;
	this->CoverButton->Enabled = this->editing;

	if(this->editing) {
		this->EditButton->Caption = "Finish";
	} else {
        this->EditButton->Caption = "Edit";
	}
}

__fastcall void TForm2::load_book_cover(const UnicodeString& cover_path) {
	this->BookCover->Picture->LoadFromFile(cover_path);
	this->cover_path = cover_path;
}
//---------------------------------------------------------------------------
Book __fastcall TForm2::save() {
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

    return result;
}
void __fastcall TForm2::CoverButtonClick(TObject *Sender)
{
	if(this->CoverDialog->Execute()) {
        if(!FileExists(this->CoverDialog->FileName)) {
			MessageDlg(
				"Such file doesn't exist!",
				mtError, TMsgDlgButtons() << mbOK,
				0
			);
		} else {
			this->load_book_cover(this->CoverDialog->FileName);
		}
    }
}
//---------------------------------------------------------------------------

