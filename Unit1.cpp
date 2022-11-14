//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainPage *MainPage;
//---------------------------------------------------------------------------

// TBookCover
__fastcall TBookCover::TBookCover(
	TComponent *owner,
	size_t _id,
	System::UnicodeString cover_path
) : TImage(owner), id(_id) {
	// Place it under the parent
    this->SetParentComponent(owner);

    // Constant values

	// Book size: 65x105
	this->Width = 65;
	this->Height = 105;

	this->Center = true;
	this->Stretch = true;

	// Loading image from memory
	this->Picture->LoadFromFile(cover_path);

	// Open the correct book page on click
	this->OnClick = this->open_book_page;
}

void __fastcall TBookCover::open_book_page(TObject*) {
	auto *form = GetParentForm(this);
	((TMainPage*)form)->open_book_page(this->id);
}

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

			current_book.title = AnsiDequotedStr(
				book->Get("title")->JsonValue->ToString(),
				'"'
			);
			current_book.series = AnsiDequotedStr(
				book->Get("series")->JsonValue->ToString(),
				'"'
			);
			current_book.author = AnsiDequotedStr(
				book->Get("author")->JsonValue->ToString(),
				'"'
			);
			current_book.genre = AnsiDequotedStr(
				book->Get("genre")->JsonValue->ToString(),
				'"'
			);
			current_book.description = AnsiDequotedStr(
				book->Get("description")
					->JsonValue
					->ToString(),
				'"'
			);
			current_book.release_date = AnsiDequotedStr(
				book->Get("release_date")
					->JsonValue
					->ToString(),
				'"'
			);
			current_book.location = AnsiDequotedStr(
				book->Get("location")
					->JsonValue
					->ToString(),
				'"'
			);
			current_book.rating = StrToInt(
				AnsiDequotedStr(
					book->Get("rating")->JsonValue->ToString(),
					'"'
				)
			);
			current_book.cover_path = ReplaceStr(AnsiDequotedStr(
				book->Get("cover")->JsonValue->ToString(),
				'"'
			), "\\\\", "\\");

            this->books.push_back(current_book);
        }
	}
	__finally {
        books->Free();
    }

    update_book_panel(this->BookPanel);
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

void __fastcall TMainPage::update_book_panel(TGridPanel *book_panel) {
	book_panel->DestroyComponents();

	for(int i = 0; i < this->books.size(); i++) {
		auto& book = this->books[i];

		auto *book_cover = new TBookCover(
			book_panel,
			i,
			book.cover_path
		);     
	}
}

void __fastcall TMainPage::open_book_page(int book_index) {
	auto *book_page = new TForm2(this);
    book_page->load_book(this->books[book_index]);
	book_page->ShowModal();
	if(book_page->changed) {
		const Book new_book = book_page->save();
		books[book_index] = new_book;
		this->save_books();
        this->load_books(nullptr);
	}
    delete book_page;
}

void __fastcall TMainPage::save_books() {
	TJSONArray *book_array;
	__try {
		book_array = new TJSONArray();

		for(int i = 0; i < this->books.size(); i++) {
			auto &book = this->books[i];
			auto *book_json = new TJSONObject();

			book_json->AddPair("title", book.title);
			book_json->AddPair("author", book.author);
			book_json->AddPair("series", book.series);
			book_json->AddPair("genre", book.genre);
			book_json->AddPair("description", book.description);
			book_json->AddPair("release_date", book.release_date);
			book_json->AddPair("location", book.location);
			book_json->AddPair("rating", book.rating);
			book_json->AddPair("cover", book.cover_path);

			book_array->AddElement(book_json);
		}

		TFile::WriteAllText("books.json", book_array->ToString());
	} __finally {
        book_array->Free();
    }
}
void __fastcall TMainPage::AddBookButtonClick(TObject *Sender)
{
	auto *add_book_page = new TForm3(this);
	add_book_page->ShowModal();
	if(add_book_page->added) {
        this->books.push_back(add_book_page->book);     
		this->save_books();
        this->load_books(nullptr);
    }
	delete add_book_page;
}
//---------------------------------------------------------------------------

