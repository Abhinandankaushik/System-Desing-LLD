#include <iostream>
using namespace std;

class Logger
{
public:
    virtual void log() = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger
{
public:
    void log() override
    {
        cout << "Logging On console..." << endl;
    }
};

class FileLogger : public Logger
{
public:
    void log() override
    {
        cout << "Logging On File..." << endl;
    }
    
};



class LoggerFactory {
public:
    virtual  Logger* createLog() = 0;
    virtual ~LoggerFactory() = default;
};


class  FileLoggerFactory : public LoggerFactory {
public:
    Logger* createLog() override {
        return new FileLogger();
    }
      
};
class  ConsoleLoggerFactory : public LoggerFactory {
public:
    Logger* createLog() override {
        return new ConsoleLogger();
    }
      
};


int main (){
 
    //creating File logger
    LoggerFactory* fileFact = new FileLoggerFactory();
    Logger* fileobj = fileFact->createLog();
    fileobj->log();

    //creating Console Logger
    LoggerFactory* consoleFact = new ConsoleLoggerFactory();
    Logger* consoleObj = consoleFact->createLog();
    consoleObj->log();

}