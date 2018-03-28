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


class Event{ //Matt
    
    private:
        int day, month, year, hour, minute;
        std::string eventName;
        
    public:
        void setEventName(std::string eventName);
        
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
        
}

}