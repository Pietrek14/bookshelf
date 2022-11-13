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
    this->CoverPathField->Text = book.cover_path;

    // Load the cover image
	this->BookCover->Picture->LoadFromFile(book.cover_path);
}
void __fastcall TForm2::EditButtonClick(TObject *Sender)
{
	this->editing = !this->editing;

    this->TitleField->Enabled = this->editing;
    this->AuthorField->Enabled = this->editing;
    this->SeriesField->Enabled = this->editing;
    this->GenreSelect->Enabled = this->editing;
    this->DescriptionField->Enabled = this->editing;
    this->ReleaseDateField->Enabled = this->editing;
    this->LocationField->Enabled = this->editing;
    this->RatingField->Enabled = this->editing;
	this->CoverPathField->Enabled = this->editing;

	if(this->editing) {
		this->EditButton->Caption = "Finish";
	} else {
        this->EditButton->Caption = "Edit";
	}
}
//---------------------------------------------------------------------------
