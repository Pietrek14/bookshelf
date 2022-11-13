//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.JSON.hpp>
#include <System.IOUtils.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Book.h>
#include <Unit2.h>
#include <Vcl.ComCtrls.hpp>
#include <vector>
#include <unordered_map>
//---------------------------------------------------------------------------
class TBookCover : TImage {
    size_t id;

public:
	__fastcall virtual TBookCover(
		TComponent *owner,
		size_t _id,
		System::UnicodeString cover_path
	);

	void __fastcall open_book_page(TObject*);
};

class TMainPage : public TForm
{
__published:	// IDE-managed Components
	TEdit *SearchBar;
	TComboBox *Genre;
	TLabel *GenreLabel;
	TGridPanel *BookPanel;
	void __fastcall load_books(TObject *Sender);
	void __fastcall update_list(TListBox *Sender);
	void __fastcall update_book_panel(TGridPanel *book_panel);
	void __fastcall open_book_page(int book_index);
private:	// User declarations
	std::vector<Book> books;
public:		// User declarations
	__fastcall TMainPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainPage *MainPage;
//---------------------------------------------------------------------------
#endif
