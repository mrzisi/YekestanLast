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
    bool isAccountActive() const;
    bool getIsDeleted() const;
    void softDelete();
    void restore();
};

/*#pragma once
#include <string>

enum class Role { ADMIN, PROFESSOR, STUDENT };

class User {
protected:
    std::string username;
    std::string password;
    Role role;
    bool isActive = true;

public:
    User(const std::string& uname, const std::string& pwd, Role r);
    virtual ~User() = default;

    bool authenticate(const std::string& input) const;
    Role getRole() const;
    std::string getUsername() const;
    bool isAccountActive() const;
    bool getIsDeleted() const;
}*/;