#include <string>
#include <iostream>
class Resource {
    public:
    //Constructors
    Resource();
    Resource(std::string id, std::string name, std::string type, bool available) 
    {
        resourceID = id;
        resourceName = name;
        resourceType = type;
        isAvailable = available;
    };
    //Getters and Setters
    bool checkAvailable() 
    {
        return isAvailable;
    }
    void setAvailable(bool available) 
    {
        isAvailable = available;
    }
    std::string getResourceID() 
    {
        return resourceID;
    }
    std::string getResourceName() 
    {
        return resourceName;
    }
    std::string getResourceType() 
    {
        return resourceType;
    }

    void setResourceID(std::string id) 
    {
        resourceID = id;
    }
    void setResourceName(std::string name) 
    {
        resourceName = name;
    }
    void setResourceType(std::string type) 
    {
        resourceType = type;
    }
    //Display Resource Information to the console
    void DisplayResourceInfo()
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
    }
    private:
    //Types
    std::string resourceID;
    std::string resourceName;
    std::string resourceType;
    bool isAvailable;
    

};