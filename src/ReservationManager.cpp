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
        //If empty list, return
        if (head == nullptr) 
        {
            std::cout << "Reservation list is empty."<<std::endl;
            return;
        }
        //If at the head
        if (head->getReservationID() == resID) 
        {
            Reservation* tempNode = head;
            head = head->getNext(); 
            cancelHistory.push(*tempNode);
            delete tempNode;            
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
                Reservation* tempNode = current->getNext();
                current->setNext(tempNode->getNext());
                cancelHistory.push(*tempNode);
                delete tempNode;
            }
        }
        
    }
    void ReservationManager::displayReservations()
    {
        if (head == nullptr) 
        {
            std::cout << "Reservation list is empty."<<std::endl;
            return;
        }
        Reservation* current = head;
        while (current != nullptr) 
        {
            current->DisplayReservationInfo();
            current = current->getNext();
        }
    }
    void ReservationManager::addToWaitlist(std::string reoID, std::string stuID, std::string name)
    {
        WaitList addedStudent = {reoID, stuID, name};
        waitlist.push(addedStudent);
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
            std::cout << "Waitlist is empty!"<<std::endl;
            return;
        }
        std::queue<WaitList> tempList = waitlist; // Copy so we don't destroy the real queue
        while (!tempList.empty()) {
            WaitList front = tempList.front();
            std::cout << front.studentName << " (" << front.studentID << ") waiting for resource " << front.resourceID << std::endl;
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
            std::cout << "No cancellations to undo." << std::endl;
            return;
        }
        Reservation lastCancelled = cancelHistory.pop();
        insertReservation(lastCancelled.getReservationID(), lastCancelled.getResourceID(), lastCancelled.getStudentID(), lastCancelled.getStudentName(), lastCancelled.getDate());
    }
