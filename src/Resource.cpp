#include "Resource.h"
//Constructors
Resource::Resource()
{
    resourceID = "";
    resourceName = "";
    resourceType = "";
    isAvailable = false;
};
Resource::Resource(std::string id, std::string name, std::string type, bool available)
{
    resourceID = id;
    resourceName = name;
    resourceType = type;
    isAvailable = available;
};
//Getters and Setters  
bool Resource::checkAvailable() 
{
    return isAvailable;
}
void Resource::setAvailable(bool available) 
{
    isAvailable = available;
}
std::string Resource::getResourceID() 
{
    return resourceID;
}
std::string Resource::getResourceName() 
{
    return resourceName;
}
std::string Resource::getResourceType() 
{
    return resourceType;
}
void Resource::setResourceID(std::string id) 
{
    resourceID = id;
}
void Resource::setResourceName(std::string name) 
{
    resourceName = name;
}
void Resource::setResourceType(std::string type) 
{
    resourceType = type;
}
//Display Resource Information to the console
void Resource::DisplayResourceInfo()
{
    std::cout << "Resource ID: " << resourceID << std::endl;
    std::cout << "Resource Name: " << resourceName << std::endl;
    std::cout << "Resource Type: " << resourceType << std::endl;
    if(isAvailable) 
    {
        std::cout << "Resource is available." << std::endl;
    } 
    else 
    {
        std::cout << "Resource is not available." << std::endl;
    }
    std::cout << "-------------------------" << std::endl; // for readability
}


