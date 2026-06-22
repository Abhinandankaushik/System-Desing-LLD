#pragma once
#include <string>
#include <vector>
#include "Owner.hpp"
#include "MenuItem.hpp"
#include "Location.hpp"

class Restaurent
{
private:
    std::string name;
    Owner* owner;
    std::vector<MenuItem*> menu;
    bool isAvailable = false;
    int id;
    LOCATION* location;

public:
    Restaurent(const std::string& name, Owner* owner, LOCATION* location, int id);

    void addMenuItem(MenuItem* item);
    std::vector<MenuItem*> getMenu() const;
    bool prepareFood(const std::vector<MenuItem*>& items);
};