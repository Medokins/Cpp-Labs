#pragma once
#include "SystemFile.h"

/**
*   File class for handeling file object from SystemFile class 
**/
class File: public SystemFile{
    public:
        /**
        *   constructor that calls SystemFile constructor
        **/
        File(const std::string name): SystemFile(name) {};
        /**
        *   function that outputs File name
        **/
        void print(std::ostream& os, const std::string& prefix) const {os << prefix << getName() << " (FILE)" << std::endl;}
};