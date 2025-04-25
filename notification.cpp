#include "notification.h"
#include <ctime>
#include <sstream>

Announcement::Announcement(const std::string& id, const std::string& content)
    : announcementId(id), content(content) {
    publishDate = std::time(nullptr);
}

std::string Announcement::getInfo() const {
    std::stringstream ss;
    ss << "Announcement ID: " << announcementId
        << "\nDate: " << std::ctime(&publishDate)
        << "Content: " << content;
    return ss.str();
}