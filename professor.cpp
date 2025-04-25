#include "Professor.h"
#include "Course.h" // ????? ??? ???? ??? ????
#include "Assignment.h"
#include <iostream>

Professor::Professor(const std::string& username, const std::string& password)
    : User(username, password, Role::PROFESSOR) {}

bool Professor::createCourse(Course* courses[], int& totalCourseCount,
    const std::string& courseId, const std::string& name, int capacity) {
    if (courseCount >= MAX_COURSES) {
        std::cerr << "Error: Professor cannot teach more than " << MAX_COURSES << " courses!\n";
        return false;
    }
    courses[totalCourseCount++] = new Course(courseId, name, capacity, this);
    taughtCourses[courseCount++] = courses[totalCourseCount - 1];
    std::cout << "Course created: " << name << "\n";
    return true;
}

void Professor::addAssignment(Course* course, const std::string& assignmentId,
    const std::string& description, const std::string& deadline) {
    Assignment* assignment = new Assignment(assignmentId, description, deadline);
    course->addAssignment(assignment); // ??? ??????? ??? addAssignment ?? Course ???? ????
    std::cout << "Assignment added: " << assignmentId << "\n";
}

void Professor::gradeStudent(Course* course, Student* student, float grade) {
    // ??? ??????? ??? gradeStudent ?? Course ???? ????
    course->gradeStudent(student, grade);
    std::cout << "Graded student: " << student->getUsername() << "\n";
}