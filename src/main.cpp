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
        if (line.empty()) continue;
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
        if (line.empty()) continue;
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

//Swaps two Resources in vector
void swapResources(Resource& a, Resource& b) 
{
    Resource temp = a;
    a = b;
    b = temp;
}

//Resource partition for Quick Sort
int partition(std::vector<Resource>& resources, int low, int high)
{
    std::string pivot = resources[high].getResourceID();
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (resources[j].getResourceID() < pivot) {

            i++;

            swapResources(resources[i], resources[j]);
        }
    }
    swapResources(resources[i + 1], resources[high]);
    return i + 1;
}

//Quick Sort function for Resources
void quickSort(std::vector<Resource>& resources, int low, int high) {

    if (low < high) {

        int pivotIndex = partition(resources, low, high);

        quickSort(resources, low, pivotIndex - 1);

        quickSort(resources, pivotIndex + 1, high);

    }
}

int binarySearchResource(std::vector<Resource>& resources, const std::string& targetID) {
    int left = 0;
    int right = resources.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        
        if (resources[mid].getResourceID() == targetID) {
            return mid; 
        }
        if (resources[mid].getResourceID() < targetID) {
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }
    return -1; 
}

int main() {
    //Load resources from file
    std::vector<Resource> resources;
    resourceLoad(resources);
    //Load reservations from file
    ReservationManager rManager;
    reservationFill(rManager);
    int caseNumber=0;   
  while(caseNumber!=13)
  {
    std::cout << "====== Welcome to the Resource Reservation System! =====" << std::endl;
    std::cout << "Select an option from the menu below:" << std::endl;
    std::cout << "1. Display All Reservations" << std::endl;
    std::cout << "2. View Waitlist" << std::endl;
    std::cout << "3. Create a Reservation" << std::endl;
    std::cout << "4. Cancel Reservation" << std::endl;
    std::cout << "5. Search Reservations" << std::endl;
    std::cout << "6. Sort Resources" << std::endl;
    std::cout << "7. Undo Reservation Cancellation" << std::endl;
    std::cout << "8. Generate Full Report" << std::endl;
    std::cout << "9. View Resources" << std::endl;
    std::cout << "10. View Cancellation History" << std::endl;
    std::cout << "11. Search Resources" << std::endl;
    std::cout << "12. Remove Waitlist Entry" << std::endl;
    std::cout << "13. Exit" << std::endl;
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
            std::cout << "Enter Reservation ID (Ex. 001): ";
            std::cin >> resID;
            std::cout << "Enter Resource ID(R102 - R120): ";
            std::cin >> reoID;
            std::cout << "Enter Student ID (Ex. 1234): ";
            std::cin >> stuID;
            std::cin.ignore(); 
            std::cout << "Enter Student Name (Ex. John Doe): ";
            std::getline(std::cin, name);
            std::cout << "Enter Date (MM/DD/YYYY): "; // Now displays correct date format
            std::cin >> date;

            if (rManager.isReservationIDExists(resID, false) || rManager.isWaitlistIDExists(resID)) {
                std::cout << " == Error: Reservation ID " << resID << " is already in use. ==" << std::endl;
                break; 
            }
            //Validate if the resource exists in the system before adding the reservation
            size_t resourceIndex = resources.size(); // Initialize to an invalid index  
            for (size_t i = 0; i < resources.size(); i++) {
            if (resources[i].getResourceID() == reoID) 
            {
                resourceIndex = i; // Store the index of the found resource 
                break;
            }
            }
            if (resourceIndex == resources.size()) { // If the resource was not found, display an error message
                std::cout << " == Error: Resource " << reoID << " does not exist in the system ==" << std::endl;
                break; 
            }
            // Check if the resource is available before proceeding with the reservation
            if (!resources[resourceIndex].checkAvailable()) {
                std::cout << " == Resource " << reoID << " is currently Unavailable. ==" << std::endl;
                std::cout << "Add yourself to the waitlist? (y/n): ";
                char choice;
                std::cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    rManager.addToWaitlist(resID, reoID, stuID, name, date);
                }
                break; 
            }
            // Check if the resource is already booked for the given date before proceeding with the reservation
            if (rManager.isResourceBooked(reoID, date)) {
                std::cout << " == Resource " << reoID << " is already booked for " << date << " ==" << std::endl;
                std::cout << "Add yourself to the waitlist? (y/n): ";
                char choice;
                std::cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    rManager.addToWaitlist(resID,reoID, stuID, name, date);
                    std::cout << " == Added to the waitlist. ==" << std::endl;
             }
             break;
            
            }
            rManager.insertReservation(resID, reoID, stuID, name, date);
            break;
        }
        case 4:
           { std::string resID;
            std::cout << "Enter Reservation ID to delete (Ex. 001): ";
            std::cin >> resID;
            rManager.deleteReservation(resID);
            break;}
        //Required Search:Reservations
        case 5:
        {
            std::string resID;
                std::cout << "Enter Reservation ID to search (Ex. 001): ";
                std::cin >> resID;
                
                if (!rManager.isReservationIDExists(resID, true)) {
                    std::cout << "Reservation ID " << resID << " not found."<< std::endl;
                }
                break;
        }
        //Required Sort:Resources
        case 6:
        {
            std::cout << "Sorting resources..." << std::endl;
            quickSort(resources, 0, static_cast<int>((resources.size() - 1)));
            std::cout << "Resources successfully sorted by ID." << std::endl;
            break;
        }
        case 7:
            rManager.undoLastCancellation(); 
            break;
        
        case 8:
            rManager.generateFullReport(resources);
            break;
        
        case 9:
            for(size_t i = 0; i < resources.size(); i++) {
            resources[i].DisplayResourceInfo();
            }
            
            break;
        case 10:
        rManager.displayCancellationHistory();
        break;

        //Binary Search for Resources
        case 11:
        {
            std::string search;
            std::cout << "Enter Resource ID to search (Ex. R105): ";
            std::cin >> search;
            
            // Binary search needs sorted array
            std::cout << "Sorting resources for binary search" << std::endl;
            quickSort(resources, 0, static_cast<int>(resources.size() - 1));
            
            int index = binarySearchResource(resources, search);
            if (index != -1) {
                std::cout << "Resource found: " << resources[index].getResourceID() << " (" << resources[index].getResourceName() << ")" << std::endl;
            } else {
                std::cout << "Resource ID " << search << " not found." << std::endl;
            }
            break;
        }
        case 12: 
        {
            std::string reoID, stuID, date;
            std::cout << "Enter Resource ID to leave waitlist (Ex. R102): ";
            std::cin >> reoID;
            std::cout << "Enter your Student ID (Ex. 1234): ";
            std::cin >> stuID;
            std::cout << "Enter the date of the reservation (Ex. 09/01/2025 ): ";
            std::cin >> date;
            rManager.removeFromWaitlist(reoID, stuID, date);
            std::cout << " == Removed from waitlist successfully. =="<<std::endl;
            break;
        }
        case 13:
            std::cout << " *===== Exiting the program. =====* " << std::endl;
            break;
        default:
            std::cout << " *-------------------------*" << std::endl;
            std::cout << " === Invalid case number ==" << std::endl;
            std::cout << " ==== Please Try Again ==== " << std::endl;
            std::cout << " *-------------------------*" << std::endl;
			std::cout << std::endl;
        }
    }
    return 0;
}