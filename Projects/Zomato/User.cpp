#include "User.hpp"

User::User(const std::string& name, int userId, const LOCATION& address)
    : name(name), userId(userId), address(address)
{
}

const std::string& User::getName() const
{
    return name;
}

void User::setName(const std::string& value)
{
    name = value;
}

int User::getUserId() const
{
    return userId;
}

void User::setUserId(int value)
{
    userId = value;
}

const LOCATION& User::getAddress() const
{
    return address;
}

void User::setAddress(const LOCATION& value)
{
    address = value;
}
