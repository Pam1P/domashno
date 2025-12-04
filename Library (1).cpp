#include "Library.h"
#include <sstream>
#include <algorithm>

void Library::addBook(const Book& b) {
    if (!hasBook(b.getIsbn()))
        books_.push_back(b);
}

void Library::addMember(const Member& m) {
    members_.push_back(m);
}

bool Library::hasBook(const std::string& isbn) const {
    for (const auto& b : books_)
        if (b.getIsbn() == isbn)
            return true;
    return false;
}

bool Library::isBookAvailable(const std::string& isbn) const {
    if (!hasBook(isbn)) return false;

    for (const auto& l : loans_) {
        if (l.getIsbn() == isbn && !l.isReturned())
            return false;
    }
    return true;
}

bool Library::loanBook(const std::string& isbn, const std::string& memberId,
                       const std::string& start, const std::string& due) {
    if (!hasBook(isbn)) return false;
    if (!isBookAvailable(isbn)) return false;

    try {
        loans_.emplace_back(isbn, memberId, start, due);
    } catch (...) {
        return false;
    }

    return true;
}

bool Library::returnBook(const std::string& isbn, const std::string& memberId) {
    for (auto& l : loans_) {
        if (l.getIsbn() == isbn && l.getMemberId() == memberId && !l.isReturned()) {
            l.markReturned();
            return true;
        }
    }
    return false;
}

std::vector<Book> Library::findByAuthor(const std::string& authorName) const {
    std::vector<Book> result;

    for (const auto& b : books_) {
        if (b.getAuthor().getName().find(authorName) != std::string::npos)
            result.push_back(b);
    }
    return result;
}

std::string Library::to_string() const {
    int activeLoans = 0;
    for (const auto& l : loans_)
        if (!l.isReturned()) activeLoans++;

    std::ostringstream oss;
    oss << "Library: " << books_.size()
        << " books, " << members_.size()
        << " members, " << activeLoans
        << " active loans";

    return oss.str();
}
