#include "Restaurent.hpp"
#include <iostream>
 

using namespace std;


Restaurent::Restaurent(const std::string &name, Owner *owner, LOCATION *location, int id)
    : name(name), owner(owner), location(location), id(id)
{
}

void Restaurent::addMenuItem(MenuItem *item)
{
    menu.push_back(item);
}

std::vector<MenuItem *> Restaurent::getMenu() const
{
    return menu;
}

bool Restaurent::prepareFood(const std::vector<MenuItem *> &items)
{
    if (items.empty())
    {
        cout << "Invalid Input , Provide item for prepration" << endl;
    }

    cout << "Preparing Food : " << endl;
    for (auto it : items)
    {
        cout << it->getName() << ": " << it->getPrice() << endl;
    }

}
