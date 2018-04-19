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

using namespace std;
class Event{ //Matt
    
    private:
        time_t eventTimeDate;
        string eventName;
        string eventLocation;//Jovanny/Mark
        string eventType;  //Jovanny/Mark
        
    public:
        Event(void);
        
        Event(std::string eventName, time_t eventTimeDate);
        
        void setEventName(string eventName);
        
        void setEventTime(time_t eventTimeDate);

        void setEventLocation(string location); //Jovanny/Mark

        void setEventType(string occassion);  //Jovanny/Mark

        string getEventType();  //Jovanny/Mark

        string getEventlocation(); //Jovanny/Mark

        string getEventType();   //Jovanny/Mark
        
        string getEventName();
        
        
       /* class Person{ //the person class /Matt
    
            private:
                string name;
                int age;
                bool primary; //Primary guest is true. Plus one is false.
        
            public:
                void setName(std::string name);
        
                void setAge(int age);
        
                void setPrimary(bool primary);
        
                string getName();
        
                int getAge();
        
                bool getPrimary();
        
        }; */


};