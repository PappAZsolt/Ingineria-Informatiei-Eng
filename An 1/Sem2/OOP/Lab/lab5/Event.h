#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event {
protected:
    string eventName;
    string eventDate;
    string location;

public:
    Event(string name, string date, string loc);
    virtual void displayEventDetails();
    virtual ~Event();
};

class Conference : public Event {
private:
    string keynoteSpeaker;

public:
    Conference(string name, string date, string loc, string speaker);
    void displayEventDetails() override;
};

class Concert : public Event {
private:
    string ConcertTopic;

public:
    Concert(string name, string date, string loc, string topic);
    void displayEventDetails() override;
};

#endif // EVENT_H
