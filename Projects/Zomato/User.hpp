#pragma once
#include <string>
#include "Location.hpp"
#include "common.hpp"

class User
{
private:
    std::string name;
    int userId;
    LOCATION address;

public:
    User(const std::string& name, int userId, const LOCATION& address);
    User() {}
    const std::string& getName() const;
    void setName(const std::string& value);

    int getUserId() const;
    void setUserId(int value);

    const LOCATION& getAddress() const;
    void setAddress(const LOCATION& value);
};