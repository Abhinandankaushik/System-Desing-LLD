#include "MenuItem.hpp"

MenuItem::MenuItem(const std::string& name, float price, int itemCode)
    : name(name), price(price), code(itemCode)
{
}

const std::string& MenuItem::getName() const
{
    return name;
}

void MenuItem::setName(const std::string& value)
{
    name = value;
}

float MenuItem::getPrice() const
{
    return price;
}

void MenuItem::setPrice(float value)
{
    price = value;
}

int MenuItem::getCode() const
{
    return code;
}

void MenuItem::setCode(int value)
{
    code = value;
}

