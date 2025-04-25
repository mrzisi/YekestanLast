#include "DatabaseManager.h"
#include <fstream>
#include <sstream>

void DatabaseManager::addUser(User* user) {
    if (userCount >= MAX_USERS) {
        throw std::runtime_error("User capacity exceeded");
    }
    users[userCount++] = user;
}

void DatabaseManager::addCourse(Course* course)
{
}

void DatabaseManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open file for writing");
    }

    file << "Users:\n";
    for (int i = 0; i < userCount; ++i) {
        file << users[i]->getUsername() << ","
            << static_cast<int>(users[i]->getRole()) << "\n";
    }

    file << "Courses:\n";
    for (int i = 0; i < courseCount; ++i) {
        file << courses[i]->getCourseInfo() << "\n";
    }
}

void DatabaseManager::loadFromFile(const std::string& filename)
{
}

User* DatabaseManager::findUser(const std::string& username) const
{
    return nullptr;
}
