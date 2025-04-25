#include "Assignment.h"
#include <stdexcept>

Assignment::Assignment(const std::string& id, const std::string& desc, const std::string& dl)
    : assignmentId(id), description(desc), deadline(dl) {}

void Assignment::gradeStudent(Student* student, float grade) {
    if (grade < 0 || grade > 20) {
        throw std::invalid_argument("Grade must be between 0 and 20");
    }
    grades[student] = grade;
}

float Assignment::getGrade(Student* student) const {
    auto it = grades.find(student);
    return (it != grades.end()) ? it->second : -1; // -1 یعنی نمره ثبت نشده
}

std::string Assignment::getInfo() const {
    return "Assignment ID: " + assignmentId + ", Deadline: " + deadline;
}