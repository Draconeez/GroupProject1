#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include "Reservation.h"
#include <vector>
#include <iostream>

class CancellationHistory {
private:
    std::vector<Reservation> historyStack; // vector for stack implementation

public:
    CancellationHistory(); 
    
    void push(Reservation res); 
    Reservation pop();          
    bool isEmpty();             
    void displayHistory();      
};

#endif