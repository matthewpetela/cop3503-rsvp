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
    string eventDate;         // The date of the event in form mm/dd/yyyy
    string eventTime;              // The time of the event
    string location;          // The location of the event

    string dresscode;         // Tells the invitee the dresscode for the event
    int ageMinimum;           // The age restriction for the event

    string message;           // A message for the planner to tell the invitee about the event


public:

    // CONSTRUCTORS //

    // Basic constructor
    Event();

    // Constructor for an event with all elements filled out except for the age minimum and dresscode // Mark and Jovanny
    Event(string eventPlanner, string eventName, string eventType, string eventDate, string eventTime, string eventLocation, string dresscode, string message);

    // Overloaded constructor for an event with all elements filled out // Mark and Jovanny
    Event(string eventPlanner, string eventName, string eventType, string eventDate, string eventTime, string eventLocation, string message);

    // Overloaded Constructor with no elements filled in // Mark and Jovanny
    Event(string eventPlanner);

    // MUTATOR METHODS //

    // Sets the name of the event // Mark and Jovanny
    void setEventName(string eventName);

    // Sets the type of event, we can have a list of event types the event planner can choose from
    // Mark and Jovanny
    void setEventType(string eventType);

    // Sets the date of the event // Mark and Jovanny
    void setEventDate(string eventDate);

    // Sets the time the event will take place // Mark and Jovanny
    void setEventTime(string eventTime);

    // Sets the location where the event will take place // Mark and Jovanny
    void setEventLocation(string eventLocation);

    // Sets the dresscode for the event // Mark and Jovanny
    void setDressCode(string dresscode);

    // Sets the minimum age for the event // Mark and Jovanny
    void setAgeMin(int ageMinimum);

    // Sets the message the event planner wants to send to the invitee // Mark and Jovanny
    void setMessage(string message);

    // Adds the name of a person to the invitee list of people, where they can then respond // Mark and Jovanny
    void sendInvite(string name, int age);


    // ACCESSOR METHODS //

    string getEventPlanner();    // Returns the name of the event planner // Mark and Jovanny
    string getEventName();       // Returns the name of the event // Mark and Jovanny
    string getEventType();       // Returns the type of the event // Mark and Jovanny
    string getEventDate();       // Returns the date of the event // Mark and Jovanny
    string getEventTime();       // Returns the time of the event // Mark and Jovanny
    string getEventLocation();   // Returns the location of the event // Mark and Jovanny
    string getDressCode();       // Returns the event's dresscode // Mark and Jovanny
    int getAgeMin();             // Returns the age minimum // Mark and Jovanny
    string getMessage();         // Returns the message the event planner wants to send to the invite // Mark and Jovanny
    vector<person> getInvitees(); // Returns the list of people invited to the event // Mark and Jovanny



    // PRINT METHODS //

    void rsvpYes();              // Shows the event planner who has indicated that they will attend the event
    void rsvpUndecided();        // Shows the event planner who has indicated that they have not decided if they will attend the event
    void rsvpNo();               // Shows the event planner who has indicated that they will not attend the event
    void printInvite();          // Prints out the information for the invitation
    void setResponse(unsigned int a, string Response);     //method used for setting response of user in case 2
    void setSeating(unsigned int i, string Table);
    void setRegistry(unsigned int i, string gift);
};



