#include "ReservationManager.h"
#include <fstream>

ReservationManager::ReservationManager()
{
    head = nullptr;
}
ReservationManager::~ReservationManager()
{

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

    };
    void ReservationManager::displayReservations()
    {

    }
    void ReservationManager::addToWaitlist(std::string resID, std::string stuID, std::string name)
    {

    }
    void ReservationManager::removeFromWaitlist(std::string resID, std::string stuID)
    {

    }
    void ReservationManager::displayWaitlist()
    {

    }
