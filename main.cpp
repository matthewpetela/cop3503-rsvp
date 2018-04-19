#include <ctime>

/*
main.cpp
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
#include<iostream>
#include<ctime>
#include<vector>
#include"rsvp.h"
#include"person.h"

using namespace std;
void createEvent(){
	cout<<"What is the name of your event?(Ex. Tom's party) "<<endl;
	std::string eventName;						//accepts multiple words for the event name
	std::getline(std::cin, eventName);
	/*
	 * add event to list here
	 */
	cout<<" "<<endl;

	cout<<"What type of event is this?(Ex. party, wedding, etc.) "<<endl;
	std::string eventType;						//accepts multiple words for the event type
	std::getline(std::cin, eventType);
	/*
	 * add type to list, if the event is a wedding ask if they want to add a registry
	 */
	cout<<" "<<endl;

	cout<<"Would you like to create a seating chart? "<<endl;
	cout<<"1. Yes "<<endl;
	cout<<"2. No "<<endl;
	int ynInput;
	cin>>ynInput;
	cin.ignore();
	if(ynInput>2|| ynInput<1) {
		cout<<"Error, enter the number of the option you'd like."<<endl;
	}
	else{
		switch(ynInput){
		case 1:
			//create seating chart
			break;
		case 2:
			break;
		}
	}
	cout<<" "<<endl;

	cout<<"Is there an age requirement? "<<endl;
	cout<<"1. Yes "<<endl;
	cout<<"2. No "<<endl;
	int ynInput2;
	string minAge;
	string maxAge;
	cin>>ynInput2;
	cin.ignore();
	if(ynInput2>2|| ynInput2<1) {
		cout<<"Error, enter the number of the option you'd like."<<endl;
	}
	else{
		switch(ynInput2){
		case 1:
			cout<<"What is the minimum age requirement? If none type NA "<<endl;
			cin>>minAge;
			//seperate code to deal with age
			cout<<"What is the maximum age requirement? If none type NA. "<<endl;
			cin>>maxAge;
			//seperate code for age
			break;
		case 2:
			break;
		}
	}
	cout<<" "<<endl;

	cout<<"Any notes you'd like your guests to know? "<<endl;
	std::string message;
	std::getline(std::cin, message);
	//include the message in details?



}
void userMenu(){
	cout<<"Please select an option below."<<endl;

	cout<<" "<<endl;
	cout<<"1. Creating an event "<<endl;
	cout<<"2. RSVP to an event "<<endl;
	cout<<"3. Details of an event "<<endl;
	cout<<"4. Change response to event "<<endl;
	cout<<"5. Exit system "<<endl;
	cout<<" "<<endl;

	int userInput;
	cin>>userInput;
	cin.ignore();
	if(userInput>5|| userInput<1) {
		cout<<"Error, enter the number of the option you'd like."<<endl;
	}
	else{
		switch(userInput){
		case 1:
			cout<<"Wonderful! To create your event please answer the following questions."<<endl;
			createEvent();
			/*
			* Create the code needed for a new event, then access it here
			* Make sure the questions are simple for the user to answer
			* Try to be as detailed as possible to meet code length requirements :)
			* Also make sure we can access the details inputed for later sections
			* The code can be written in different classes so long as the correct information is displayed
			* Return to menu
			*/
			break;
		case 2:
			cout<<"Awesome! To RSVP to your event please follow the steps below. "<<endl;
			/*
			 * Create the code needed to RSVP to an event, then access it here
			 * Make sure the steps are easy to follow
			 * Return to menu
			 */
			break;
		case 3:
			cout<<"Details are important! Please answer the questions below. "<<endl;
			/*
			 * Display details of an event here including seating, who's going, etc.
			 * Most of the code should exist from other classes so it should just be able to print here
			 * Make sure it's easy to understand for the user
			 * Return to menu
			 */
			break;
		case 4:
			cout<<"No problem! To change your response follow the steps below. "<<endl;
			/*
			 * Create the code needed to change the response of a guest
			 * Try to be as detailed as possible
			 * The code can be written in different classes so long as the correct information is displayed
			 * Return to menu
			 */
			break;

		case 5:
			cout<<"See you later, alligator! "<<endl;
			exit(0);
			break;
		}
	}
}
int main(int argc, char *argv[]){
    vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark

   // std::string event = "Party"; //used for testing
    time_t now = time(0); //used for testing


    cout << "Welcome to the Gator RSVP system!" << endl;
	userMenu();

}

