#include "Author.h"
#include <sstream>

Author::Author() : name_("Unknown"), birthYear_(1900) {}

Author::Author(const std::string& name, int birthYear)
    : name_(name), birthYear_(birthYear) {
    setBirthYear(birthYear);
}

void Author::setBirthYear(int y) {
    if (y < 1850) birthYear_ = 1850;
    else if (y > 2025) birthYear_ = 2025;
    else birthYear_ = y;
}

std::string Author::to_string() const {
    std::ostringstream oss;
    oss << name_ << " (" << birthYear_ << ")";
    return oss.str();
}
