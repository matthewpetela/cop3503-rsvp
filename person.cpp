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

#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

// Basic constructor for the person object, each person has a name, an age, a reponse that is
// "Undecided" by default, and if the person is the primary person being invited, they can bring a plus one
// Mark
person::person(string name, int age, string response, bool primary) {
    this->name = name;
    this->age = age;
    this->inviteResponse = response;
    this->primary = primary;
}

// Sets the response of the person // Mark
void person::setResponse(string response) {
    this->inviteResponse = response;
}

// Creates a new person if the primary invitee wants to bring a plus one
// This person is "Going" by default, and they cannot invite another plus one
// Mark
void person::plusOne(string name, int age) {
    person(name, age, "Going", false);
}

// Returns the name of the person // Mark
string person::getName() { return name;}

// Returns the age of the person // Mark
int person::getAge() { return age;}

// Returns the response of the person // Mark
string person::getResponse() { return inviteResponse;}