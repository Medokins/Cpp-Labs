#pragma once
#include <vector>
#include <iostream>

/**
*   Template class for Dir and File classes
**/
class SystemFile{
    public:
        /**
        *   constructor
        **/
        SystemFile(const std::string& name): _name(name) {};
        /**
        *   default destructor
        **/
        virtual ~SystemFile() = default;
        /**
        *   template function that outputs File or Dir name
        **/
        virtual void print(std::ostream& os, const std::string& prefix) const = 0;
        /**
        *   function that returns of File or Dir name
        **/
        std::string getName() const {return _name;}
    private:
        /**
        *   File or Dir name
        **/
        std::string _name;
};

/**
*   overloaded << operator to output Dir or File contains
**/
std::ostream& operator<<(std::ostream& os, const SystemFile& element){
    element.print(os, "");
    return os;
}