#include <iostream>
#include <set>
#include <string>
using namespace std;

// forward declare so IChannel can use the pointer type
class ISubscriber;

class IChannel
{
public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unSubscribe(ISubscriber *subscriber) = 0;
    virtual void notify() = 0;
    virtual ~IChannel() = default;
};

class ISubscriber
{
public:
    virtual void update() = 0;
    virtual string getName() const = 0;
    virtual ~ISubscriber() = default;
};


class Channel : public IChannel
{
    string name;
    string videoLink;
    set<ISubscriber *> subscriber;

public:
    Channel(const string &name)
    {
        this->name = name;
        this->videoLink = "https://leetlab.devsh.online";
    }
    void subscribe(ISubscriber *subscriber) override
    {
        if (this->subscriber.find(subscriber) != this->subscriber.end())
        {
            cout << subscriber->getName() << " Already Subscribed :" << this->name << endl;
            return;
        }
        cout << subscriber->getName() << " Subscribed :" << this->name << endl;
        this->subscriber.insert(subscriber);
        
    }

    void unSubscribe(ISubscriber *subscriber) override
    {
        this->subscriber.erase(subscriber);
        cout << subscriber->getName() << "Unsubscribed " << this->name << endl;
    }

    string getVideoLink()
    {
        return this->videoLink;
    }
   

     void notify() override
    {
        for (auto s : subscriber)
        {
            s->update();
        }
    }

    void uploadVideo(string videoLink)
    {
        this->videoLink = videoLink;
        cout << "Added new video Link :" << this->videoLink << endl;
        notify();
    }

   
};


class Subscriber : public ISubscriber
{
    string name;
    Channel *channel;

public:
    Subscriber(const string &name , Channel* channel)
    {
        this->name = name;
        this->channel = channel;
    }
    string getName() const override
    {
        return this->name;
    }
    void addChannel(Channel *channel)
    {
        this->channel = channel;
    }

    void update() override
    {
        cout << name << " received update on channel added new video : [Link " << channel->getVideoLink() << "]" << endl;
    }
};





int main (){

    Channel* channelA = new Channel("YTgaming");

    Subscriber* subA = new Subscriber("John Doe",channelA);
    Subscriber* subB = new Subscriber("Joy",channelA);

    channelA->subscribe(subA) ;  
    channelA->subscribe(subB);

    channelA->uploadVideo("https://newvide.mp4");

    channelA->unSubscribe(subA);

    
    return 0;
    
}