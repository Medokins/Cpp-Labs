#pragma once
#include <vector>
#include "school.h"
#include <initializer_list>

class Student{
    public:
        Student(std::string name, unsigned points, std::vector<School*> schools) : _name(name), _points(points), _schools(schools) {}
        void print() const{
            std::cout << _name << ": " << _points << " [ ";
            for(auto& elem : _schools){
                std::cout << elem->getclass() << " ";
            }
            std::cout << "] --> ";
            if(_school == nullptr) std::cout << "nieprzyjety" << std::endl;
            else std::cout << _school->getclass() << std::endl;
        }
        unsigned GetPoints(){
           return _points;
        }
        std::vector<School*> GetSchools(){
            return _schools;
        }
        void SetSchool(School* school) {
            _school = school;
        }
    private:
        std::string _name;
        unsigned _points;
        std::vector<School*> _schools;
        School* _school = nullptr;
};