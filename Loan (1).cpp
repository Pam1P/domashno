#include "Loan.h"
#include <sstream>
#include <stdexcept>

Loan::Loan(const std::string& isbn, const std::string& memberId,
           const std::string& startDate, const std::string& dueDate)
    : isbn_(isbn), memberId_(memberId), startDate_(startDate), dueDate_(dueDate), returned_(false) {
    if (dueDate < startDate) {
        throw std::invalid_argument("Invalid dates");
    }
}

bool Loan::isOverdue(const std::string& today) const {
    if (returned_) return false;
    return today > dueDate_;
}

std::string Loan::to_string() const {
    std::ostringstream oss;
    oss << "Loan: ISBN=" << isbn_
        << ", Member=" << memberId_
        << ", Start=" << startDate_
        << ", Due=" << dueDate_
        << ", Returned=" << (returned_ ? "yes" : "no");
    return oss.str();
}
