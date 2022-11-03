//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainPage *MainPage;
//---------------------------------------------------------------------------
__fastcall TMainPage::TMainPage(TComponent* Owner)
	: TForm(Owner)
{
}

#include <iostream>

void __fastcall TMainPage::load_books(TObject *Sender)
{
	System::UnicodeString file_contents;

	try {
        file_contents = TFile::ReadAllText("books.json");
	} catch (...) {
		MessageDlg(
			"The 'books.json' file has not been found!",
			mtError, TMsgDlgButtons() << mbOK,
			0
		);
        return;
	}

	auto *books = (TJSONArray*) TJSONObject::ParseJSONValueUTF8(
		TEncoding::ASCII->GetBytes(file_contents),
		0
	);

	int book_num = books->Size();

	this->books.clear();
	this->books.reserve(book_num);

	__try {
		for(int i = 0; i < book_num; i++) {
			auto *book = (TJSONObject*) books->Get(i);
			Book current_book;

			current_book.title = book->Get("title")->JsonValue->ToString();
			current_book.series = book->Get("series")->JsonValue->ToString();
			current_book.author = book->Get("author")->JsonValue->ToString();
			current_book.genre = book->Get("genre")->JsonValue->ToString();
			current_book.description = book->Get("description")
				->JsonValue
				->ToString();
			current_book.release_date = book->Get("release_date")
				->JsonValue
				->ToString();
			current_book.location = book->Get("location")
				->JsonValue
				->ToString();
			current_book.rating = StrToInt(
				book->Get("rating")->JsonValue->ToString()
			);
			current_book.cover_path = book->Get("cover")->JsonValue->ToString();

            this->books.push_back(current_book);
        }
	}
	__finally {
        books->Free();
    }

	update_list(this->BookList);
}

//---------------------------------------------------------------------------

void __fastcall TMainPage::update_list(TListBox *list_box)
{
    list_box->Items->Clear();

	for(auto& book : this->books) {
		list_box->Items->Add(book.title);
    }
}
//---------------------------------------------------------------------------

