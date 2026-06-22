#pragma once
#include <string>

class MenuItem
{
private:
    std::string name;
    float price;
    int code;
public:
    MenuItem(const std::string& name, float price, int itemCode);

    const std::string& getName() const;
    void setName(const std::string& value);

    float getPrice() const;
    void setPrice(float value);

    int getCode() const;
    void setCode(int value);
};