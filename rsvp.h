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

    string eventName;
    string eventType;
    string location;          // The location of the event
    string time;              // The time of the event


public:

    Event();

    Event(string eventName, string eventType, string eventTime, string eventLocation);

    void setEventName(string eventName);

    void setEventType(string eventType);

    void setEventTime(string time);

    void setEventLocation(string eventLocation);

    string getEventName();
    string getEventType();
    string getEventLocation();
    string getEventTime();

    void sendInvite(string name, int age);       // Adds the name of a person to the invitee list of people, where they can then respond
    void rsvpYes();          // Shows the event planner who has indicated that they will attend the event
    void rsvpUndecided();        // Shows the event planner who has indicated that they have not decided if they will attend the event
    void rsvpNo();           // Shows the event planner who has indicated that they will not attend the event

};