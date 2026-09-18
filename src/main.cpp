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
    file.close();
    if (file.eof())
    {
        std::cout << "Reached end of file." << std::endl;
    }
    else
    {
        std::cerr << "Error: File reading failed!" << std::endl;
    }

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
        std::string reoID = line.substr(pos1 + 1, pos2 - (pos1 + 1));
        std::string stuID = line.substr(pos2 + 1, pos3 - (pos2 + 1));
        std::string name = line.substr(pos3 + 1, pos4 - (pos3 + 1));
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
    for(size_t i = 0; i < resources.size(); i++) {

        resources[i].DisplayResourceInfo();
    }

    
    return 0;
}