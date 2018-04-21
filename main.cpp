
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

//kimmy
void createEvent(int i){                    //int i is used to tell which event we are currently creating.Kimmy
                                            // this is used for adding people to the current event
    string eventPlanner;
    string eventName;
    string eventType;						//accepts multiple words for the event type
    string eventTime;                       //used for event date       //jovanny and mark
    string eventLocation;                   //used for event location
    string message;
    string dressCode;
    string eventDate;
    string guestName;                       // used to guest creation
    string age;                                // used for guest creation
    int numGuests;
    int dressOption;

    vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark

    cout<<"What is your name?\n"<<endl; // used for eventplanner name
    std::cin.get();
    getline(std::cin, eventPlanner);
    cout<<" "<<endl;

    cout<<"What is the name of your event?(Ex. Tom's party) "<<endl;
   // cin.ignore();
    getline(cin, eventName);
    cout<<" "<<endl;

	cout<<"What type of event is this?(Ex. party, wedding, etc.) "<<endl;
    getline(cin, eventType);
    cout<<" "<<endl;

    cout<<"What is the time of the event?" << endl;
    getline(cin, eventTime);
    cout<<" "<<endl;

    cout<<"What is the date of the event? (Enter in the form mm/dd/yyyy)" <<endl;
    getline(cin, eventDate);
    /*
     * error checking needs to be done in this section to make sure it is in correct format
     * possibly use substrings to analyze that everything is in proper format
     */
    cout<<" "<<endl;

    cout<<"Where will this event be held?" << endl;
    getline(cin, eventLocation);
    cout<<" "<<endl;

    //jovanny  // loop to make sure a dress code is picked
    bool dressBool = true;
    while(dressBool){
    	cout<<"Please select the dresscode for this event?" <<endl;
    	cout<<"1. Casual "<<endl;
    	cout<<"2. Business casual "<<endl;
    	cout<<"3. Business formal "<<endl;
    	cout<<"4. Semi-formal "<<endl;
    	cout<<"5. Formal "<<endl;
    	cout<<"6. Other (please specify)"<<endl;
    	cin>>dressOption;
    	switch(dressOption){
    	case 1:
    		dressCode = "Casual";
    		dressBool = false;
    		break;
    	case 2:
    		dressCode = "Business casual";
    		dressBool = false;
    		break;
    	case 3:
    		dressCode = "Business formal";
    		dressBool = false;
    		break;
    	case 4:
    		dressCode = "Semi-formal";
    		dressBool = false;
    		break;
    	case 5:
    		dressCode = "Formal";
    		dressBool = false;
    		break;
    	case 6:
    		cout<<"Please specify your dress Code" <<endl;
    		//cin.ignore();
    		getline(cin, dressCode);
    		dressBool = false;
    		break;
    	default:
    		cout<<"Error, enter the number of the option you'd like."<<endl;
    		cin.clear();
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		continue;

    	}

    }

    cout<<"Any notes you'd like your guests to know?"<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No" <<endl;
    int choice = 0;
    cin>>choice;
     switch(choice){
         case 1:
            cout<<"Type your message."<<endl;
            getline(cin, message);
            cout<<endl;
             break;
         case 2:
             break;
         default:
             cout<<"Please enter either Y or N"<<endl;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
     }


    //include the message in details?

    //creates the event based on whatever inputs the user givse
    eventCreator.emplace_back(eventPlanner, eventName, eventType,eventDate, eventTime, eventLocation, dressCode , message);     //jovanny and mark emplace back is equivalent to push back
    cout<< eventName << " " << eventType << " " << eventLocation << " " << eventTime << " "<< eventDate << " "<< eventPlanner<< " " << message;  //statement for erro checking
    cout<<dressCode<<endl;    //used for error checking in dress code


    //while loop used to create guests
   // bool menu = true;
   // bool breakOut;          // bool to check if you broke out of the for loop due to a bad age string
    //bool menu2 = true;
   // char addGuest = 'z';

    //kailee
    cout<<"How many guests would you like to invite?"<<endl;
    cin>>numGuests;
    string guestArray[numGuests];
    for(int x = 0; x < numGuests; x++){
           // breakOut = false;
            cout<<"Please enter the name of the guest you would like to add to your invite list" << endl;
            std::cin.get();
            getline(std::cin, guestName);
            guestArray[x] = guestName;
            cout<<endl;

            /*I thought it made more sense to ask the guest their age rather than the event creator so I just commented out the code to copy later
             * I made a more simple loop for the names, since the age doesn't matter yet
             * It also fixed an issue of not letting the someone enter the second guest's name before asking if they wanted to add another guest
             * I was hoping to make it more user friendly
             */

         /*   cout<<"Please enter the guest's age (numbers only)"<<endl;
            getline(cin, age);
            cout<<endl;

            for(unsigned int a = 0; a < age.size(); a++){   //for loop to check if the age string contains numbers only
                if(isdigit(age.at(a)) == 0){                //isdigit returns 0 when it is false
                breakOut = true;
                cout<<"Please enter numbers only"<<endl;
                    cout<< "\n";
                break;                                      //if a character isn't a number, we break out of the for loop
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
            }*/

              //while loop to check if user wants to add another guest

            /*while(menu2){
                cout<<"Would you like to add another guest? (hit Y for yes or N for no)"<<endl;
                cin>>addGuest;
                switch(toupper(addGuest)){
                    case 'Y':   //
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
            }*/
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




}


//jovanny and mark
void rsvpSystem(){




}


void userMenu(){
    int userInput;
    int i = 0;   // int tht is sent to create event class. used to tell which event we are currently creating

    //jovanny and mark
    while(true){        //while statement will continue to display the menu until a correct option is chosen

    	//kimmy
    	cout<<"Please select an option. "<<endl;
    	cout<<" "<<endl;
        cout<<"1. Creating an event "<<endl;
        cout<<"2. RSVP to an event "<<endl;
        cout<<"3. Details of an event "<<endl;
        cout<<"4. Change response to event "<<endl;
        cout<<"5. Exit system "<<endl;
        cin>>userInput;

        //kimmy
		switch(userInput){
		case 1:
			// Kareem
			int i =1;
			char cont;
			do{
				cout<<"Wonderful! To create your event please answer the following questions."<<endl;
				createEvent(i);
				i++;
				do
				{
					cout << "Do you want to create another event (Y/N)" << endl;
					cin >> cont;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

				} while(cont != 'y' && cont != 'Y' && cont != 'N' && cont != 'n');

			} while(cont == 'y' || cont == 'Y');
			//after creating the event, i is incremented to be ready for the use in the next event
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


    cout << "Welcome to the Gator RSVP system!!!!!" << endl;
	userMenu();

}
