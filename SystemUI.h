//#pragma once
//#pragma once
//#include "User.h"
//#include "Databasemanager.h"
//#include <iostream>
//#include <limits>
//#include "admin.h"

//class SystemUI {
//private:
//    DatabaseManager& db;
//
//    void clearScreen();
//    void pause();
//    User* login();
//
//public:
//    SystemUI(DatabaseManager& database);
//
//    void showMainMenu();
//    void showAdminMenu(Admin* admin);
//    void showProfessorMenu(Professor* prof);
//    void showStudentMenu(Student* student);
//};


#pragma once
#include "User.h"
#include "DatabaseManager.h"
#include <iostream>
#include <limits>


class Admin;
class Professor;
class Student;

class SystemUI {
private:
    DatabaseManager& db;

    SystemUI(DatabaseManager& database);

    void clearScreen();
    void pause();
    User* login();

public:
    SystemUI(DatabaseManager& database);
    void showMainMenu();
    void showAdminMenu(Admin* admin);
    void showProfessorMenu(Professor* prof);
    void showStudentMenu(Student* student);
};