#pragma once
#include <string>
#include <map>
#include "Student.h"

class Assignment {
private:
    std::string assignmentId;
    std::string description;
    std::string deadline;
    std::map<Student*, float> grades;

public:
    Assignment(const std::string& id, const std::string& desc, const std::string& deadline);
    void gradeStudent(Student* student, float grade);
    float getGrade(Student* student) const;
    std::string getInfo() const;
};
