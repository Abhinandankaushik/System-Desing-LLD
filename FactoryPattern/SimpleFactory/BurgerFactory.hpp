#pragma once
#include "Type.hpp"
#include "Burger.hpp"

class BurgerFactory {
public:
   static Burger* PrepareBurger(BurgerType type);
    
};