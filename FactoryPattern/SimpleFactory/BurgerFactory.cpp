#include "BurgerFactory.hpp"
#include "NormalBurger.hpp"
#include "PremiumBurger.hpp"

Burger* BurgerFactory::PrepareBurger(BurgerType type){
     
    switch(type){
        case BurgerType::Normal:
          return new NormalBurger();
        
        case BurgerType::Premium:
          return new PremiumBurger();
        default:
          return nullptr;     
    }
};


