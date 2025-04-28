#pragma once
#pragma once
#include "User.h"
#include "Course.h"

const int MAX_USERS = 500;
const int MAX_COURSES = 100;

class DatabaseManager {
public:
   /* User* users[MAX_USERS];
    Course* courses[MAX_COURSES];
    int userCount = 0;
    int courseCount = 0;*/

    static const int MAX_USERS = 100;
      std::array<User*, MAX_USERS> users;
        int userCount = 0;
        int courseCount = 0;
public:
    void addUser(User* user);
    void addCourse(Course* course);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    User* findUser(const std::string& username) const;
};


//#pragma once
//#include "User.h"
//#include <array>
//
//class Database {
//private:
//    static const int MAX_USERS = 100;
//    std::array<User*, MAX_USERS> users;
//    int userCount = 0;
//
//public:
//    void addUser(User* user) {
//        if (userCount < MAX_USERS) {
//            users[userCount++] = user;
//        }
//    }
//
//    User* findUser(const std::string& username) const {
//        for (int i = 0; i < userCount; ++i) {
//            if (users[i]->getUsername() == username) {
//                return users[i];
//            }
//        }
//        return nullptr;
//    }
//};