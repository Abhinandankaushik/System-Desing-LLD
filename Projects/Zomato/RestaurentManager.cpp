#include "RestaurentManager.hpp"

std::mutex RestaurentManager::mtx;
RestaurentManager *RestaurentManager::restaurentManagerInstance = nullptr;

RestaurentManager::RestaurentManager() {}

RestaurentManager *RestaurentManager::getRestaurentManager()
{
    if (restaurentManagerInstance == nullptr)
    {
        std::lock_guard<std::mutex> lock(mtx);

        if (restaurentManagerInstance == nullptr)
        {
            restaurentManagerInstance = new RestaurentManager();
        }
    }
    return restaurentManagerInstance;
}

void RestaurentManager::addRestaurent(const std::string &name, Restaurent *restaurent)
{
    if (restaurent != nullptr)
    {
        restaurentMap[name] = restaurent;
    }
}

Restaurent *RestaurentManager::getRestaurent(const std::string &name)
{
    auto it = restaurentMap.find(name);
    if (it != restaurentMap.end())
    {
        return it->second;
    }
    return nullptr;
}
