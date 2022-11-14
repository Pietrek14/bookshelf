//---------------------------------------------------------------------------

#ifndef BookH
#define BookH

#include <System.hpp>

struct Book {
    size_t id = 0;

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
