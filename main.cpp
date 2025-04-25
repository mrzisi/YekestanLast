#include "DatabaseManager.h"
#include "Admin.h"
#include "Professor.h"
#include "Student.h"
#include <iostream>
#include "notification.h"

int main() {
    try {
        DatabaseManager db;

        // ایجاد کاربران اولیه
        Admin admin("admin", "1234");
        Professor prof("prof1", "5678");
        Student student("student1", "1111");

        // افزودن به دیتابیس
        db.addUser(&admin);
        db.addUser(&prof);
        db.addUser(&student);

        // ایجاد درس توسط استاد
        Course* cs101 = new Course("CS101", "Programming", 30, &prof);
        db.addCourse(cs101);

        // دانشجو در درس ثبت‌نام می‌کند
        student.enrollInCourse(cs101);

        // ایجاد تکلیف
        Assignment* assignment1 = new Assignment("HW1", "Complete exercises", "2023-12-30");
        cs101->addAssignment(assignment1);

        // ایجاد اعلان
        Announcement* announcement1 = new Announcement("ANN1", "Midterm exam next week");
        cs101->addAnnouncement(announcement1);

        // ذخیره داده‌ها
        db.saveToFile("data.txt");

        std::cout << "System initialized successfully.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}