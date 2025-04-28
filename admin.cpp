#include "Admin.h"
#include <iostream>
#include "databasemanager.h"
//using namespace Database;

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password, Role::ADMIN) {}

void Admin::createUser(User* users[], int& userCount, const std::string& username,
    const std::string& password, Role role) {
    if (userCount >= DatabaseManager::MAX_USERS) {
        std::cerr << "Maximum users reached!\n";
        return;
    }
    users[userCount++] = new User(username, password, role);
    std::cout << "User created: " << username << "\n";
}

void Admin::deleteUser(User* user) {
    user->softDelete();
}

void Admin::restoreUser(User* user) {
    user->restore();
}

void Admin::viewAllCourses(const Course* courses[], int courseCount)
{
}

void Admin::viewAllCourses(const Course* courses[], int courseCount) const
{
}
