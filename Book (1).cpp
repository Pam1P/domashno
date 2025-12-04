#include "Book.h"
#include <sstream>

int Book::totalBooks = 0;

bool Book::validYear(int y) {
    return y >= 1450 && y <= 2025;
}

Book::Book()
    : title_("Untitled"), author_(), year_(1900), price_(0.0), isbn_("") {
    ++totalBooks;
}

Book::Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn)
    : title_(title), author_(author), year_(1900), price_(0.0), isbn_(isbn) {
    setYear(year);
    setPrice(price);
    ++totalBooks;
}

Book::~Book() {
    --totalBooks;
}

void Book::setYear(int y) {
    if (validYear(y)) year_ = y;
    else year_ = 1900;
}

void Book::setPrice(double p) {
    if (p < 0) price_ = 0;
    else price_ = p;
}

std::string Book::to_string() const {
    std::ostringstream oss;
    oss << "Title: " << title_
        << "; Author: " << author_.to_string()
        << "; Year: " << year_
        << "; Price: " << price_
        << "; ISBN: " << isbn_;
    return oss.str();
}

