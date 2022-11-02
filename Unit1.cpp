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

	auto *string_reader = new TStringReader(file_contents);
    auto *json_text_reader = new TJsonTextReader(string_reader);
	auto *json_reader = new TJSONIterator(json_text_reader);

	this->books.clear();

    Book current_book;
	bool reading_book = false;

	while(json_reader->Next()) {
		switch(json_reader->Type) {
			// Start of a book
			case TJsonToken::StartObject:
				json_reader->Recurse();
                current_book = Book();
				reading_book = true;
				break;
			case TJsonToken::EndObject:
				reading_book = false;
				this->books.push_back(current_book);
				break;
			case TJsonToken::String:
				if(reading_book) {
					if(json_reader->Key == "title") {
						current_book.title = json_reader->AsString;
						MessageDlg(
							json_reader->AsString,
							mtError, TMsgDlgButtons() << mbOK,
							0
						);
                    }
                }
				break;
			default:
                break;
        }
    }

    this->update_book_data(this->BookList);

	delete string_reader;
	delete json_text_reader;
	delete json_reader;
}

//---------------------------------------------------------------------------

/// The Sender *must* be a ListBox
void __fastcall TMainPage::update_book_data(TListBox *list_box)
{
    list_box->Items->Clear();

	for(auto& book : this->books) {
		list_box->Items->Add(book.title);
    }
}
//---------------------------------------------------------------------------

