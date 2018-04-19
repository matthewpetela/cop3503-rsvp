/*
rsvp.cpp
COP3503
Project_Team 18:
                Kareem Joudeh
                Nicholas Perret
                Matthew Petela
                Kailee Ringrose
                Kimberly Spencer
                Jovanny Vera
                Mark Wagner
*/

#include <string> //Used for string //matt
#include <ctime> //used for date and time of event //matt

#include "rsvp.h" //includes header file //matt
using namespace std;

void Event::Event();

void Event::setEventName(string event){
    eventName=event;
}
void Event::setEventTime(time_t now){
    eventTimeDate = now;
}
void Event::setEventLocation(string location) {  //Jovanny/Mark
    eventLocation = location;
}
void Event::setEventType(string occassion) {     //Jovanny/Mark
    eventType = occassion;
}

string Event::getEventName() {
    return eventName;
}
string Event::getEventlocation() {
    return eventLocation;
}
string Event::getEventType() {
    return eventType;
}