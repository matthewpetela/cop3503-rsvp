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
#include<limits>

using namespace std;
void createEvent(int i){                    //int i is used to tell which event we are currently creating.
                                            // this is used for adding people to the current event
    string eventName;
    string eventType;						//accepts multiple words for the event type
    string eventTime;                       //used for event date       //jovanny and mark
    string eventLocation;                   //used for event location
    string guestName;                       // used to guest creation
    string age;                                // used for guest creation


    vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark

    cout<<"What is the name of your event?(Ex. Tom's party) "<<endl;     //accepts multiple words for the event name
    cin.ignore();
    getline(cin, eventName);
	cout<<" "<<endl;

	cout<<"What type of event is this?(Ex. party, wedding, etc.) "<<endl;
    getline(cin, eventType);
	cout<<" "<<endl;

    cout<<"What is the time of the event?" << endl;        //jovanny and mark
    getline(cin, eventTime);
    cout<<endl;

    cout<<"What is the date of the event? (enter in the form mm/dd/yyyy)" <<endl;
    /*
     * error checking needs to be done in this section to make sure it is in correct format
     * possibly use substrings to analyze that everything is in proper format
     */

    cout<<endl;

    cout<<"Where will this event be held?" << endl;         //jovanny and mark
    getline(cin, eventLocation);
    cout<<endl;

    //creates the event based on whatever inputs the user givse
    eventCreator.emplace_back(eventName, eventType, eventTime, eventLocation);     //jovanny and mark emplace back is equivalent to push back
    cout<<eventName << " " << eventType << " " << eventLocation << " " << eventTime <<endl;  //statement for erro checking


    //while loop used to create guests
    bool menu = true;
    bool breakOut;          // bool to check if you broke out of the for loop due to a bad age string
    bool menu2 = true;
    char addGuest = 'z';

    while(menu){
        breakOut = false;
        cout<<"Please enter the name of the guest you would like to add to your invite list" << endl;
        getline(cin, guestName);
        cout<<endl;

        cout<<"Please enter the guest's age (numbers only)"<<endl;
        getline(cin, age);
        cout<<endl;

        for(unsigned int a = 0; a < age.size(); a++){   //for loop to check if the age string contains numbers only
            if(isdigit(age.at(a)) == 0){                //isdigit returns 0 when it is false
            breakOut = true;
            cout<<"Please enter numbers only"<<endl;
                cout<< "\n";
            break;                                      //if a character isnt a number, we break out of the for loop
            }
            else{
                if(a == (age.size()  - 1)){             // if you reach the end of the age string and everything is a number you create a person
                    cout<< guestName << " was added successfully to your guest list!"<<endl;
                    eventCreator[i].sendInvite(guestName, stoi(age));
                }
            }
        }
        cout<<guestName << " " << age << "\n";      //used for testing purposes


        if(breakOut){   // if we brokeout of the for loop due to bad age, the while loop is continued
            continue;   // and the user is not prompted about adding another person
        }


          //while loop to check if user wants to add another guest

        while(menu2){
            cout<<"Would you like to add another guest? (hit Y for yes or N for no)"<<endl;
            cin>>addGuest;
           // toupper(addGuest);
            switch(toupper(addGuest)){
                case 'Y':
                    menu = true;
                    menu2 = false;
                    break;
                case 'N':
                    menu = false;
                    menu2 = false;
                    break;
                default:
                    menu2 = true;
                    cout<<"Please enter either Y or N"<<endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }


    }








//SEATING CHART SECTION
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



//DRESS CODE SECTION

    cout<<"Is there a dress code? "<<endl;
    cout<<"1. Yes "<<endl;
    cout<<"2. No "<<endl;
    int ynInput3;
    cin>>ynInput3;
    std::string eventDress;
    cin.ignore();
    if(ynInput3>2|| ynInput3<1) {
        cout<<"Error, enter the number of the option you'd like."<<endl;
    }
    else{
        switch(ynInput3){
            case 1:
                cout<<"Enter the dresscode. (Ex. casual, professional, etc.) "<<endl;
                std::getline(std::cin, eventDress);
                /*
                 * add dresscode to list
                 */
                break;
            case 2:
                break;
        }
    }
    cout<<" "<<endl;





    //AGE REQUIREMENT SECTION

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




    //EXTRA NOTES SECTION


	cout<<"Any notes you'd like your guests to know? "<<endl;
	std::string message;
	std::getline(std::cin, message);
	//include the message in details?



}


//jovanny and mark
void rsvpSystem(){




}



void userMenu(){
    int userInput;
    int i = 0;   // int tht is sent to create event class. used to tell which event we are currently creating

    //jovanny and mark
    while(true){        //while statement will continue to display the menu until a correct option is chosen
        cout<<"1. Creating an event "<<endl;
        cout<<"2. RSVP to an event "<<endl;
        cout<<"3. Details of an event "<<endl;
        cout<<"4. Change response to event "<<endl;
        cout<<"5. Exit system "<<endl;
        cin>>userInput;

		switch(userInput){
		case 1:
			cout<<"Wonderful! To create your event please answer the following questions."<<endl;
			createEvent(i);
            i++;    //after creating the event, i is incremented to be ready for the use in the next event
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

        default:                // clears all input a user puts in and continues the loop //jovanny and mark
            cout<<"Error, enter the number of the option you'd like."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
		}
	}
}
int main(int argc, char *argv[]){
    vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark

   time_t now = time(0); //used for testing


    cout << "Welcome to the Gator RSVP system!" << endl;
	userMenu();

}

