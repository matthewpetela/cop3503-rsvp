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

#include <iostream>
#include "rsvp.h"
#include "person.h"
#include <vector>

using namespace std;

// Basic Constructor for an event with all elements filled out // Mark and Jovanny
Event::Event(string eventName, string eventType, string eventTime, string eventLocation) {
    this->eventName = eventName;
    this->eventType = eventType;
    this->time = eventTime;
    this->location = eventLocation;
}

// Creates an event object with no elements filled out // Mark and Jovanny
Event::Event() = default;

// Sets the name of the event // Mark and Jovanny
void Event::setEventName(string eventName){
    this->eventName = eventName;
}

// Sets the type of event, we can have a list of event types the event planner can choose from
// Mark and Jovanny
void Event::setEventType(string eventType){
    this->eventType = eventType;
}

// Sets the time the event will take place // Mark and Jovanny
void Event::setEventTime(string time){
    this->time = time;
}

// Sets the location where the event will take place // Mark and Jovanny
void Event::setEventLocation(string eventLocation){
    this->location = eventLocation;
}

// Returns the name of the event // Mark and Jovanny
string Event::getEventName() { return eventName;}

// Returns the type of the event // Mark and Jovanny
string Event::getEventType() { return eventType;}

// Returns the location of the event // Mark and Jovanny
string Event::getEventLocation() { return location;}

// Returns the time of the event // Mark and Jovanny
string Event::getEventTime() { return time;}

// Creates a person with a name and an age, sets their decision to Undecided
// and says that they are the primary invitee, rather than a plus one
// This person is that added to a vector of all the people invited to the event //Mark and Jovanny
void Event::sendInvite(string name, int age) {
    invitees.push_back(person(name, age, "Undecided", true));
}

// Prints out a list of people that have said they will go to the event // Mark and Jovanny
void Event::rsvpYes() {
    vector<person> rsvpYes;
    for(unsigned int i = 0; i < invitees.size(); i++){
        if(invitees.at(i).getResponse() == "Yes"){}
        rsvpYes.push_back(invitees.at(i));
    }

    cout << "The list of people that have responded that they are going to attend " << eventName << " are: " << endl;
    for( unsigned int i = 0; i < rsvpYes.size() - 1; i++){
        cout << rsvpYes.at(i).getName() << " (" << rsvpYes.at(i).getAge() << "), " << endl;
    }
    cout << rsvpYes.at(rsvpYes.size()).getName() << " (" << rsvpYes.at(rsvpYes.size()).getAge() << ") \n" << endl;
}

// Prints out a list of people that have not responded to the invite // Mark and Jovanny
void Event::rsvpUndecided() {
    vector<person> rsvpUndecided;
    for(unsigned int i = 0; i < invitees.size(); i++){
        if(invitees.at(i).getResponse() == "Undecided"){}
        rsvpUndecided.push_back(invitees.at(i));
    }

    cout << "The list of people that have not responded to the invite for " << eventName << " are: " << endl;
    for( unsigned int i = 0; i < rsvpUndecided.size() - 1; i++){
        cout << rsvpUndecided.at(i).getName() << " (" << rsvpUndecided.at(i).getAge() << "), " << endl;
    }
    cout << rsvpUndecided.at(rsvpUndecided.size()).getName() << " (" << rsvpUndecided.at(rsvpUndecided.size()).getAge() << ") \n" << endl;
}

// Prints out a list of people that have said they will not go to the event // Mark and Jovanny
void Event::rsvpNo() {
    vector<person> rsvpNo;
    for(unsigned int i = 0; i < invitees.size(); i++){
        if(invitees.at(i).getResponse() == "No"){}
        rsvpNo.push_back(invitees.at(i));
    }

    cout << "The list of people that have responded that they are unable to attend " << eventName << " are: " << endl;
    for( unsigned int i = 0; i < rsvpNo.size() - 1; i++){
        cout << rsvpNo.at(i).getName() << " (" << rsvpNo.at(i).getAge() << "), " << endl;
    }
    cout << rsvpNo.at(rsvpNo.size()).getName() << " (" << rsvpNo.at(rsvpNo.size()).getAge() << ") \n" << endl;
}