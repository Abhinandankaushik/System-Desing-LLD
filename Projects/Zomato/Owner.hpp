#pragma once
#include "IPartner.hpp"
#include "common.hpp"
#include <string>

class Owner : public IPartner
{
public:
    Owner(const std::string& name, RATING rating);
};