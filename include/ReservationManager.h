#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
#include "Reservation.h"
#include "CancellationHistory.h"
#include <string>
#include <iostream>
#include <queue>
#include <stack>

struct WaitList{
    std::string resourceID;
    std::string studentID;
    std::string studentName;
};
class ReservationManager {
    public:
    ReservationManager();
    ~ReservationManager();
    
    void insertReservation(std::string resID,std::string reoID, std::string stuID, std::string name, std::string d);
    void deleteReservation(std::string resID);
    void displayReservations();
    void addToWaitlist(std::string reoID, std::string stuID, std::string name);
    void removeFromWaitlist(std::string reoID, std::string stuID);
    void displayWaitlist();
    void displayCancellationHistory();
    void undoLastCancellation();
    bool isReservationIDExists(std::string resID);
    bool isResourceBooked(std::string resourceID, std::string date);
    private:
    Reservation* head;
    std::queue<WaitList> waitlist;
    CancellationHistory cancelHistory;
};

#endif
