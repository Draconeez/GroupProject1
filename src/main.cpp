#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "../include/Reservation.h"
#include "../include/Resource.h"
#include "../include/ReservationManager.h"
void resourceLoad(std::vector<Resource>& resources) 
{
    //Open the file for reading and check if successful
    std::ifstream file("data/resources.txt");
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return;
    }
    std::string line;
    int lineNumber = 0;
    //Loop to add resources to the vector
    while (std::getline(file, line)) 
    {
        if (!line.empty() && line.back() == '\r') 
        {
            line.pop_back();
        }
        lineNumber++;
        int pos1 = line.find('|');
        int pos2 = line.find('|', pos1 + 1);
        int pos3 = line.find('|', pos2 + 1);
        std::string id = line.substr(0, pos1);
        std::string name = line.substr(pos1 + 1, pos2 - (pos1 + 1));
        std::string type = line.substr(pos2 + 1, pos3 - (pos2 + 1));
        bool available = (line.substr(pos3 + 1) == "Available");
        resources.push_back(Resource(id, name, type, available));
    }
    //Check if finished with file and close it
    if (file.eof())
    {
        std::cout << "Reached end of file." << std::endl;
    }
    else
    {
        std::cerr << "Error: File reading failed!" << std::endl;
    }
    file.close();
}
void reservationFill(ReservationManager& resManager) 
{
    std::ifstream file("data/reservations.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open reservations file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        int pos1 = line.find('|');
        int pos2 = line.find('|', pos1 + 1);
        int pos3 = line.find('|', pos2 + 1);
        int pos4 = line.find('|', pos3 + 1);
        std::string resID = line.substr(0, pos1);
        std::string stuID = line.substr(pos1 + 1, pos2 - (pos1 + 1));
        std::string name = line.substr(pos2 + 1, pos3 - (pos2 + 1));
        std::string reoID = line.substr(pos3 + 1, pos4 - (pos3 + 1));
        std::string date = line.substr(pos4 + 1);
        resManager.insertReservation(resID, reoID, stuID, name, date);
    }
    file.close();
}
int main() {
    //Load resources from file
    std::vector<Resource> resources;
    resourceLoad(resources);
    //Load reservations from file
    ReservationManager rManager;
    reservationFill(rManager);
    int caseNumber=0;   
  while(caseNumber!=10)
  {
    std::cout << "Hello, welcome to the Resource Reservation System!" << std::endl;
    std::cout << "Select an option from the menu below:" << std::endl;
    std::cout << "1. Display All Reservations" << std::endl;
    std::cout << "2. Display Waitlist" << std::endl;
    std::cout << "3. Add Reservation" << std::endl;
    std::cout << "4. Delete Reservation" << std::endl;
    std::cout << "5. Add to Waitlist" << std::endl;
    std::cout << "6. Remove from Waitlist" << std::endl;
    std::cout << "7. Undo Reservation Cancellation" << std::endl;
    std::cout << "8. Display Cancellation History" << std::endl;
    std::cout << "9. Display Resource Information" << std::endl;
    std::cout << "10. Exit" << std::endl;
    std::cin >> caseNumber;
    switch(caseNumber) 
        {
        case 1:
            rManager.displayReservations();
            break;
        case 2:
            rManager.displayWaitlist();
            break;
        case 3: {
            std::string resID, reoID, stuID, name, date;
            std::cout << "Enter Reservation ID: ";
            std::cin >> resID;
            std::cout << "Enter Resource ID: ";
            std::cin >> reoID;
            std::cout << "Enter Student ID: ";
            std::cin >> stuID;
            std::cin.ignore(); 
            std::cout << "Enter Student Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Date (YYYY-MM-DD): ";
            std::cin >> date;
            //Validate if the resource exists in the system before adding the reservation
            bool resourceExists = false;
            for (size_t i = 0; i < resources.size(); i++) {
            if (resources[i].getResourceID() == reoID) 
            {
                resourceExists = true;
                break;
            }
            }
            if (!resourceExists) {
                std::cout << "Error: Resource " << reoID << " does not exist in the system." << std::endl;
                break; 
            }
            
            if (!rManager.isReservationIDExists(resID)) {
                rManager.insertReservation(resID, reoID, stuID, name, date);
            } else {
                std::cout << "Error: Reservation ID " << resID << " already exists." << std::endl;
                break;
            }
            break;
        }
        case 4:
           { std::string resID;
            std::cout << "Enter Reservation ID to delete: ";
            std::cin >> resID;
            rManager.deleteReservation(resID);
            break;}
        case 5:
              {  std::string reoID, stuID, name;
                std::cout << "Enter Resource ID: ";
                std::cin >> reoID;
                std::cout << "Enter Student ID: ";
                std::cin >> stuID; 
                std::cin.ignore();
                std::cout << "Enter Student Name: ";
                std::getline(std::cin, name);
            rManager.addToWaitlist(reoID, stuID, name);
            break;
              }
        case 6:
        {
            std::string reoID, stuID;
                std::cout << "Enter Resource ID: ";
                std::cin >> reoID;
                std::cout << "Enter Student ID: ";
                std::cin >> stuID;
            rManager.removeFromWaitlist(reoID, stuID); 
            break;
        }
        case 7:
            rManager.undoLastCancellation(); 
            break;
        
        case 8:
            rManager.displayCancellationHistory();
            break;
        
        case 9:
            for(size_t i = 0; i < resources.size(); i++) {
            resources[i].DisplayResourceInfo();
            }
            break;    
        case 10:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid case number." << std::endl;
        }
    }
    return 0;
}