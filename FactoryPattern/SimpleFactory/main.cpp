#include "Burger.hpp"
#include "BurgerFactory.hpp"

int main(){
    // Normal burger
    Burger* normal = BurgerFactory::PrepareBurger(BurgerType::Normal);
    normal->prepare();
    delete normal;
    
    // Premium burger
    Burger* premium = BurgerFactory::PrepareBurger(BurgerType::Premium);
    premium->prepare();
    delete premium;

    return 0;
}