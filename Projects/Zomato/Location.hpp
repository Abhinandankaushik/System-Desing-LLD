#pragma once
#include <string>

class LOCATION
{
private:
    std::string street;
    std::string city;
    std::string zipCode;

public:
    LOCATION();
    LOCATION(const std::string& street, const std::string& city, const std::string& zipCode);

    const std::string& getStreet() const;
    void setStreet(const std::string& value);

    const std::string& getCity() const;
    void setCity(const std::string& value);

    const std::string& getZipCode() const;
    void setZipCode(const std::string& value);
};