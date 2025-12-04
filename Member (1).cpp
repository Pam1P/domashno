#include "Member.h"
#include <sstream>

Member::Member() : name_("Unknown"), memberId_("UNKNOWN"), yearJoined_(1900) {}

Member::Member(const std::string& name, const std::string& memberId, int yearJoined)
    : name_(name), memberId_(memberId), yearJoined_(yearJoined) {
    if (memberId_.empty()) memberId_ = "UNKNOWN";
}

std::string Member::to_string() const {
    std::ostringstream oss;
    oss << "Member: " << name_ << " [" << memberId_ << "] joined " << yearJoined_;
    return oss.str();
}
