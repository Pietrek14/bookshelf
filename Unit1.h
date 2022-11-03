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
#include <vector>
#include <unordered_map>
//---------------------------------------------------------------------------
struct Book {
    System::UnicodeString title;
    System::UnicodeString series;
	System::UnicodeString author;
	System::UnicodeString genre;
	System::UnicodeString description;
	System::UnicodeString release_date;
	System::UnicodeString location;
	int rating;
    System::UnicodeString cover_path;

};

class TMainPage : public TForm
{
__published:	// IDE-managed Components
	TEdit *SearchBar;
	TComboBox *Genre;
	TLabel *GenreLabel;
	TListBox *BookList;
	void __fastcall load_books(TObject *Sender);
	void __fastcall update_list(TListBox *Sender);
private:	// User declarations
	std::vector<Book> books;
public:		// User declarations
	__fastcall TMainPage(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainPage *MainPage;
//---------------------------------------------------------------------------
#endif
