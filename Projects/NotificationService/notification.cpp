#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <set>

using namespace std;

class INotification
{
public:
    virtual string getContent() = 0;
    ~INotification() = default;
};

class INotificationDecorator : public INotification
{
protected:
    INotification *notifi;

public:
    INotificationDecorator(INotification *n)
    {
        this->notifi = n;
    }
    virtual string getContent() = 0;
};

class SimpleNotification : public INotification
{
    string text;

public:
    SimpleNotification(string txt)
    {
        this->text = txt;
    }

    string getContent() override
    {
        return this->text;
    }
};

class TimeStampDecorator : public INotificationDecorator
{
public:
    TimeStampDecorator(INotification *notifi) : INotificationDecorator(notifi) {}

    string getContent() override
    {
        time_t currentTime = time(0);
        return ctime(&currentTime) + notifi->getContent();
    }
};

class SignatureDecorator : public INotificationDecorator
{
    string signature;

public:
    SignatureDecorator(INotification *notifi, string sign) : INotificationDecorator(notifi)
    {
        this->notifi = notifi;
        this->signature = sign;
    }

    string getContent() override
    {
        time_t currentTime = time(0);
        return this->signature + notifi->getContent();
    }
};

class IObserver
{
public:
    virtual void update() = 0;
};

class IObservable
{
protected:
    set<IObserver *> observer;

public:
    virtual void add(IObserver *observer) = 0;
    virtual void remove(IObserver *observer) = 0;
    virtual void notify() = 0;
};

class NotificationObservable : public IObservable
{
    INotification *notification;

public:
    NotificationObservable() : notification(nullptr) {}
    void add(IObserver *observer)
    {
        this->observer.insert(observer);
    }
    void remove(IObserver *observer)
    {
        this->observer.erase(observer);
    }

    void notify()
    {
        for (auto it : observer)
        {

            it->update();
        }
    }

    void sendNotification(INotification *n)
    {

        if (this->notification != nullptr)
        {
            delete notification;
        }
        this->notification = n;
        this->notify();
    }

    string getNotificationContent()
    {
        return notification->getContent();
    }
};

class INotificationStrategy
{
public:
    virtual void sendNotification(string &str) = 0;
};

class EmailStrategy : public INotificationStrategy
{
    string email;

public:
    EmailStrategy(string mail)
    {
        this->email = mail;
    }
    void sendNotification(string &content) override
    {
        cout << "============Email Sending=========" << endl;
        cout << "sending to: " << this->email << endl;
        cout << "Email Notification: " << content << endl;
    }
};

class SMSStrategy : public INotificationStrategy
{
    string number;

public:
    SMSStrategy(string number)
    {
        this->number=number;
    }
    void sendNotification(string &content) override
    {
        cout << "============SMS=============" << endl;
        cout << "SMS sended to: " << this->number << endl;
        cout << "SMS is: " << content << endl;
    }
};

class NotificationService
{
    vector<INotification *> history;
    static NotificationService *obj;
    NotificationObservable *observ;
    NotificationService()
    {
        this->observ = new NotificationObservable();
    }

public:
    static NotificationService *getNotificationService()
    {

        if (obj == nullptr)
        {
            obj = new NotificationService();
        }
        return obj;
    }
    NotificationObservable *getObservable()
    {
        return this->observ;
    }
    void setNotification(INotification *n)
    {

        history.push_back(n);
        observ->sendNotification(n);
    }
};

NotificationService *NotificationService::obj = nullptr;

class NotificationEngine : public IObserver
{
    vector<INotificationStrategy *> stat;
    NotificationObservable *obj;

public:
    NotificationEngine()
    {
        obj = NotificationService::getNotificationService()->getObservable();
        obj->add(this);
    }
    void addNotificationStrategy(INotificationStrategy *s)
    {
        stat.push_back(s);
    }
    void update() override
    {
        for (auto it : stat)
        {
            string msg = obj->getNotificationContent();
            it->sendNotification(msg);
        }
    }
};

class Logger : public IObserver
{

    NotificationObservable *obj;

public:
    Logger()
    {
        this->obj = NotificationService::getNotificationService()->getObservable();
        obj->add(this);
    }
    Logger(NotificationObservable *o)
    {
        this->obj = o;
    }
    void update() override
    {
        cout << "Logging : " << obj->getNotificationContent() << endl;
    }
};

int main()
{
    NotificationService *service = NotificationService::getNotificationService();

    Logger *logger = new Logger();

    NotificationEngine *engine = new NotificationEngine();

    engine->addNotificationStrategy(new SMSStrategy("9323423423"));
    engine->addNotificationStrategy(new EmailStrategy("xyz@gmail.com"));

    INotification *simple = new SimpleNotification("Your Order Placed");
    simple = new TimeStampDecorator(simple);
    simple = new SignatureDecorator(simple, "--Abhinandan Kaushik ");

    service->setNotification(simple);
    return 0;
}