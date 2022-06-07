#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

class Student;
class School{
    public:
        School(std::string school_name, unsigned capacity): _name(school_name), _capacity(capacity) {};
        std::string getclass(){
            return _name;
        }
        unsigned getmax(){
            return _capacity;
        }
        void print() const;
        std::vector<Student*> GetStudents(){
            return _students;
        }
        void SetStudent(Student* student) {
            _students.push_back(student);
        }
    private:
        std::string _name;
        unsigned _capacity;
        std::vector<Student*> _students;
};