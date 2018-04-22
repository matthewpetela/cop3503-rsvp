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

// CONSTRUCTORS //

// Basic Constructor for an event with all elements filled out except for the dresscode and age limit // Mark and Jovanny
Event::Event(string eventPlanner, string eventName, string eventType, string eventDate, string eventTime, string eventLocation, string message) {
    this->eventPlanner = eventPlanner;
    this->eventName = eventName;
    this->eventType = eventType;
    this->eventDate = eventDate;
    this->eventTime = eventTime;
    this->location = eventLocation;
    this->dresscode = "";
    this->ageMinimum = 0;
    this->message = message;
}

// Overloaded Constructor for an event with all elements filled out except for the dresscode and age limit // Mark and Jovanny
Event::Event(string eventPlanner, string eventName, string eventType, string eventDate, string eventTime, string eventLocation, string dresscode, string message) {
    this->eventPlanner = eventPlanner;
    this->eventName = eventName;
    this->eventType = eventType;
    this->eventDate = eventDate;
    this->eventTime = eventTime;
    this->location = eventLocation;
    this->dresscode = dresscode;
  //  this->ageMinimum = ageMin;
    this->message = message;
}

// Overloaded Constructor with no elements filled in // Mark and Jovanny
Event::Event(string eventPlanner) {
    this->eventPlanner = eventPlanner;
    this->eventName = "";
    this->eventType = "";
    this->eventDate = "";
    this->eventTime = "";
    this->location = "";
    this->dresscode = "";
    this->ageMinimum = 0;
    this->message = "";
}

// MUTATOR METHODS //
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

// Sets the date of the event // Mark and Jovanny
void Event::setEventDate(string eventDate){
    this->eventDate = eventDate;
}

// Sets the time the event will take place // Mark and Jovanny
void Event::setEventTime(string eventTime){
    this->eventTime = eventTime;
}

// Sets the location where the event will take place // Mark and Jovanny
void Event::setEventLocation(string eventLocation){
    this->location = eventLocation;
}

// Sets the dresscode for the event // Mark and Jovanny
void Event::setDressCode(string dresscode){
    this->dresscode = dresscode;
}

// Sets the minimum age for the event // Mark and Jovanny
void Event::setAgeMin(int ageMinimum){
    this->ageMinimum = ageMinimum;
}

// Sets the message the event planner wants to send to the invitee
void Event::setMessage(string message){
    this->message = message;
}

// Creates a person with a name and an age, sets their decision to Undecided
// and says that they are the primary invitee, rather than a plus one
// This person is that added to a vector of all the people invited to the event //Mark and Jovanny
void Event::sendInvite(string name, int age) {
    invitees.emplace_back(person(name, age, "Undecided", true));
}

// ACCESSOR METHODS //

// Returns the name of the event planner // Mark and Jovanny
string Event::getEventPlanner() { return eventPlanner; }

// Returns the name of the event // Mark and Jovanny
string Event::getEventName() { return eventName;}

// Returns the type of the event // Mark and Jovanny
string Event::getEventType() { return eventType;}

// Returns the location of the event // Mark and Jovanny
string Event::getEventLocation() { return location;}

// Returns the date of the event // Mark and Jovanny
string Event::getEventDate() { return eventDate;}

// Returns the time of the event // Mark and Jovanny
string Event::getEventTime() { return eventTime;}

// Returns the event's dresscode // Mark and Jovanny
string Event::getDressCode(){ return dresscode; }

// Returns the age minimum // Mark and Jovanny
int Event::getAgeMin(){ return ageMinimum; }

// Returns the message the event planner wants to send to the invite // Mark and Jovanny
string Event::getMessage() { return message; }

// Returns the list of people invited to the event // Mark and Jovanny
vector<person> Event::getInvitees() { return invitees; }
//method used to set response in case 2 Jovanny
void Event::setResponse(unsigned int a, string Response) {
    invitees.at(a).setResponse(Response);
}


// PRINT METHODS //

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

// Prints out the information for the invitation
void Event::printInvite() {
    cout << "You were invited to " << eventPlanner << "'s " << eventType << "!" << endl;
    cout << eventName << ": " << endl;
    cout << "When: " << eventDate << " at " << eventTime << endl;
    cout << "Where: " << location << endl;
    cout << "Dresscode: " << dresscode << endl;
    cout << "Notes: " << message << endl;
   // if (ageMinimum != 0)
    //    cout << "Age Limit: " << ageMinimum << " or older" << endl;


}