#include "Reservation.h"
//Constructors
Reservation::Reservation()
{
    reservationID = "";
    studentID = "";
    studentName = "";
    resourceID = "";
    date = "";
};
Reservation::Reservation(std::string resID, std::string stuID, std::string name, std::string rescID, std::string d)
{
    reservationID = resID;
    studentID = stuID;
    studentName = name;
    resourceID = rescID;
    date = d;
};
//Getters and Setters  

std::string Reservation::getReservationID() 
{
    return reservationID;
}
std::string Reservation::getStudentID() 
{
return studentID;
}
std::string Reservation::getStudentName() 
{
    return studentName;
}
std::string Reservation::getResourceID() 
{
return resourceID;
}
std::string Reservation::getDate() 
{
    return date;
}

void Reservation::setReservationID(std::string resID) 
{
    reservationID = resID;
}
void Reservation::setStudentID(std::string stuID) 
{
    studentID = stuID;
}
void Reservation::setStudentName(std::string name) 
{
    studentName = name;
}
void Reservation::setResourceID(std::string rescID) 
{
    resourceID = rescID;
}
void Reservation::setDate(std::string d) 
{
    date = d;
}
//Display Resource Information to the console
void Reservation::DisplayReservationInfo()
{
    std::cout << "Reservation ID: " << reservationID << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Student Name: " << studentName << std::endl;
    std::cout << "Resource ID : " << resourceID << std:: endl;
    std::cout << "Listed Date : " << date << std::endl;
}


