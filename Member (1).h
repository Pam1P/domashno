#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    std::string name_;
    std::string memberId_;
    int yearJoined_;

public:
    Member();
    Member(const std::string& name, const std::string& memberId, int yearJoined);

    const std::string& getName() const noexcept { return name_; }
    const std::string& getId() const noexcept { return memberId_; }
    int getYearJoined() const noexcept { return yearJoined_; }

    std::string to_string() const;
};

#endif

