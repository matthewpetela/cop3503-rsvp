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
#include "objects.h"

using namespace std;

objects::objects(string name, int amnt){
	this->name=name;
	this->amnt=amnt;
}
void objects::setRegistry(string gift){
	this->name = gift;
}
void objects::setAmount(int qnty){
	this->amnt=qnty;
}
string objects::getRegistry() {return name;}

