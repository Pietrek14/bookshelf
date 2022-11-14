//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.JSON.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <System.StrUtils.hpp>
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
#include <Unit3.h>
#include <Vcl.ComCtrls.hpp>
#include <vector>
#include <unordered_map>
//---------------------------------------------------------------------------
class TBookCover : public TImage {
	size_t id;

public:
	__fastcall virtual TBookCover(
		TComponent *owner,
		size_t _id,
		System::UnicodeString cover_path
	);

	void __fastcall open_book_page(TObject*);
    void __fastcall set_visible(const bool visible);
    size_t inline get_id();
    static void __fastcall delete_all();
};

class TMainPage : public TForm
{
__published:	// IDE-managed Components
	TEdit *SearchBar;
	TComboBox *Genre;
	TLabel *GenreLabel;
	TGridPanel *BookPanel;
	TButton *AddBookButton;
	TComboBox *SearchBySelect;
	TLabel *SearchByLabel;
	void __fastcall load_books(TObject *Sender);
	void __fastcall update_list(TListBox *Sender);
	void __fastcall open_book_page(int book_index);
	void __fastcall AddBookButtonClick(TObject *Sender);
	void __fastcall SearchBarChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	void __fastcall update_book_panel(
		TGridPanel *book_panel,
		std::vector<Book> &books
	);
	std::vector<Book> books;
	__fastcall TMainPage(TComponent* Owner);
    __fastcall void save_books();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainPage *MainPage;
//---------------------------------------------------------------------------
#endif
