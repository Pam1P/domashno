#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

class Book {
private:
    std::string title_;
    Author author_;
    int year_;
    double price_;
    std::string isbn_;

    static bool validYear(int y);

public:
    static int totalBooks;

    Book();
    Book(const std::string& title, const Author& author, int year, double price, const std::string& isbn);

    Book(const Book&) = default;
    Book(Book&&) = default;
    Book& operator=(const Book&) = default;
    Book& operator=(Book&&) = default;
    ~Book();   // <-- важно

    const std::string& getTitle() const noexcept { return title_; }
    const Author& getAuthor() const noexcept { return author_; }
    int getYear() const noexcept { return year_; }
    double getPrice() const noexcept { return price_; }
    const std::string& getIsbn() const noexcept { return isbn_; }

    void setYear(int y);
    void setPrice(double p);

    std::string to_string() const;
    static int getTotalBooks() noexcept { return totalBooks; }
};

#endif

