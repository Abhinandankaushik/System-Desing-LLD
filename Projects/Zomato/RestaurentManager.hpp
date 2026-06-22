#pragma once
#include <mutex>
#include <unordered_map>
#include <string>
#include "Restaurent.hpp"
#include "User.hpp"

class RestaurentManager
{
private:
    static std::mutex mtx;
    std::unordered_map<std::string, Restaurent*> restaurentMap;
    static RestaurentManager* restaurentManagerInstance;
    RestaurentManager();

public:
    static RestaurentManager* getRestaurentManager();

    void addRestaurent(const std::string& name, Restaurent* restaurent);
    Restaurent* getRestaurent(const std::string& name);
};