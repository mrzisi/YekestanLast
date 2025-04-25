#pragma once
#include "User.h"
#include "Course.h"
#include "Assignment.h"
#include <array>

class Course;
class Assignment;

class Professor : public User {
private:
    static const int MAX_COURSES = 5; 
    std::array<Course*, MAX_COURSES> taughtCourses;
    int courseCount = 0;

public:
    Professor(const std::string& username, const std::string& password);

    bool createCourse(Course* courses[], int& totalCourseCount,
        const std::string& courseId, const std::string& name, int capacity);
    void addAssignment(Course* course, const std::string& assignmentId,
        const std::string& description, const std::string& deadline);
    void gradeStudent(Course* course, Student* student, float grade);
    void postAnnouncement(Course* course, const std::string& content);
};