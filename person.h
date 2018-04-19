//
// Project_Team 18 includes Kareem Joudeh, Nicholas Perret, Matthew Petela, Kailee Ringrose, Kimberly Spencer, Jovanny Vera, and Mark Wagner.
//

#ifndef GROUP_PROGRAM_PERSON_H
#define GROUP_PROGRAM_PERSON_H

#include <iostream>
#include <string>

using namespace std;

class person{

private:

    string name;               // The name of the person, can be used to see if this person has been invited to any events
    int age;                   // Useful for Aged seating / If they can drink at the event, etc
    string inviteResponse;     // Going, Not Going, or undecided
    bool primary;              // Yes for if the person is the primary person invited, false for if the person is the plus one

public:

    person(string name, int age, string response, bool primary);  // Basic Constructor for a person with no plus one

    void setResponse(string response);
    void plusOne(string name, int age);

    string getName();       // Returns the name of the person
    int getAge();           // Returns the age of the person
    string getResponse();   // Returns the response of the person

};

#endif //GROUP_PROGRAM_PERSON_H
