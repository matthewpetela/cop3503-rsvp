/*
rsvp.h
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

#include <vector>
#include "person.h"

using namespace std;

class Event{

private:

    vector<person> invitees;     // A list of all the people invited by the host.
    // A person can log into the program and check to see if there name has been added to an invite list,
    // Where they can then reply as to whether they are going or not, etc.

    string eventPlanner;      // The name of the person organizing the event
    string eventName;         // The name of the event
    string eventType;         // The type of the event
    string location;          // The location of the event
    string time;              // The time of the event


public:

    // Basic constructor
    Event();

    // Constructor for an event with all elements filled out // Mark and Jovanny
    Event(string eventName, string eventType, string eventTime, string eventLocation);

    // Sets the name of the event // Mark and Jovanny
    void setEventName(string eventName);

    // Sets the type of event, we can have a list of event types the event planner can choose from
// Mark and Jovanny
    void setEventType(string eventType);

    // Sets the time the event will take place // Mark and Jovanny
    void setEventTime(string time);

    // Sets the location where the event will take place // Mark and Jovanny
    void setEventLocation(string eventLocation);

    string getEventName();       // Returns the name of the event // Mark and Jovanny
    string getEventType();       // Returns the type of the event // Mark and Jovanny
    string getEventLocation();   // Returns the location of the event // Mark and Jovanny
    string getEventTime();       // Returns the time of the event // Mark and Jovanny

    void sendInvite(string name, int age);       // Adds the name of a person to the invitee list of people, where they can then respond
    void rsvpYes();                              // Shows the event planner who has indicated that they will attend the event
    void rsvpUndecided();                        // Shows the event planner who has indicated that they have not decided if they will attend the event
    void rsvpNo();                               // Shows the event planner who has indicated that they will not attend the event

};