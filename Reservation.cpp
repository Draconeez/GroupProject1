#include "Reservation.h"
//Constructors
Reservation::Reservation()
{
    reservationID = "";
    resourceID = "";
    studentID = "";
    studentName = "";
    date = "";
    next = nullptr;
};
Reservation::Reservation(std::string resID,std::string reoID, std::string stuID, std::string name, std::string d)
{
    reservationID = resID;
    resourceID = reoID;
    studentID = stuID;
    studentName = name;
    date = d;
    next = nullptr;
};
//Getters and Setters  

std::string Reservation::getReservationID() {return reservationID;}
std::string Reservation::getResourceID() {return resourceID;}
std::string Reservation::getStudentID() {return studentID;}
std::string Reservation::getStudentName() {return studentName;}
std::string Reservation::getDate() {return date;}
Reservation* Reservation::getNext() {return next;}


void Reservation::setReservationID(std::string resID) {reservationID = resID;}
void Reservation::setResourceID(std::string reoID) {resourceID = reoID;}
void Reservation::setStudentID(std::string stuID) {studentID = stuID;}
void Reservation::setStudentName(std::string name) {studentName = name;}
void Reservation::setDate(std::string d) {date = d;}
void Reservation::setNext(Reservation* next) {this->next = next;}

//Display Reservation Information to the console
void Reservation::DisplayReservationInfo()
{
    std::cout << "Reservation ID: " << reservationID << std::endl;
    std::cout << "Resource ID: " << resourceID << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Student Name: " << studentName << std::endl;
    std::cout << "Listed Date : " << date << std::endl;
}


