#pragma once
#pragma once
#include "User.h"
#include "Course.h"

const int MAX_USERS = 500;
const int MAX_COURSES = 100;

class DatabaseManager {
private:
    User* users[MAX_USERS];
    Course* courses[MAX_COURSES];
    int userCount = 0;
    int courseCount = 0;

public:
    void addUser(User* user);
    void addCourse(Course* course);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    User* findUser(const std::string& username) const;
};