#include "Location.hpp"

LOCATION::LOCATION() = default;

LOCATION::LOCATION(const std::string& street, const std::string& city, const std::string& zipCode)
    : street(street), city(city), zipCode(zipCode)
{
}

const std::string& LOCATION::getStreet() const
{
    return street;
}

void LOCATION::setStreet(const std::string& value)
{
    street = value;
}

const std::string& LOCATION::getCity() const
{
    return city;
}

void LOCATION::setCity(const std::string& value)
{
    city = value;
}

const std::string& LOCATION::getZipCode() const
{
    return zipCode;
}

void LOCATION::setZipCode(const std::string& value)
{
    zipCode = value;
}
