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
        
    public:
        Event(void);
        
        Event(std::string eventName, time_t eventTimeDate);
        
        void setEventName(std::string eventName);
        
        void setEventTime(time_t eventTimeDate);
        
        std::string getEventName();
        
        
        class Person{ //the person class /Matt
    
            private:
                std::string name;
                int age;
                bool primary; //Primary guest is true. Plus one is false.
        
            public:
                void setName(std::string name);
        
                void setAge(int age);
        
                void setPrimary(bool primary);
        
                std::string getName();
        
                int getAge();
        
                bool getPrimary();
        
        };


};