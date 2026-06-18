#include <iostream>
using namespace std;

class Walk
{
public:
    virtual void walk() = 0;
    virtual ~Walk() = default;
};

class NormalWalk : public Walk
{
public:
    void walk() override
    {
        cout << "Normal Walking..." << endl;
    }
};
class NoWalk : public Walk
{
public:
    void walk() override
    {
        cout << "Don't Have Walking Functionality..." << endl;
    }
};

class Talk
{
public:
    virtual void talk() = 0;
    virtual ~Talk() = default;
};

class NormalTalk : public Talk
{
public:
    void talk() override
    {
        cout << "Normal Talking.." << endl;
    }
};

class NoTalk : public Talk
{
public:
    void talk() override
    {
        cout << "Don't Have Talking Functionality" << endl;
    }
};

class Fly
{
public:
    virtual void fly() = 0;
    virtual ~Fly() = default;
};

class NormalFly : public Fly
{
public:
    void fly() override
    {
        cout << "Normal Fly Initiated..." << endl;
    }
};

class JetFly : public Fly
{
public:
    void fly() override
    {
        cout << "Jet Fly Initiated ..." << endl;
    }
};

class Projection
{
public:
    virtual void projection() = 0;
    virtual ~Projection() = default;
};

class SimpleProjection : public Projection
{
public:
    void projection() override
    {
        cout << "Robot Projection Type : Simple" << endl;
    }
};

class WiderProjection : public Projection
{
public:
    void projection() override
    {
        cout << "Robot Projection type : Wider" << endl;
    }
};

//---Robot base class----
class Robot
{
    Talk *T;
    Walk *W;
    Fly *F;
    Projection *P;
    public:
    virtual ~Robot() = default;
    Robot(Talk *t, Walk *w, Fly *f, Projection *p)
    {
        this->T = t;
        this->W = w;
        this->F = f;
        this->P = p;
    }
    void talk()
    {
        T->talk();
    }
    void walk()
    {
        W->walk();
    }
    void fly()
    {
        F->fly();
    }
    void projection()
    {
        P->projection();
    }
};

//---Concreate Robot type-1
class HouseWorkerRobot : public Robot
{
public:
    HouseWorkerRobot(Talk *t, Walk *w, Fly *f, Projection *p) : Robot(t, w, f, p) {}
};

int main() {
   
    
    HouseWorkerRobot* robo = new HouseWorkerRobot(new NormalTalk() , new NormalWalk(),new JetFly() , new WiderProjection());
    robo->talk();
    robo->walk();
    robo->fly();
    robo->projection();
  
    return 0;
}