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
person::person(string name, int age, string response, string obj, bool primary, string table, string gift, string ride) {
    this->name = name;
    this->age = age;
    this->inviteResponse = response;
    this->primary = primary;
    this->seating = table;
    this->registry = gift;
    this->bring = obj;
    this->transport=ride;
}

// Sets the response of the person // Mark
void person::setResponse(string response) {
    this->inviteResponse = response;
}
void person::setSeating(string table){
	this->seating = table;
}
void person::setRegistry(string gift){
	this->registry = gift;
}
void person::setBring(string obj){
	this->bring=obj;
}
void person::setRide(string ride){
	this->transport=ride;
}

// Creates a new person if the primary invitee wants to bring a plus one
// This person is "Going" by default, and they cannot invite another plus one
// Mark
void person::plusOne(string name, int age) {
    person(name, age, "Going", "nothing" , false, "None", "NA", "No");
}

// Returns the name of the person // Mark
string person::getName() { return name;}

// Returns the age of the person // Mark
int person::getAge() { return age;}

// Returns the response of the person // Mark
string person::getResponse() { return inviteResponse;}

string person::getSeating() {return seating;}

string person::getRegistry(){return registry;}

string person::getBring(){return bring;}

string person::getRide(){return transport;}

