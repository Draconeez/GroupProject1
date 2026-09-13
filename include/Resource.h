#include <string>
#include <iostream>
class Resource {
    public:
    //Constructors
    Resource();
    Resource(std::string id, std::string name, std::string type, bool available);
    //Getters and Setters
    bool checkAvailable();
    void setAvailable(bool available);
    std::string getResourceID();
    std::string getResourceName();
    std::string getResourceType();
    void setResourceID(std::string id);
    void setResourceName(std::string name);
    void setResourceType(std::string type);
    //Display Resource Information to the console
    void DisplayResourceInfo();
    private:
    //Types
    std::string resourceID;
    std::string resourceName;
    std::string resourceType;
    bool isAvailable;
    

};