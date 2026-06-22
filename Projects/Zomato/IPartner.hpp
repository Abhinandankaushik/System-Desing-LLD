#pragma once
#include <string>
#include "common.hpp"

class IPartner
{
private:
    std::string name;
    RATING rating;
public:
    IPartner(const std::string& name, RATING rating);
};