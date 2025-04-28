#include "SystemUI.h"
#include "Admin.h"
#include "Professor.h"
#include "Student.h"

SystemUI::SystemUI(DatabaseManager& database) : db(database) {}

void SystemUI::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void SystemUI::pause() {
    std::cout << "\nEnter bezan...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

User* SystemUI::login() {
    clearScreen();
    std::string uname, pwd;

    std::cout << "===============\n"
        << "YEKESTAN \n"
        << "===============\n"
        << "NAMEKARBARI: ";
    std::cin >> uname;
    std::cout << "RAMZE OBUR: ";
    std::cin >> pwd;

    User* user = db.findUser(uname);
    if (user && user->notification(pwd)) {
        return user;
    }
    std::cout << "NMITUNI VARED BESHI!\n";
    pause();
    return nullptr;
}

SystemUI::SystemUI(DatabaseManager& database)
{
}

void SystemUI::showMainMenu() {
    int choice;
    do {
        clearScreen();
        std::cout << "===============\n"
            << " MENU ASL KARI \n"
            << "===============\n"
            << "1. VORUD\n"
            << "2. KHORUJ\n"
            << "===============\n"
            << "ENTEKHAB: ";
        std::cin >> choice;

        if (choice == 1) {
            if (User* user = login()) {
                switch (user->getRole()) {
                case Role::ADMIN:
                    showAdminMenu(static_cast<Admin*>(user));
                    break;
                case Role::PROFESSOR:
                    showProfessorMenu(static_cast<Professor*>(user));
                    break;
                case Role::STUDENT:
                    showStudentMenu(static_cast<Student*>(user));
                    break;
                }
            }
        }
    } while (choice != 2);
}

void SystemUI::showAdminMenu(Admin* admin) {
    int choice;
    do {
        clearScreen();
        std::cout << "=== PANEL ===\n"
            << "1. IJAD KARBAR\n"
            << "2. MOSHAHEDE KARBARAN\n"
            << "3. BAZGASHT\n"
            << "===============\n"
            << "ENTEKHAB: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            admin->createUser(db);
            pause();
            break;
        case 2:
            admin->viewAllUsers(db);
            pause();
            break;
        }
    } while (choice != 3);
}

void SystemUI::showProfessorMenu(Professor* prof)
{
}

void SystemUI::showStudentMenu(Student* student)
{
}
