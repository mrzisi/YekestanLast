#pragma once
#include <string>
#include <ctime>

class Announcement {
private:
    std::string announcementId;
    std::string content;
    std::time_t publishDate;

public:
    Announcement(const std::string& id, const std::string& content);
    std::string getInfo() const;
};
