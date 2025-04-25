#include "Course.h"
//#include <stdexcept>
//#include <numeric>
#include <iostream>
#include "professor.h"

Course::Course(const std::string& id, const std::string& name, int capacity, Professor* prof)
    : courseId(id), name(name), capacity(capacity), professor(prof) {}

bool Course::addStudent(Student* student) {
    if (studentCount >= capacity) {
        std::cerr << "Course capacity full!\n";
        return false;
    }
    enrolledStudents[studentCount++] = student;
    return true;
}

bool Course::addAssignment(Assignment* assignment) {
    if (assignmentCount >= MAX_ASSIGNMENTS) {
        std::cerr << "Max assignments reached!\n";
        return false;
    }
    assignments[assignmentCount++] = assignment;
    return true;
}

bool Course::addAnnouncement(Announcement* announcement)
{
    return false;
}

float Course::getAverageRating() const {
    if (studentRatings.empty()) return 0.0f;
    float sum = 0.0f;
    for (const auto& pair : studentRatings) {
        sum += pair.second;
    }
    return sum / studentRatings.size();
}

std::string Course::getCourseInfo() const
{
    return std::string();
}
