#pragma once

class Burger {
public:
    virtual void  prepare() = 0; // Pure virtual function
    virtual ~Burger() = default; //virtual Distructor
};