#include <string>
#include <iostream>
class Reservation {

    public:
    //Constructors
    Reservation();
    Reservation(std::string resID, std::string stuID, std::string name, std::string rescID, std::string d);
    //Getters and Setters

    std::string getReservationID();
    std::string getstudentID();
    std::string getStudentName();
    std::string getResourceID();
    std::string getDate();
    void setReservationID(std::string resID);
    void setStudentID(std::string stuID);
    void setStudentName(std::string name);
    void setResourceID(std::string rescID);
    void setDate(std::string d);

    //Display Resource Information to the console
    void DisplayReservationInfo();

    private:
    //Types
    std::string reservationID; 
    std::string studentID; 
    std::string studentName;
    std::string resourceID;
    std::string date;
};