#include <iostream>

using namespace std;

class PowerSystem
{
public:
    void providePower()
    {
        cout << "Power Supply : Providing power..." << endl;
    }
};
class CPU
{
public:
    void startFans()
    {
        cout << "CPU : Initialization started..." << endl;
    }
};
class BIOS
{
public:
    void startBios()
    {
        cout << "BIOS : started BIOS..." << endl;
    }
};
class Drivers
{
public:
    void checkDrivers()
    {
        cout << "Drivers : cheking drives..." << endl;
    }
};

class ComputerFacade
{

    BIOS *bios;
    CPU *cpu;
    PowerSystem *power;
    Drivers *driver;

public:
    void startComputer()
    {
        cout << "----------Starting Computer----------" << endl;
        power->providePower();
        bios->startBios();
        cpu->startFans();
        driver->checkDrivers();
        cout << "----------Computer Started----------" << endl;
    }
};

int main()
{

    ComputerFacade *computer = new ComputerFacade();

    computer->startComputer();

    delete computer;

    return 0;
}