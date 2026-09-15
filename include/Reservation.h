#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include <iostream>
class Reservation {
    
    private:
    //Types
    std::string reservationID; 
    std::string resourceID;
    std::string studentID; 
    std::string studentName;
    std::string date;
    //pointer
    Reservation* next;
    public:
    

    //Constructors
    Reservation();
    Reservation(std::string resID,std::string reoID, std::string stuID, std::string name, std::string d);

    //Getters and Setters

    std::string getReservationID();
    std::string getResourceID();
    std::string getStudentID();
    std::string getStudentName();
    std::string getDate();
    Reservation* getNext();
    void setReservationID(std::string resID);
    void setResourceID(std::string reoID);
    void setStudentID(std::string stuID);
    void setStudentName(std::string name);
    void setDate(std::string d);
    void setNext(Reservation* next);
    //Display Reservation Information to the console
    void DisplayReservationInfo();    
};
#endif