#include <string>
#include <iostream>
class Reservation {

    public:
    //pointer

    Reservation* next;

    //Constructors
    Reservation()
    {
        this -> reservationID = "";
        this -> studentID = "";
        this -> studentName = "";
        this -> date = "";
        this -> next = NULL;
    }
    Reservation(std::string resID, std::string stuID, std::string name, std::string d)
    {
        this -> reservationID = resID;
        this -> studentID = stuID;
        this -> studentName = name;
        this -> date = d;
        this -> next = NULL;
    };

    //Getters and Setters

    std::string getReservationID();
    std::string getStudentID();
    std::string getStudentName();
    std::string getDate();
    void setReservationID(std::string resID);
    void setStudentID(std::string stuID);
    void setStudentName(std::string name);
    void setDate(std::string d);

    //Display Reservation Information to the console
    void DisplayReservationInfo();

    private:
    //Types
    std::string reservationID; 
    std::string studentID; 
    std::string studentName;
    std::string date;
};