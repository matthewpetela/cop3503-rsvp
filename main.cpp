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
#include<regex>


vector<Event> eventCreator;  // create a vector of events for easy addition and checking what people are going to an event Jovanny/Mark
//global variable is needed for access across all methods

using namespace std;

//Jovanny   method for clearing input rather than typing it over and over
void clearInput(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Kailee and kimmy
void seatingSystem(){
    string tEventName;
    string tRsvpName;
    bool inEvent = false;
    bool menu = true;
    bool addSeat = true;
    char menuOption1 = 'z';
    vector<person> tempTable;          //POSSIBILY USE POINTERS HERE FOR BETTER MEMORY MANAGEMENT
    //cout<<"To exit type x."<<endl;

    while(addSeat != false){
        cout<<"Would you like to assign a new guest to a table? (Y/N)"<<endl;
        char ans4;
        cin>>ans4;
        clearInput();
        if(ans4 == 'y' || ans4 == 'Y'){
            cout<<"Please enter the guest you'd like to seat."<< endl;
            getline(cin, tRsvpName);
            tRsvpName.erase(remove(tRsvpName.begin(), tRsvpName.end(), ' '), tRsvpName.end()); //removes whitespace for comparison
            transform(tRsvpName.begin(),tRsvpName.end(), tRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison
            cout<< tRsvpName <<endl;         // test to make sure input user name has no spaces


            for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
                tempTable = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
                for(unsigned int a = 0; a < tempTable.size(); a++){        //for loop to iterate through all the people in the event
                    tEventName = tempTable[a].getName();
                    tEventName.erase(remove(tEventName.begin(), tEventName.end(), ' '), tEventName.end()); //removes whitespace for comparison
                    transform(tEventName.begin(),tEventName.end(), tEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
                    if(tEventName == tRsvpName){
                        inEvent = true;                                     //bool to let user know whether they re in an event or not
                        //eventCreator[i].printSeating();                      //prints the invitation to the event

                        menu = true;
                        while(menu){                                        //while loop to check if user is attending the event
                            cout<<"Where would you like them to sit?"<<endl;
                            cout<<"Table 1,2,3, or 4?"<<endl;
                            cin>>menuOption1;
                            clearInput();
                            switch(toupper(menuOption1)){
                                case '1':
                                    eventCreator[i].setSeating(i,"Table 1");
                                    cout<<"It's been recorded"<<endl;
                                    menu = false;
                                    break;
                                case '2':
                                    eventCreator[i].setSeating(i,"Table 2");
                                    cout<<"It's been recorded"<< "\n"<<endl;
                                    menu = false;
                                    break;
                                case '3':
                                    eventCreator[i].setSeating(i,"Table 3");
                                    cout<<"It's been recorded"<<endl;
                                    menu = false;
                                    break;
                                case '4':
                                    eventCreator[i].setSeating(i,"Table 4");
                                    cout<<"It's been recorded"<< "\n"<<endl;
                                    menu = false;
                                    break;
                                default:
                                    cout<<"Please enter an option 1-4."<<endl;
                                    continue;

                            }
                        }
                    }
                }
            }
            if(!inEvent){
                cout<<"Error they were not on the list of invites"<<endl;
            }
        }
        else if (ans4 == 'N' || ans4 == 'n'){
            addSeat=false;
        }
        else{
            cout<<"invalid input."<<endl;
            clearInput();
            continue;
        }
    }
}

void ride(string tempRsvpName){
    string tempEventName;

    bool inEvent = false;
    bool menu = true;
    char menuOption = 'z';
    string trans;
    vector<person> tempPeople;          //POSSIBILY USE POINTERS HERE FOR BETTER MEMORY MANAGEMENT

    /*cout<<"Please enter your name"<< endl;
    getline(cin, tempRsvpName);
    */
    tempRsvpName.erase(remove(tempRsvpName.begin(), tempRsvpName.end(), ' '), tempRsvpName.end()); //removes whitespace for comparison
    transform(tempRsvpName.begin(),tempRsvpName.end(), tempRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison



    for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
        tempPeople = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
        for(unsigned int a = 0; a < tempPeople.size(); a++){        //for loop to iterate through all the people in the event
            tempEventName = tempPeople[a].getName();
            tempEventName.erase(remove(tempEventName.begin(), tempEventName.end(), ' '), tempEventName.end()); //removes whitespace for comparison
            transform(tempEventName.begin(),tempEventName.end(), tempEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
            if(tempEventName == tempRsvpName){
                inEvent = true;                                     //bool to let user know whether they re in an event or not
                menu = true;
                while(menu){                                        //while loop to check if user is attending the event
                    cout<<"Will you need a ride to the event? (hit Y for yes or N for no)"<<endl;
                    cin>>menuOption;
                    clearInput();
                    switch(toupper(menuOption)){
                        case 'Y':

                            eventCreator[i].setRide(i,"Yes");
                            cout<<"Thank you for response!"<<endl;
                            menu = false;
                            break;
                        case 'N':
                            eventCreator[i].setRide(i,"No");
                            cout<<"Thank you for response!"<< "\n"<<endl;
                            menu = false;
                            break;
                        default:
                            cout<<"Please enter either Y or N"<<endl;
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
void bringItem(string tempRsvpName){
    string tempEventName;
    bool inEvent = false;
    bool menu = true;
    char menuOption = 'z';
    string item;
    vector<person> tempPeople;          //POSSIBILY USE POINTERS HERE FOR BETTER MEMORY MANAGEMENT

   /* cout<<"Please enter your name"<< endl;
    getline(cin, tempRsvpName);
    */
    tempRsvpName.erase(remove(tempRsvpName.begin(), tempRsvpName.end(), ' '), tempRsvpName.end()); //removes whitespace for comparison
    transform(tempRsvpName.begin(),tempRsvpName.end(), tempRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison

    for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
        tempPeople = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
        for(unsigned int a = 0; a < tempPeople.size(); a++){        //for loop to iterate through all the people in the event
            tempEventName = tempPeople[a].getName();
            tempEventName.erase(remove(tempEventName.begin(), tempEventName.end(), ' '), tempEventName.end()); //removes whitespace for comparison
            transform(tempEventName.begin(),tempEventName.end(), tempEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
            if(tempEventName == tempRsvpName){
                inEvent = true;                                     //bool to let user know whether they re in an event or not
                //eventCreator[i].printInvite();                      //prints the invitation to the event

                menu = true;
                while(menu){                                        //while loop to check if user is attending the event
                    cout<<"Will you be bringing anything to this event? (hit Y for yes or N for no)"<<endl;
                    cin>>menuOption;
                    clearInput();
                    switch(toupper(menuOption)){
                        case 'Y':
                            cout<<"What are you bringing?"<<endl;
                            getline(cin, item);
                            eventCreator[i].setBring(i,item);
                            cout<<"Thank you for response!"<<endl;

                            menu = false;
                            break;
                        case 'N':
                            eventCreator[i].setBring(i,"Nothing");
                            cout<<"Thank you for response!"<< "\n"<<endl;
                            menu = false;
                            break;
                        default:
                            cout<<"Please enter either Y or N"<<endl;
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

//kimmy and kailee
void registry(){
    string tEventName;
    string tRsvpName;
    bool inEvent = false;
    bool menu = true;
    bool addItem = true;
    char menuOption1 = 'z';
    vector<person> tempTable;          //POSSIBILY USE POINTERS HERE FOR BETTER MEMORY MANAGEMENT
    //cout<<"To exit type x."<<endl;
    cout<<"Time to make your registry!"<<endl;
    cout<<""<<endl;
    while(addItem != false){
        cout<<"Would you like to assign a new guest to an item? (Y/N)"<<endl;
        char ans4;
        cin>>ans4;
        clearInput();
        if(ans4 == 'y' || ans4 =='Y'){
            cout<<"Please enter the guest's name."<< endl;
            getline(cin, tRsvpName);
            tRsvpName.erase(remove(tRsvpName.begin(), tRsvpName.end(), ' '), tRsvpName.end()); //removes whitespace for comparison
            transform(tRsvpName.begin(),tRsvpName.end(), tRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison
            cout<< tRsvpName <<endl;         // test to make sure input user name has no spaces


            for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
                tempTable = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
                for(unsigned int a = 0; a < tempTable.size(); a++){        //for loop to iterate through all the people in the event
                    tEventName = tempTable[a].getName();
                    tEventName.erase(remove(tEventName.begin(), tEventName.end(), ' '), tEventName.end()); //removes whitespace for comparison
                    transform(tEventName.begin(),tEventName.end(), tEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
                    if(tEventName == tRsvpName){
                        inEvent = true;                                     //bool to let user know whether they re in an event or not
                        //eventCreator[i].printSeating();                      //prints the invitation to the event

                        menu = true;
                        while(menu){
                            cout<<"What would you like the gift to be."<<endl;
                            string gifts;
                            getline(cin, gifts);
                            eventCreator[i].setRegistry(i, gifts);

                            menu = false;
                        }
                    }
                }
            }
            if(!inEvent){
                cout<<"Error they were not on the list of invites"<<endl;
            }
        }
        else if (ans4 == 'n' || ans4 == 'N'){
            addItem=false;
        }
        else{
            cout<<"invalid input."<<endl;
            continue;
        }
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
    getline(cin, eventPlanner);
    cout<<" "<<endl;

    cout<<"What is the name of your event?(Ex. Tom's party) "<<endl;
    getline(cin, eventName);
    cout<<" "<<endl;

    //type
    bool typeError;
    bool registryTrue = false;
    do {
        typeError = false;
        cout << "What type of event is this?(Ex. party, wedding, etc.) " << endl;
        cout << " " << endl;
        cout << "1. Party " << endl;
        cout << "2. Wedding " << endl;
        cout << "3. Shower (bridal, baby, etc. " << endl;
        cout << "4. Other (Please specify) " << endl;
        cin >> eventTypeOp;
        clearInput();

        switch (eventTypeOp) {
            case 1:
                eventType = "Party";
                break;
            case 2:
                bool weddingError;
                do {
                    weddingError = false;
                    eventType = "Wedding";
                    cout << "Would you like to create a registry?(Y/N) " << endl;
                    char ans2;
                    cin >> ans2;
                    clearInput();
                    switch (ans2) {
                        case 'Y':
                            registryTrue = true;
                            break;
                        case 'y' :
                            registryTrue = true;
                            break;
                        case 'N':
                            registryTrue = false;
                            break;
                        case 'n' :
                            registryTrue = false;
                            break;
                        default:
                            cout << "Please enter either Y or N" << endl;
                            weddingError = true;
                            break;
                    }
                } while (weddingError);
                break;
            case 3:
                bool showerError;
                do {
                    showerError = false;
                    eventType = "Shower";
                    cout << "Would you like to create a registry? (Y/N)" << endl;
                    char ans3;
                    cin >> ans3;
                    clearInput();
                    switch (ans3) {
                        case 'Y':
                            registryTrue = true;
                            break;
                        case 'y' :
                            registryTrue = true;
                            break;
                        case 'N':
                            registryTrue = false;
                            break;
                        case 'n' :
                            registryTrue = false;
                            break;
                        default:
                            cout << "Please enter either Y or N" << endl;
                            showerError = true;
                            break;
                    }
                } while (showerError);
                break;
            case 4:
                cout<<"What type of event is this?"<<endl;
                getline(cin, eventName);
                cout << " " << endl;
                break;
            default:
                cout << "Please enter a number 1 to 4" << endl;
                typeError = true;
                continue;

        }
        cout << " " << endl;
    } while (typeError);

    bool menBool = true;
    char temChar;
    int y = 0;
    while(menBool) {
        cout << "What is the time of the event? (Enter in the format 01:23)" << endl;
        getline(cin, eventTime);
        if(eventTime.length() != 5){
            cout<<"Wrong input"<<endl;
            cout<<"Please input the time in the correct format"<<endl;
            continue;
        }
        else{
            temChar = eventTime.at(0);
            y = (int)temChar - 48;
            if(isdigit(eventTime.at(0)) == 0 || (y == 1 && ((int)eventTime.at(1) - 48) > 2)){ // checks if hour is proper
                cout<<"Wrong input"<<endl;
                cout<<"Please input the time in the correct format"<<endl;
                continue;
            }

            if(isdigit(eventTime.at(1)) == 0||(y == 0 && (int)eventTime.at(1) - 48 > 9)){
                cout<<"Wrong input"<<endl;
                cout<<"Please input the time in the correct format"<<endl;
                continue;
            }

            temChar = eventTime.at(2);
            if(temChar != ':'){
                cout<<"Wrong input"<<endl;
                cout<<"Please input the time in the correct format"<<endl;
                continue;
            }

            temChar = eventTime.at(3);
            y = (int)temChar - 48;

            if(isdigit(eventTime.at(3)) == 0 || isdigit(eventTime.at(4)) == 0){ // checks if minute is proper
                cout<<"Wrong input"<<endl;
                cout<<"Please input the time in the correct format"<<endl;
                continue;
            }

            if(y > 5 || (int)eventTime.at(4) - 48 > 9){
                cout<<"Wrong input"<<endl;
                cout<<"Please input the time in the correct format"<<endl;
                continue;
            }


        }
        menBool = false;
    }

    bool menuuu = true;
    int time = 0;
    while(menuuu){
        cout<<"is this time AM(select 1) or PM(select 2)"<<endl;
        cin>>time;
        clearInput();
        switch(time){
            case 1:
                eventTime +="AM";
                menuuu = false;
                break;
            case 2:
                eventTime += "PM";
                menuuu = false;
                break;
            default:
                cout<<"Error please select 1 for AM or 2 for PM"<<endl;
                continue;
        }
    }

    cout<<" "<<endl;


    //kareem and jovanny
    bool menuBool = true;
    int x = 0;
    char tempChar;
    while(menuBool){
        cout<<"What is the date of the event? (Enter in the form mm/dd/yyyy. Year must be between 2000 and 2199)" <<endl;
        getline(std::cin, eventDate);	//HAS TO STAY AS GETLINE. IF NOT YOU HAVE TO CLEAR INPUT EVERYTIME ITS BAD INPUT OR YOU GET AN

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

            if(x == 3 && (((int)eventDate.at(4)) - 48) > 1){
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
        clearInput();
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
                getline(cin, dressCode);
                dressBool = false;
                break;
            default:
                cout<<"Error, enter the number of the option you'd like."<<endl;
                continue;

        }

    }

    bool notesError;
    do {
        notesError = false;
        cout << "Any notes you'd like your guests to know?(Y/N)" << endl;
        char choice = 0;
        cin >> choice;
        clearInput();
        switch (choice) {
            case 'Y':
                cout << "Type your message." << endl;
                getline(cin, message);
                cout << endl;
                break;
            case 'y' :
                cout << "Type your message." << endl;
                getline(cin, message);
                cout << endl;
                break;
            case 'N':
                message = "N/A";
                break;
            case 'n' :
                message = "N/A";
                break;
            default:
                cout << "Please enter either Y or N" << endl;
                notesError = true;

        }
    } while (notesError);


    //include the message in details?


    eventCreator.emplace_back(eventPlanner, eventName, eventType,eventDate, eventTime, eventLocation, dressCode , message);     //jovanny and mark emplace back is equivalent to push back

    //while loop used to create guests
    bool menu = true;
    bool breakOut;          // bool to check if you broke out of the for loop due to a bad age string
    bool menu2 = true;
    char addGuest = 'z';


    while(menu){
        breakOut = false;
        //kimmy I had to turn it into two parts so it saves all letters correctly but the string is still saved under the same name
        string firstInvite;
        string lastInvite;

        cout<<"Please Enter the first name of your guest."<<endl;
        getline(cin, firstInvite);
        cout<<endl;

        cout<<"Please enter the last name of your guest."<<endl;
        getline(cin, lastInvite);
        cout<<endl;

        guestName = firstInvite + " " + lastInvite;

        //cout<< guestName <<endl;

        cout<<"Please enter the guest's age (numbers only)"<<endl;
        cin>>age;
        clearInput();
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
            cout<<"Would you like to add another guest? (Y/N)"<<endl;
            cin>>addGuest;
            clearInput();
            switch(toupper(addGuest)){
                case 'Y':   //
                    menu = true;
                    menu2 = false;
                    break;
                case 'y' :
                    menu = true;
                    menu2 = false;
                    break;
                case 'N':
                    menu = false;
                    menu2 = false;
                    break;
                case'n' :
                    menu = false;
                    menu2 = false;
                    break;
                default:
                    menu2 = true;
                    cout<<"Please enter either Y or N"<<endl;
            }
        }
    }
    if(registryTrue)
    {
        registry();
    }


    //SEATING CHART SECTION
    cout<<"Would you like to create a seating chart? (Y/N)"<<endl;
    char ynInput;
    cin>>ynInput;
    clearInput();

    switch(ynInput){
        case'Y' :
            seatingSystem();
            //create seating chart
            break;
        case 'y' :
            seatingSystem();
        case 'N':
            break;
        case 'n' :
            break;
        default :
            cout<<"Please enter Y or N."<<endl;
    }

    cout<<" "<<endl;

    char foodItemOption;
    char ynInput2;
    bool error;
    // Food request // Nicholas and Mark
    do {
    cout << "Do you want any guests to bring any food items?" << endl;
    cout << "1. Yes " << endl;
    cout << "2. No " << endl;

    cin >> ynInput2;
    clearInput();


        error = false;
        switch (ynInput2) {
            case '1':
                cout << "What type of food would you like your guests to bring? " << endl;
                cout << " " << endl;
                cout << "1. Appetizers " << endl;
                cout << "2. Entrees " << endl;
                cout << "3. Desserts " << endl;
                cout << "4. Any Food Item " << endl;
                cin >> foodItemOption;
                clearInput();
                switch (foodItemOption) {
                    case '1':
                        eventCreator.back().setFoodToBring("appetizers ");
                        cout << "We'll let your guests know to bring appetizers." << endl;
                        break;
                    case '2':
                        eventCreator.back().setFoodToBring("entrees ");
                        cout << "We'll let your guests know to bring entrees." << endl;
                        break;
                    case '3':
                        eventCreator.back().setFoodToBring("desserts ");
                        cout << "We'll let your guests know to bring desserts." << endl;
                        break;
                    case '4':
                        eventCreator.back().setFoodToBring("any food item ");
                        cout << "We'll let your guests know to bring any food item." << endl;
                        break;
                    default:
                        cout << "Error, enter the number of the option you'd like." << endl;
                        error = true;
                        break;
                }
            case '2':
                eventCreator.back().setFoodToBring("");
                break;
            default:
                cout << "Please try again" << endl;
                error = true;
                break;
        }
    } while (error);

    cout << " " << endl;


}

// Mark
void plusOne(){
    bool error;
    do {
        error = false;
        char menuOption;
        string firstname;
        string lastname;
        string plusonename;
        string plusOneAge;
        cout << "Would you like to bring a plus one?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> menuOption;
        clearInput();
        switch (menuOption){
            case '1':
                cout << "Enter the first name of your plus one: ";
                getline(cin, firstname);

                cout << "\nEnter the last name of your plus one: ";
                getline(cin, lastname);

                plusonename = firstname + ' ' + lastname;

                cout << "Please enter the age of your plus one (Only enter numbers)" << endl;
                getline(cin, plusOneAge);

                for (unsigned int i = 0; i < plusOneAge.size(); i++){
                    if (isdigit(plusOneAge.at(i)) == 0){
                        error = true;
                        cout << "Please enter only digits for the age" << endl;
                        break;
                    }
                }
                eventCreator.back().plusOne(plusonename, stoi(plusOneAge));
                cout << plusonename << " is set to go to the event!" << endl;
                break;
            case '2':
                break;
            default:
                cout << "Please enter 1 or 2" << endl;
                error = true;
                break;
        }
    } while (error);
}


// Mark // Checks to see if someone is going to the event
void checkAttendees(Event event){
    string friendName;                                  // The name of the person you are looking for
    string nameChecked;                                 // The name being looked at from the event
    vector<person> allInvitees = event.getInvitees();   // Gets the invitees from the event
    vector<person> partiallyCorrectNames;               // If no complete match is found, a list of partially correct names will print out
    bool partialNameCorrect = false;                    // Used to see if a name is partially correct
    bool friendFound = false;                           // If a complete match is found, this is true
    bool hasWhitespace = false;                         // If a name has whitespace, it will be removed

    cout << "Please enter the name of the person you are checking to see if they are going: ";
    getline(cin, friendName);
    cout << endl;

    // Iterates through the name and sees if there is whitespace that needs to be removed
    for (unsigned int i = 0; i < friendName.size(); i++){
        if (friendName.at(i) == ' '){
            hasWhitespace = true;
            break;
        }
    }

    // If the name has whitespace, this removes that whitespace
    if (hasWhitespace)
        friendName.erase(remove(friendName.begin(), friendName.end(), ' ')); friendName.end();

    // Makes the entire name lowercase, easier to compare with
    transform(friendName.begin(), friendName.end(), friendName.begin(), ::tolower);

    // Iterates through the invitees list, gets all the names and compares to see if t
    for (unsigned int a = 0; a < allInvitees.size(); a++) {
        // Removes whitespace from names and converts it to lowercase for easier comparisons
        nameChecked = allInvitees.at(a).getName();
        nameChecked.erase(remove(nameChecked.begin(), nameChecked.end(), ' ')); nameChecked.end();
        transform(nameChecked.begin(), nameChecked.end(), nameChecked.begin(), ::tolower);

        // If the name of the person you are looking for completely matches someone found in the list, it prints their name
        // and if they have chosen to go or not.
        if (nameChecked == friendName) {
            cout << allInvitees.at(a).getName() << " is invited to " << event.getEventName() << "." << endl;

            if (allInvitees.at(a).getResponse() == "Yes")
                cout << allInvitees.at(a).getName() << " is going." << endl;
            else if (allInvitees.at(a).getResponse() == "Undecided")
                cout << allInvitees.at(a).getName() << " has not responded to the invite yet." << endl;
            else if (allInvitees.at(a).getResponse() == "No")
                cout << allInvitees.at(a).getName() << " is not going." << endl;

            // Breaks out of the loop
            friendFound = true;
            break;
        } else {
            // If no complete match can be found, partial matches are searched for
            // Useful for just searching for first names
            partialNameCorrect = true;
            for (unsigned int b = 0; b < friendName.size(); b++) {
                if (nameChecked.at(b) != friendName.at(b)) {
                    partialNameCorrect = false;
                    break;
                }
                while (nameChecked.at(b) == friendName.at(b)) {
                    b++;
                    if ((b >= friendName.size()) || (!partialNameCorrect))
                        break;
                }

                // If the name is a partial match, the person is added to a partial matches vector
                if (partialNameCorrect) {
                    partiallyCorrectNames.push_back(allInvitees.at(a));
                }
            }
        }
    }

    // If there was no complete match found, the partial matches are printed, or if no partial matches were found, the person is not in the invitees list
    if (!friendFound){
        if (!partiallyCorrectNames.empty()) {
            for (unsigned int i = 0; i < partiallyCorrectNames.size(); i++) {
                cout << "We found " << partiallyCorrectNames.at(i).getName() << " is invited to "
                     << event.getEventName() << ". " << endl;

                if (partiallyCorrectNames.at(i).getResponse() == "Yes")
                    cout << partiallyCorrectNames.at(i).getName() << " is going." << endl;
                else if (partiallyCorrectNames.at(i).getResponse() == "Undecided")
                    cout << partiallyCorrectNames.at(i).getName() << " has not responded to the invite yet." << endl;
                else if (partiallyCorrectNames.at(i).getResponse() == "No")
                    cout << partiallyCorrectNames.at(i).getName() << " is not going." << endl;
                cout << endl;
            }
        } else {
            cout << "The person you searched for could not be found." << endl;
        }
    }
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
    getline(cin, tempRsvpName);
    tempRsvpName.erase(remove(tempRsvpName.begin(), tempRsvpName.end(), ' '), tempRsvpName.end()); //removes whitespace for comparison
    transform(tempRsvpName.begin(),tempRsvpName.end(), tempRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison


    for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
        tempPeople = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
        for(unsigned int a = 0; a < tempPeople.size(); a++){        //for loop to iterate through all the people in the event
            tempEventName = tempPeople[a].getName();
            tempEventName.erase(remove(tempEventName.begin(), tempEventName.end(), ' '), tempEventName.end()); //removes whitespace for comparison
            transform(tempEventName.begin(),tempEventName.end(), tempEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
            if(tempEventName == tempRsvpName){
                inEvent = true;                                     //bool to let user know whether they re in an event or not
                eventCreator[i].printInvite();                      //prints the invitation to the event

                // Mark CheckAttendees
                char menuOption1;
                cout << "Would you like to check the guest list before choosing? (enter Y for yes or N for no)" << endl;
                cin >> menuOption1;
                clearInput();
                switch (toupper(menuOption1)) {
                    case 'Y':
                        checkAttendees(eventCreator.at(i));
                        break;
                    case 'N':
                        break;
                    default:
                        cout << "Please enter either Y or N" << endl;
                }

                menu = true;
                while(menu){                                        //while loop to check if user is attending the event
                    cout<<"Will you be attending this event? (hit Y for yes or N for no)"<<endl;
                    cin>>menuOption;
                    clearInput();
                    switch(toupper(menuOption)){
                        case 'Y':
                            eventCreator[i].setResponse(a,"Yes");
                            cout<<"Thank you for response!"<<endl;
                            // Asks if the person would like to bring a plus one
                            if (tempPeople.at(a).isPrimary()) {
                                plusOne();
                            }
                            bringItem(tempRsvpName);
                            ride(tempRsvpName);
                            menu = false;
                            break;
                        case 'N':
                            eventCreator[i].setResponse(a,"No");
                            cout<<"Thank you for response!"<< "\n"<<endl;
                            menu = false;
                            break;
                        default:
                            cout<<"Please enter either Y or N"<<endl;
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

//kailee nicholas
void eventDetails()
{
    string Name;					//Initializes all of the event details
    string tempName;
    string tempEvent;
    string tempEventType;
    string tempEventDate;
    string tempEventTime;
    string tempEventLocation;
    string tempDressCode;
    vector<person> guestList;
    string guestName;
    string tableNum;
    string response;
    string gift;
    string bring;
    string ride;
    string food;

    bool isEvent = false;
    cout<<"What is the name of the event that you would like the details for? "<<endl;
    getline(cin, Name);

    tempName = Name;
    tempName.erase(remove(tempName.begin(), tempName.end(), ' '), tempName.end()); //removes whitespace for comparison
    transform(tempName.begin(),tempName.end(), tempName.begin(), ::tolower);    //sets characters to lower case for comparison
    cout<< tempName <<endl;
    for(unsigned int i = 0; i < eventCreator.size(); i++) {          //for loop to iterate through all created events
        tempEvent = eventCreator[i].getEventName();
        tempEvent.erase(remove(tempEvent.begin(), tempEvent.end(), ' '),
                        tempEvent.end()); //removes whitespace for comparison
        transform(tempEvent.begin(), tempEvent.end(), tempEvent.begin(),
                  ::tolower);    //sets characters to lower case for comparison

        tempEventType = eventCreator[i].getEventType();                //
        tempEventDate = eventCreator[i].getEventDate();
        tempEventTime = eventCreator[i].getEventTime();
        tempEventLocation = eventCreator[i].getEventLocation();
        tempDressCode = eventCreator[i].getDressCode();
        guestList = eventCreator[i].getInvitees();
        food = eventCreator[i].getFoodToBring();


        if (tempName == tempEvent) {
            isEvent = true;
            cout << "\nThe event " << Name << " has the following details to it:" << endl;
            cout << "The type of the event is " << tempEventType << endl;
            cout << "The date of the event is " << tempEventDate << endl;
            cout << "The time of the event is " << tempEventTime << endl;
            cout << "The location of the event is " << tempEventLocation << endl;
            cout << "The dress code of the event is " << tempDressCode << endl;
            //cout<<"The food to bring is " << food <<endl;

            //prints list of guests and table assignments
            cout << "The list of guests who are coming  " << endl;
            for (unsigned int a = 0;
                 a < guestList.size(); a++) {        //for loop to iterate through all the people in the event
                guestName = guestList[a].getName();
                tableNum = guestList[a].getSeating();
                response = guestList[a].getResponse();
                gift = guestList[a].getRegistry();
                bring = guestList[a].getBring();
                if (tableNum != "None" && response == "Yes" && gift != "NA" && bring != "nothing") {
                    cout << guestName << " at " << tableNum << " their gift is " << gift << " and they are bringing "
                         << bring << endl;
                } else if (response == "Yes" && tableNum != "None" && gift != "NA") {
                    cout << guestName << " at " << tableNum << " their gift is " << gift << endl;
                } else if (tableNum != "None" && response == "Yes" && bring != "nothing") {
                    cout << guestName << " at " << tableNum << " and they are bringing " << bring << endl;
                } else if (response == "Yes" && gift != "NA" && bring != "nothing") {
                    cout << guestName << " their gift is " << gift << " and they are bringing " << bring << endl;
                } else if (response == "Yes" && gift != "NA") {
                    cout << guestName << " their gift is " << gift << endl;
                } else if (response == "Yes" && tableNum != "None") {
                    cout << guestName << " at " << tableNum << endl;
                } else if (response == "Yes" && bring != "nothing") {
                    cout << guestName << " and they are bringing " << bring << endl;
                } else if (response == "Yes") {
                    cout << guestName << endl;
                }

            }
            cout << "" << endl;
            cout << "List of guests not coming " << endl;
            for (unsigned int b = 0; b < guestList.size(); b++) {
                guestName = guestList[b].getName();
                response = guestList[b].getResponse();
                if (response == "No") {
                    cout << guestName << endl;
                }
            }
            cout << "" << endl;
            cout << "List of guests who are Undecided" << endl;
            for (unsigned int c = 0; c < guestList.size(); c++) {
                guestName = guestList[c].getName();
                response = guestList[c].getResponse();
                if (response == "Undecided") {
                    cout << guestName << endl;
                }
            }
            cout << "List of guests who need a ride" << endl;
            for (unsigned int d = 0; d < guestList.size(); d++) {
                guestName = guestList[d].getName();
                ride = guestList[d].getRide();
                if (ride == "Yes") {
                    cout << guestName << endl;
                }

            }
        }
    }
}


void changeResponse(){
    string tempEventName;
    string tempRsvpName;
    bool inEvent = false;
    bool menu1 = true;
    bool menu2 = false;
    char menuOption1 = 'z';
    char menuOption2 = 'z';
    vector<person> tempPeople;          //POSSIBILY USE POINTERS HERE FOR BETTER MEMORY MANAGEMENT

    cout<<"Please enter your name"<< endl;
    getline(cin, tempRsvpName);
    tempRsvpName.erase(remove(tempRsvpName.begin(), tempRsvpName.end(), ' '), tempRsvpName.end()); //removes whitespace for comparison
    transform(tempRsvpName.begin(),tempRsvpName.end(), tempRsvpName.begin(), ::tolower);    //sets characters to lower case for comparison


    for(unsigned int i = 0; i < eventCreator.size(); i++){          //for loop to iterate through all created events
        tempPeople = eventCreator[i].getInvitees();                 //gets a copy of the invitees to the event
        for(unsigned int a = 0; a < tempPeople.size(); a++){        //for loop to iterate through all the people in the event
            tempEventName = tempPeople[a].getName();
            tempEventName.erase(remove(tempEventName.begin(), tempEventName.end(), ' '), tempEventName.end()); //removes whitespace for comparison
            transform(tempEventName.begin(),tempEventName.end(), tempEventName.begin(), ::tolower);    //sets characters to lower case for comparisom
            if(tempEventName == tempRsvpName){
                inEvent = true;                                     //bool to let user know whether they re in an event or not
                eventCreator[i].printInvite();                      //prints the invitation to the event
                menu1 = true;
                while(menu1){										//while loop to ask if the user would like to change their response to an invitation
                    cout<<"Would you like to change your response for this event? (hit Y for yes or N for no)"<<endl;
                    cin>>menuOption1;
                    clearInput();
                    switch(toupper(menuOption1)){
                        case 'Y':
                            menu1 = false;
                            menu2 = true;
                            break;
                        case 'N':
                            cout<<"Thank you for your response!"<< "\n"<<endl;
                            menu1 = false;
                            menu2 = false;
                            break;
                        default:
                            cout<<"Please enter either Y or N"<<endl;
                            continue;

                    }
                }

                while(menu2){                                        //while loop to change if user is attending the event
                    cout<<"What would you like to change your response to? (hit Y for yes or N for no)"<<endl;
                    cin>>menuOption2;
                    clearInput();
                    switch(toupper(menuOption2)){
                        case 'Y':
                            eventCreator[i].setResponse(a,"Yes");
                            cout<<"Thank you for response!"<<endl;
                            menu2 = false;
                            break;
                        case 'N':
                            eventCreator[i].setResponse(a,"No");
                            cout<<"Thank you for response!"<< "\n"<<endl;
                            menu2 = false;
                            break;
                        default:
                            cout<<"Please enter either Y or N"<<endl;
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
        clearInput();
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
                        clearInput();

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
                eventDetails();
                break;
            case 4:
                cout<<"No problem! To change your response follow the steps below. "<<endl;
                changeResponse();
                break;

            case 5:
                cout<<"See you later, alligator! "<<endl;
                exit(0);

            default:                // clears all input a user puts in and continues the loop //jovanny and mark
                cout<<"Error, enter the number of the option you'd like."<<endl;
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
    cout << "Welcome to the Gator RSVP system!!!!" << endl;
    userMenu();

}