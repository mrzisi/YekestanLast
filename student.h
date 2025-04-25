#pragma once
#include "User.h"
#include "Course.h"
#include <array>

class Course;

class Student : public User {
private:
    static const int MAX_COURSES = 10; 
    std::array<Course*, MAX_COURSES> enrolledCourses;
    int courseCount = 0;

public:
    Student(const std::string& username, const std::string& password);

    bool enrollInCourse(Course* course);
    void viewGrades(const Course* course) const;
    void viewAnnouncements(const Course* course) const;
    void rateCourse(Course* course, float rating);
};