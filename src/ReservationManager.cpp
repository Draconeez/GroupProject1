#include "ReservationManager.h"
#include <fstream>

ReservationManager::ReservationManager()
{
    head = nullptr;
}
ReservationManager::~ReservationManager()
{
    Reservation* current = head;
    while (current != nullptr) {
        Reservation* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
}

    void ReservationManager::insertReservation(std::string resID,std::string reoID, std::string stuID, std::string name, std::string d)
    {
        Reservation* newNode = new Reservation(resID, reoID, stuID, name, d);
        if (head == nullptr) 
        {
            head = newNode;
            return;
        }
        Reservation* current = head;
        while (current->getNext() != nullptr) 
        {
            current = current->getNext();
        }
            current->setNext(newNode);
        }
    void ReservationManager::deleteReservation(std::string resID)
    {
        Reservation* tempNode = nullptr;
        //If empty list, return
        if (head == nullptr) 
        {
            std::cout << " == Reservation list is empty. ==" << std::endl;
            return;
        }
        //If at the head
        if (head->getReservationID() == resID) 
        {
            tempNode = head;
            head = head->getNext();            
        }
        else
        {
            //Regular case
            Reservation* current = head;
            while (current->getNext() != nullptr && current->getNext()->getReservationID() != resID) {
                current = current->getNext();
            }
            //If found, delete the node
            if (current->getNext() != nullptr) {
                tempNode = current->getNext();
                current->setNext(tempNode->getNext());
                
            }
        }
        if (tempNode == nullptr) {
        std::cout << " == Error: Reservation ID " << resID << " not found. ==" << std::endl;
        return;
    }
    // Keep the details of the reservation
    std::string freedResourceID = tempNode->getResourceID();
    std::string freedDate = tempNode->getDate();

    // Push the reservation to the cancel history and delete it
    Reservation cancelledRes(tempNode->getReservationID(), tempNode->getResourceID(), 
                             tempNode->getStudentID(), tempNode->getStudentName(), tempNode->getDate());
    cancelHistory.push(cancelledRes);
    delete tempNode;            
    std::cout << " == Reservation " << resID << " canceled successfully. ==" << std::endl;

    // Waitlist Promotion Logic
    std::queue<WaitList> tempQueue;
    bool promoted = false;
    // Iterate through the waitlist to find a suitable candidate for promotion
    while (!waitlist.empty()) 
    {
        WaitList candidate = waitlist.front();
        waitlist.pop();

        // Check if someone is waiting for this exact resource and date
        if (!promoted && candidate.resourceID == freedResourceID && candidate.date == freedDate) 
        {
            promoted = true;
            
            // Insert them directly into the active reservations using their original requested ID
            insertReservation(candidate.reservationID, candidate.resourceID, candidate.studentID, candidate.studentName, candidate.date);
            
            std::cout << "\nA slot opened up for " << candidate.resourceID << " on " << candidate.date << std::endl;
            std::cout << " -> Waitlisted student " << candidate.studentName << " was automatically promoted to an active reservation (ID: " << candidate.reservationID << ")." << std::endl;
        }
        else 
        {
            tempQueue.push(candidate);
        }
    }
    
    // Restore the waitlist queue
    waitlist = tempQueue; 
}
    bool ReservationManager::isWaitlistIDExists(std::string resID) 
    {
    std::queue<WaitList> tempQueue = waitlist; 
    while (!tempQueue.empty()) 
    {
        if (tempQueue.front().reservationID == resID) 
        {
            return true;
        }
        tempQueue.pop();
    }
    return false;
    }
    void ReservationManager::displayReservations()
    {
        if (head == nullptr) 
        {
            std::cout << " == Reservation list is empty. ==" << std::endl;
            return;
        }
        Reservation* current = head;
        while (current != nullptr) 
        {
            current->DisplayReservationInfo();
            current = current->getNext();
        }
    }
 
    bool ReservationManager::isReservationIDExists(std::string resID, bool details) {
        Reservation* current = head;
        while (current != nullptr) {
            if (current->getReservationID() == resID) {
                if (details) {
                std::cout << " Booked by " << current->getStudentName() << " (ID: " << current->getStudentID() 
                << ") for Resource " << current->getResourceID() << " on " << current->getDate() << "." << std::endl;
                
            }
                return true;
            }
            
            current = current->getNext();
        }
        return false;
    }
    bool ReservationManager::isResourceBooked(std::string resourceID, std::string date) {
        Reservation* current = head;
        while (current != nullptr) {
            if (current->getResourceID() == resourceID && current->getDate() == date) {
                return true;
            }
            
            current = current->getNext();
        }
        return false;
    }
    void ReservationManager::addToWaitlist(std::string resID,std::string reoID, std::string stuID, std::string name,std::string date)
    {
        WaitList addedStudent = {resID, reoID, stuID, name, date};
        waitlist.push(addedStudent);
        std::cout << "\nResource " << reoID << " is currently occupied on " << date << ".\n"
              << " -> " << name << " (" << stuID << ") has been automatically added to the waitlist!" << std::endl;
    }
    void ReservationManager::removeFromWaitlist(std::string reoID, std::string stuID)
    {
        std::queue<WaitList> tempQueue;
        while (!waitlist.empty()) 
        {
            WaitList front = waitlist.front();
            waitlist.pop();
            if (!(front.resourceID == reoID && front.studentID == stuID)) {
                tempQueue.push(front);
            }
        }
        waitlist = tempQueue; 
    }
    void ReservationManager::displayWaitlist()
    {
        if (waitlist.empty()) 
        {
            std::cout << " == Waitlist is empty. ==" << std::endl;
            return;
        }
        std::queue<WaitList> tempList = waitlist; // Copy so we don't destroy the real queue
        while (!tempList.empty()) {
            WaitList front = tempList.front();
            std::cout << " == " << front.studentName << " (" << front.studentID << ") waiting for resource " << front.resourceID << " on " << front.date << " ==" << std::endl;
            tempList.pop();
        }
    }
    void ReservationManager::displayCancellationHistory()
    {
        cancelHistory.displayHistory();
    }
    void ReservationManager::undoLastCancellation()
    {
        if (cancelHistory.isEmpty()) 
        {
            std::cout << " == No cancellations to undo. ==" << std::endl;
            return;
        }
        Reservation lastCancelled = cancelHistory.pop();
        if (isResourceBooked(lastCancelled.getResourceID(), lastCancelled.getDate())) {
        std::cout << " == Error: Cannot undo cancellation. Resource " << lastCancelled.getResourceID() << " has already been filled by the waitlist for " << lastCancelled.getDate() << ". ==\n";
        addToWaitlist(lastCancelled.getReservationID(), lastCancelled.getResourceID(), lastCancelled.getStudentID(), lastCancelled.getStudentName(), lastCancelled.getDate());
        std::cout << " == Added back to the waitlist. ==" << std::endl;
        return;
        }
        else {
            insertReservation(lastCancelled.getReservationID(), lastCancelled.getResourceID(), lastCancelled.getStudentID(), lastCancelled.getStudentName(), lastCancelled.getDate());
            std::cout << " == Successfully restored the last cancelled reservation. ==" << std::endl;
        }
    }

    void ReservationManager::generateFullReport(std::vector<Resource>& resources){
    std::cout << "\n========== SYSTEM UTILIZATION REPORT ==========" << std::endl;
    
    //Vectors to store count for active reservations and waitlist per resource
    std::vector<int> activeCount(resources.size(), 0);
    std::vector<int> waitlistCount(resources.size(), 0);
    
    //Tally Current Active Reservations
    int totalActive = 0;
    Reservation* current = head;
    while (current != nullptr) 
    {
        totalActive++;
        for (size_t i = 0; i < resources.size(); i++) 
        {
            if (resources[i].getResourceID() == current->getResourceID()) 
            {
                activeCount[i]++;
                break;
            }
        }
        current = current->getNext();
    }
    
    std::cout << "[ ACTIVE RESERVATIONS ]"<<std::endl;
    std::cout << "Total Active Reservations in System: " << totalActive << std::endl << std::endl;
    // Display resource utilization based on active reservation counts
    std::cout << "[ RESOURCE UTILIZATION ]"<<std::endl;
    int maxRequests = 0;
    // Determine the maximum number of active reservations for any resource
    for (size_t i = 0; i < resources.size(); i++) 
    {
        int count = activeCount[i];
        std::cout << " - " << resources[i].getResourceID() << " (" << resources[i].getResourceName() << "): " << count << " active reservations"<<std::endl;         
        if (count > maxRequests) 
        {
            maxRequests = count;
        }
    }
    // Identify the most requested resource(s)
    std::cout << "\n[ MOST REQUESTED RESOURCES ]"<<std::endl;
    if (maxRequests == 0) 
    {
        std::cout << " - No resources are currently booked."<<std::endl;
    } 
    else 
    {
        // Loop through resources to find those with the maximum number of active reservations
        for (size_t i = 0; i < resources.size(); i++) 
        {
            if (activeCount[i] == maxRequests) 
            {
                std::cout << " - " << resources[i].getResourceID() << " (" << resources[i].getResourceName() << ") with " << maxRequests << " reservations"<<std::endl;
            }
        }
    }
    // Display waiting-list statistics
    std::cout << "\n[ WAITING-LIST STATISTICS ]"<<std::endl;
    std::queue<WaitList> tempQueue = waitlist; 
    bool waitlistEmptyFlag = tempQueue.empty();
    // Count the number of students waiting for each resource
    while (!tempQueue.empty()) 
    {
        for (size_t i = 0; i < resources.size(); i++) 
        {
            if (resources[i].getResourceID() == tempQueue.front().resourceID) 
            {
                waitlistCount[i]++;
                break;
            }
        }
        tempQueue.pop();
    }
    // Display waitlist counts per resource
    if (waitlistEmptyFlag) 
    {
        std::cout << " - The waitlist is currently empty."<<std::endl;
    } 
    else 
    {
        // Loop through resources to display the number of students waiting for each resource
        for (size_t i = 0; i < resources.size(); i++) 
        {
            if (waitlistCount[i] > 0) 
            {
                std::cout << " - Resource " << resources[i].getResourceID() << ": " << waitlistCount[i] << " students waiting"<<std::endl;
            }
        }
    } 
    std::cout << "==============================================="<<std::endl<<std::endl;
}
