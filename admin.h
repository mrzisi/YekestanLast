#pragma once
#include "User.h"

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);

    void createUser(User* users[], int& userCount, const std::string& username,
        const std::string& password, Role role);
    void deleteUser(User* user);
    void restoreUser(User* user);
    void viewAllCourses(const Course* courses[], int courseCount);
    void viewAllCourses(const Course* courses[], int courseCount) const;
};

//class Admin : public User {
//public:
//    Admin(const std::string& uname, const std::string& pwd, Role r);
//
//    void createUser(Database& db);
//    void viewAllUsers(Database& db) const;
//};