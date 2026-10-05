#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
#include "Reservation.h"
#include "CancellationHistory.h"
#include "Resource.h"
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

struct WaitList{
    std::string reservationID;
    std::string resourceID;
    std::string studentID;
    std::string studentName;
    std::string date;
};
class ReservationManager {
    public:
    ReservationManager();
    ~ReservationManager();
    void insertReservation(std::string resID,std::string reoID, std::string stuID, std::string name, std::string d);
    void deleteReservation(std::string resID);
    void displayReservations();
    void addToWaitlist(std::string resID, std::string reoID, std::string stuID, std::string name, std::string date);
    void removeFromWaitlist(std::string reoID, std::string stuID);
    void displayWaitlist();
    void displayCancellationHistory();
    void undoLastCancellation();
    void generateFullReport(std::vector<Resource>& resources);
    bool isWaitlistIDExists(std::string resID);
    bool isReservationIDExists(std::string resID, bool details=false);
    bool isResourceBooked(std::string resourceID, std::string date);
    private:
    Reservation* head;
    std::queue<WaitList> waitlist;
    CancellationHistory cancelHistory;
};

#endif
