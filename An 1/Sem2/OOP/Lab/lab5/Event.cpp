#include "Event.h"

// Base class Event implementation
Event::Event(string name, string date, string loc)
        : eventName(name), eventDate(date), location(loc) {}

void Event::displayEventDetails() {
    cout << "Event Name: " << eventName << endl;
    cout << "Date: " << eventDate << endl;
    cout << "Location: " << location << endl;
}

Event::~Event() {}


Conference::Conference(string name, string date, string loc, string speaker)
        : Event(name, date, loc), keynoteSpeaker(speaker) {}

void Conference::displayEventDetails() {
    Event::displayEventDetails();
    cout << "Keynote Speaker: " << keynoteSpeaker << endl;
}

Concert::Concert(string name, string date, string loc, string topic)
        : Event(name, date, loc), ConcertTopic(topic) {}

void Concert::displayEventDetails() {
    Event::displayEventDetails();
    cout << "Concert Topic: " << ConcertTopic << endl;
}
