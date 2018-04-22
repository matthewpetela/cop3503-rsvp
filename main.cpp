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
#include<algorithm>
#include<fstream>


vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark
//global variable is needed for access across all methods

using namespace std;

//Jovanny   method for clearing input rather than typing it over and over
void clearInput(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//kimmy and kailee
void registry(){
	int numGifts;
	string gift;
	cout<<"How many gifts are on your registry?"<<endl;
	cin>>numGifts;
	string guestArray[numGifts];
	for(int x = 0; x < numGifts; x++){
		// breakOut = false;
		cout<<"Please enter the name of the gift" << endl;
		std::cin.get();
		getline(std::cin, gift);
		guestArray[x] = gift;
		cout<<endl;
	}
}
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
	//int numGuests;
	int dressOption;
	int eventTypeOp;


	cout<<"What is your name?"<<endl; // used for eventplanner name
	cin.get();
	getline(cin, eventPlanner);
	cout<<" "<<endl;

	cout<<"What is the name of your event?(Ex. Tom's party) "<<endl;
	//cin.get();
	getline(cin, eventName);
	cout<<" "<<endl;

	cout<<"What type of event is this?(Ex. party, wedding, etc.) "<<endl;
	cout<<" "<<endl;
	cout<<"1. Party "<<endl;
	cout<<"2. Wedding "<<endl;
	cout<<"3. Shower (bridal, baby, etc. "<<endl;
	cout<<"4. Other (Please specify) "<<endl;
	cin>>eventTypeOp;

	switch(eventTypeOp){
	case 1:
		eventType= "Party";
		break;
	case 2:
		eventType = "Wedding";
		cout<<"Would you like to create a registry? "<<endl;
		cout<<"1. Yes"<<endl;
		cout<<"2. No"<<endl;
		int ans2;
		cin>>ans2;
		switch(ans2){
		case 1:
			registry();
			break;
		case 2:
			break;
		default:
			break;
		}
		break;
		case 3:
			eventType = "Shower";
			cout<<"Would you like to create a registry? "<<endl;
			cout<<"1. Yes"<<endl;
			cout<<"2. No"<<endl;
			int ans3;
			cin>>ans3;
			switch(ans3){
			case 1:
				registry();
				break;
			case 2:
				break;
			default:
				break;
			}
			break;
			case 4:
				cin.get();
				getline(cin, eventName);
				cout<<" "<<endl;
				break;
			default:
				break;

	}
	cout<<" "<<endl;

	cout<<"What is the time of the event?" << endl;
	cin.get();
	getline(cin, eventTime);
	cout<<" "<<endl;

	//kareem and jovanny
	bool menuBool = true;
	int x = 0;
	char tempChar;
	while(menuBool){
		cout<<"What is the date of the event? (Enter in the form mm/dd/yyyy. Year must be between 2000 and 2199)" <<endl;
		//std::cin.get();
		getline(std::cin, eventDate);	//HAS TO STAY AS GETLINE. IF NOT YOU HAVE TO CLEAR INPUT EVERYTIME ITS BAD INPUT OR YOU GET AN
		//cin>>eventDate;				//INFINITE LOOP - JOVANNY


		if(eventDate.length() != 10){
			cout<<"Wrong input"<<endl;
			cout<<"Please input the date in the correct format"<<endl;

			continue;
		}
		else{
			tempChar = eventDate.at(0);
			x = (int)tempChar - 48;                          //convert character to int for checking. subtract ascii value
			if(isdigit(eventDate.at(0)) == 0 || x > 1){ //checks if the month is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(1);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if((isdigit(eventDate.at(1)))==0 || x > 9){ //checks if the month is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			if(eventDate.at(2)!= '/'||eventDate.at(5)!= '/') {          //checks if the dashes are present in the date
				cout << "Wrong input" << endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(3);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if(isdigit(eventDate.at(3)) == 0 || x > 3 < 0 ){     //checks if the day is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			if(isdigit(eventDate.at(3)) == 0 && (((int)eventDate.at(4)) - 48) > 1){
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(4);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if(isdigit(eventDate.at(4)) == 0 || x > 9){     //checks if the day is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(6);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if(isdigit(eventDate.at(6)) == 0 || x > 2){     //checks if the year is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(7);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if(isdigit(eventDate.at(7)) == 0 || x > 1){     //checks if the year is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(8);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if(isdigit(eventDate.at(8)) == 0 || x > 9){     //checks if the year is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			tempChar = eventDate.at(9);
			x = (int)tempChar - 48;                          //convert character to int for date checking
			if(isdigit(eventDate.at(9)) == 0 || x > 9){     //checks if the year is digits
				cout<<"wrong input"<<endl;
				cout<<"Please input the date in the correct format"<<endl;
				continue;
			}

			menuBool = false;
		}

	}
	cout<<" "<<endl;

	cout<<"Where will this event be held?" << endl;
	cin.get();
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
			cin.get();
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
		cin.get();
		getline(cin, message);
		cout<<endl;
		break;
	case 2:
		message = "N/A";
		break;
	default:
		cout<<"Please enter either 1 or 2"<<endl;
		clearInput();
	}


	//include the message in details?

	//creates the event based on whatever inputs the user givse
	eventCreator.emplace_back(eventPlanner, eventName, eventType,eventDate, eventTime, eventLocation, dressCode , message);     //jovanny and mark emplace back is equivalent to push back
	cout<<" "<<endl;
	cout<< eventPlanner<< " " << eventName << " " << eventType <<endl;
	cout<< eventLocation<< " " << eventTime << " "<< eventDate <<endl;			//statement for erro checking
	cout<< dressCode<<endl;
	cout<< message<<endl; //used for error checking in dress code
	cout<<" "<<endl;

	//while loop used to create guests
	bool menu = true;
	bool breakOut;          // bool to check if you broke out of the for loop due to a bad age string
	bool menu2 = true;
	char addGuest = 'z';

	/* //kailee
    cout<<"How many guests would you like to invite?"<<endl;
    cin>>numGuests;
    string guestArray[numGuests];
    for(int x = 0; x < numGuests; x++){
           // breakOut = false;
            cout<<"Please enter the name of the guest you would like to add to your invite list" << endl;
            std::cin.get();
            getline(std::cin, guestName);
            guestArray[x] = guestName;
            cout<<endl;*/

	/*cout<<"Please enter the name of the guest you would like to add to your invite list" << endl;
			cin.get();
			getline(cin, guestName);
			cout<<endl;*/
	// guestArray[x] = guestName;

			/*I thought it made more sense to ask the guest their age rather than the event creator so I just commented out the code to copy later
			 * I made a more simple loop for the names, since the age doesn't matter yet
			 * It also fixed an issue of not letting the someone enter the second guest's name before asking if they wanted to add another guest
			 * I was hoping to make it more user friendly
			 */

	while(menu){
		breakOut = false;
		//kimmy I had to turn it into two parts so it saves all letters correctly but the string is still saved under the same name
		//I also put the old code for the section above the while loop so its all together
		string firstInvite;
		string lastInvite;

		cout<<"Please Enter the first name of your guest."<<endl;
		cin>>firstInvite;
		cout<<endl;

		cout<<"Please enter the last name of your guest."<<endl;
		cin>>lastInvite;
		cout<<endl;

		guestName = firstInvite +" "+ lastInvite;

		cout<< guestName <<endl;

		cout<<"Please enter the guest's age (numbers only)"<<endl;
		cin>>age;
		cout<<endl;
		for(unsigned int a = 0; a < age.size(); a++){   //for loop to check if the age string contains numbers only
			if(isdigit(age.at(a)) == 0){                //isdigit returns 0 when it is false
				breakOut = true;
				cout<< "Error: "<< guestName << " Was not added to your guest list"<<endl;
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
		cout<< guestName << " " << age << "\n";      //used for testing purposes


		if(breakOut){   // if we brokeout of the for loop due to bad age, the while loop is continued
			continue;   // and the user is not prompted about adding another person
		}

		//while loop to check if user wants to add another guest
		menu2 = true;
		while(menu2){
			cout<<"Would you like to add another guest? (hit Y for yes or N for no)"<<endl;
			cin>>addGuest;
			clearInput();
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
				clearInput();
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
		default:
			break;
		}
	}
	cout<<" "<<endl;




}


//jovanny
void rsvpSystem(){
	string tempEventName;
	string tempRsvpName;
	bool inEvent = false;
	bool menu = true;
	char menuOption = 'z';
	vector<person> tempPeople;          //POSSIBILY USE POINTERS HERE FOR BETTER MEMORY MANAGEMENT

	cout<<"Please enter your name"<< endl;
	cin.get();
	getline(cin, tempRsvpName);
	tempRsvpName.erase(remove(tempRsvpName.begin(), tempRsvpName.end(), ' '), tempRsvpName.end()); //removes whitespace for comparison
	transform(tempRsvpName.begin(),tempRsvpName.end(), tempRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison
	cout<< tempRsvpName <<endl;         // test to make sure input user name has no spaces

	
	for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
		tempPeople = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
		for(unsigned int a = 0; a < tempPeople.size(); a++){        //for loop to iterate through all the people in the event
			tempEventName = tempPeople[a].getName();
			tempEventName.erase(remove(tempEventName.begin(), tempEventName.end(), ' '), tempEventName.end()); //removes whitespace for comparison
			transform(tempEventName.begin(),tempEventName.end(), tempEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
			if(tempEventName == tempRsvpName){
				inEvent = true;                                     //bool to let user know whether they re in an event or not
				eventCreator[i].printInvite();                      //prints the invitation to the event

				menu = true;
				while(menu){                                        //while loop to check if user is attending the event
					cout<<"Will you be attending this event? (hit Y for yes or N for no)"<<endl;
					cin>>menuOption;
					clearInput();
					switch(toupper(menuOption)){
					case 'Y':
					eventCreator[i].setResponse(a,"Yes");
					cout<<"Thank you for response!"<<endl;
					menu = false;
					break;
					case 'N':
						eventCreator[i].setResponse(a,"No");
						cout<<"Thank you for response!"<< "\n"<<endl;
						menu = false;
						break;
					default:
						cout<<"Please enter either Y or N"<<endl;
						clearInput();
						continue;

					}
				}
			}
		}
	}
	if(!inEvent){
		cout<<"Unfortunately you have not been invited to any events."<<endl;
	}
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

			break;
		case 2:
			cout<<"Awesome! To RSVP to your event please follow the steps below. "<<endl;
			 rsvpSystem();   //calls rsvp method
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

void loadFile(){//Opens saved file. ***IMPORTANT*** Must modify when adding person or event variables/traits - Matt
    std::string DATA_FILE_NAME = "data.txt";
    std::string PERSON_FILE_NAME = "person.txt";
    vector<std::string> dataFileVector;
    ofstream dataFile;
    dataFile.open (DATA_FILE_NAME);

   // for( std::string line; getline( input, line ); ){


   // }


    dataFile.close();

}

void saveFile(){ //saves to file. ***IMPORTANT*** Must modify when adding person or event variables/traits - Matt
    int size = eventCreator.size(); //Gets the number of events
    std::string DATA_FILE_NAME = "data.txt";
    std::string PERSON_FILE_NAME = "person.txt"; //used later to transfer over guests
    ofstream dataFile(DATA_FILE_NAME);


    for (int i= 0 ; i < size; i++){ //writes to file with new line seperation
    dataFile << eventCreator.at(i).getEventPlanner() << "\n" << eventCreator.at(i).getEventName() << "\n" << eventCreator.at(i).getEventType() << "\n" << eventCreator.at(i).getEventLocation() << "\n" <<
    eventCreator.at(i).getEventDate() << eventCreator.at(i).getEventTime() <<"\n" << eventCreator.at(i).getDressCode() << "\n" << eventCreator.at(i).getAgeMin()<< "\n";

    }

    dataFile.close();

}
int main(int argc, char *argv[]){
    vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark

   time_t now = time(0); //used for testing


    cout << "Welcome to the Gator RSVP system!!!!!" << endl;
	userMenu();

}
