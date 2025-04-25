#include "User.h"
#include <iostream>

User::User(const std::string& username, const std::string& password, Role role)
    : username(username), password(password), role(role) {}

bool User::login(const std::string& inputPassword) const {
    return !isDeleted && (password == inputPassword);
}

void User::logout() {
    std::cout << username << " logged out.\n";
}

Role User::getRole() const
{
    return Role();
}

std::string User::getUsername() const
{
    return std::string();
}

bool User::getIsDeleted() const
{
    return false;
}

void User::softDelete() {
    isDeleted = true;
    std::cout << username << " soft deleted.\n";
}

void User::restore() {
    isDeleted = false;
    std::cout << username << " restored.\n";
}