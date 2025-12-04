#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

class Author {
private:
    std::string name_;
    int birthYear_;

public:
    Author();
    Author(const std::string& name, int birthYear);

    const std::string& getName() const noexcept { return name_; }
    int getBirthYear() const noexcept { return birthYear_; }

    void setBirthYear(int y);
    std::string to_string() const;
};

#endif

