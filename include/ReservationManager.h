#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
#include "Reservation.h"
#include <string>
#include <iostream>

#include <queue>

struct WaitList{
    std::string resourceID;
    std::string studentID;
    std::string studentName;
};
class ReservationManager {
    public:
    ReservationManager();
    ~ReservationManager();
    //Add insert reservation, remove reservation, display reservations 
//Insert res
//Remove res
//Display all res
    //Add queue methods for waitlist 
// Add student to waitlist
// Remove student from waitlist
// Display Full Waitlist
    private:
    Reservation* head;
    std::queue<WaitList> waitlist;
   
};

#endif
