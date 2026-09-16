#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
#include "Reservation.h"
#include <string>
#include <iostream>
#include <stack>
#include <queue>
struct CancellationHistory{
    std::string reservationID;
    std::string resourceID;
    std::string studentID;
    std::string studentName;
    std::string date;
};
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

    //Add queue methods for waitlist and stack methods for cancellation history

    private:
    Reservation* head;
    std::queue<WaitList> waitlist;
    std::stack<CancellationHistory> cancelHistory;
};

#endif
