//---------------------------------------------------------------------------

#ifndef BookH
#define BookH
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
#endif
