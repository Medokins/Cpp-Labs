#include "student.h"
#include "school.h"

void School::print() const{
    std::cout << _name << " - " << _capacity << ": ";
    if(_students.size() == 0) std::cout << "brak przyjetych" << std::endl;
    else{
        std::cout << std::endl;
        for(auto& elem: _students){
            elem->print();
        }
    }
}