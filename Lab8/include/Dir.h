#pragma once
#include "SystemFile.h"

/**
*   Dir final class for handeling Dir object from SystemFile class 
**/
class Dir final: public SystemFile{
    public:
        /**
        *   constructor that calls SystemFile constructor
        **/
        Dir(const std::string name): SystemFile(name) {};
        /**
        *   function that outputs Dir name and it's contains
        **/
        void print(std::ostream& os, const std::string& prefix) const override {
            os << prefix << getName() << "  (DIR)" << std::endl;
            for(int i = 0; i < _elements.size(); i++) _elements[i]->print(os, prefix+"  ");
        }
        /**
        *   destructor that cleans Dir itself and all it's contains
        **/
        ~Dir() final {
            std::cout << "Deleting Dir: " << getName() << std::endl;
            for(int i = 0; i < _elements.size(); i++){
                std::cout << "About to delete " << _elements[i]->getName() << std::endl;
                delete _elements[i];
            }
        }
        /**
        *   function that adds SystemFile object to Dir _elements vector
        **/
        void add(SystemFile* element){_elements.push_back(element);}
        /**
        *   operator += that calls add function
        **/
        void operator+=(SystemFile* element) {add(element);}
        /**
        *   function that returns pointer to Dir with a name passed in the argument if it exists
        *   or nullptr if it doesn't exist
        **/
        Dir* findDir(const std::string& name){
            if(getName() == name) return this;
            for(int i = 0; i < _elements.size(); i++){
                Dir* dir = dynamic_cast<Dir*>(_elements[i]);
                if(dir != nullptr) return dir->findDir(name);
            }
            return nullptr;
        }
        /**
        *   function that returns pointer to SystemFile with a name passed in the argument if it exists
        *   or nullptr if it doesn't exist
        **/
        SystemFile* get(const std::string& name){
            if(getName() == name) return this;
            for(int i = 0; i < _elements.size(); i++){
                if(_elements[i]->getName() == name) return _elements[i];
                Dir* dir = dynamic_cast<Dir*>(_elements[i]);
                if(dir){
                    SystemFile* temp = dir->get(name);
                    if(temp) return temp;
                }
            }
            return nullptr;
        }
    private:
        /**
        *   vector containing all SystemFiles added to it
        **/
        std::vector<SystemFile*> _elements;
};