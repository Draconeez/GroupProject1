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
        // make sure there is a reservation to delete
	if (head == nullptr)
	{
		std::cout << "No reservations to delete." << std::endl;
		return;
	}

	// Delete the head node if it matches the reservation ID
	if (head->getReservationID() == resID)
	{
		Reservation* temp = head;
		head = head->getNext();
		delete temp;
		std::cout << "Reservation with ID " << resID << " deleted." << std::endl;
		return;
	}

	// Traverse the linked list to find the reservation to delete
	Reservation* current = head;
	while (current->getNext() != nullptr)
	{
		if (current->getNext()->getReservationID() == resID)
		{
			Reservation* temp = current->getNext();
			current->setNext(current->getNext()->getNext());
			delete temp;
			std::cout << "Reservation with ID " << resID << " deleted." << std::endl;
			return;
		}
		current = current->getNext();
	}
	std::cout << "Reservation with ID " << resID << " not found." << std::endl;
};

    void ReservationManager::displayReservations()
    {
        Reservation* current = head;
        while (current != nullptr)
        {
	        current->DisplayReservationInfo();
	        current = current->getNext();
        }
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
