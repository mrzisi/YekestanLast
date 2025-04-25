#pragma once
#include <string>
#include <array>

enum class Role { ADMIN, PROFESSOR, STUDENT };

class User {
protected:
    std::string username;
    std::string password;
    Role role;
    bool isDeleted = false;

public:
    User(const std::string& username, const std::string& password, Role role);
    virtual ~User() = default;

    bool login(const std::string& inputPassword) const;
    void logout();
    Role getRole() const;
    std::string getUsername() const;
    bool getIsDeleted() const;
    void softDelete();
    void restore();
};
