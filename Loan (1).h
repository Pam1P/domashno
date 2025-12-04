#ifndef LOAN_H
#define LOAN_H

#include <string>

class Loan {
private:
    std::string isbn_;
    std::string memberId_;
    std::string startDate_;
    std::string dueDate_;
    bool returned_;

public:
    Loan(const std::string& isbn, const std::string& memberId, const std::string& startDate, const std::string& dueDate);

    void markReturned() { returned_ = true; }
    bool isReturned() const { return returned_; }

    bool isOverdue(const std::string& today) const;

    const std::string& getIsbn() const { return isbn_; }
    const std::string& getMemberId() const { return memberId_; }

    std::string to_string() const;
};

#endif

