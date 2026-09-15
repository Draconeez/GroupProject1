#include "../include/CancellationHistory.h"

CancellationHistory::CancellationHistory() {
    // empty constructor
}

bool CancellationHistory::isEmpty() {
    return historyStack.empty();
}

// add to stack
void CancellationHistory::push(Reservation res) {
    historyStack.push_back(res);
    std::cout << "Reservation added to cancellation history.\n";
}

// remove from stack and return it
Reservation CancellationHistory::pop() {
    if (isEmpty()) {
        std::cout << "Error: No cancellations to undo.\n";
        return Reservation(); 
    }
    
    Reservation topRes = historyStack.back();
    historyStack.pop_back();
    
    return topRes;
}

// print history
void CancellationHistory::displayHistory() {
    if (isEmpty()) {
        std::cout << "Cancellation history is empty.\n";
        return;
    }
    
    std::cout << "--- Cancellation History (Most Recent First) ---\n";
    
    for (int i = historyStack.size() - 1; i >= 0; i--) {
        std::cout << "Reservation ID: " << historyStack[i].getReservationID() << "\n";
    }
}