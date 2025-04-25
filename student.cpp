#include "Student.h"
#include "Course.h" // ????? ??? ???? ??? ????
#include <iostream>
#include "databasemanager.h"

Student::Student(const std::string& username, const std::string& password)
    : User(username, password, Role::STUDENT) {}

bool Student::enrollInCourse(Course* course) {
    if (courseCount >= MAX_COURSES) {
        std::cerr << "Error: Max courses reached for student!\n";
        return false;
    }
    if (course->addStudent(this)) {
        enrolledCourses[courseCount++] = course;
        std::cout << "Enrolled in course: " << course->getCourseInfo() << "\n";
        return true;
    }
    return false;
}

void Student::viewGrades(const Course* course) const {
    std::cout << "Grades for course " << course->getCourseInfo() << ":\n";
    // ?????????? ?????? ????? ?? ???? Course
}

void Student::rateCourse(Course* course, float rating) {
    if (rating < 0 || rating > 5) {
        std::cerr << "Error: Rating must be between 0 and 5!\n";
        return;
    }
    course->addRating(this, rating); // ??? ??????? ??? addRating ?? Course ???? ????
    std::cout << "Rating submitted for course " << course->getCourseInfo() << "\n";
}