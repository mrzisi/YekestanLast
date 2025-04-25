#pragma once
#include <string>
//#include <array>
//#include <map>
#include "User.h"
#include "Assignment.h"
#include "notification.h"
#include "professor.h"

const int MAX_STUDENTS = 100;
const int MAX_ASSIGNMENTS = 10;
const int MAX_ANNOUNCEMENTS = 20;

class Course {
private:
    std::string courseId;
    std::string name;
    int capacity;
    Professor* professor;
    std::array<Student*, MAX_STUDENTS> enrolledStudents;
    std::array<Assignment*, MAX_ASSIGNMENTS> assignments;
    std::array<Announcement*, MAX_ANNOUNCEMENTS> announcements;
    std::map<std::string, float> studentRatings;
    int studentCount = 0;
    int assignmentCount = 0;
    int announcementCount = 0;

public:
    Course(const std::string& id, const std::string& name, int capacity, Professor* prof);
    bool addStudent(Student* student);
    bool addAssignment(Assignment* assignment);
    bool addAnnouncement(Announcement* announcement);
    float getAverageRating() const;
    std::string getCourseInfo() const;
};
