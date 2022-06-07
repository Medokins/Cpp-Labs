#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
class School;
class Student;
class Table
{
    public:
    Table(std::vector<Student> students) : _students(students) {}
    Table(School* school) {_schools.push_back(school);}
    void operator+=(Student student){
        _students.push_back(student);
    }
    void operator+=(School* school){
        _schools.push_back(school);
    }
    void sortpoints(){
        std::sort(_students.begin(), _students.end(), [](Student s1, Student s2){return s2.GetPoints() < s1.GetPoints();});
    }
    void printStud() const{
        for(auto& s : _students) s.print();
    }
    double getAverageStudScore() const{
        return std::accumulate(_students.begin(), _students.end(), 0, [](int sum, Student student){return sum + student.GetPoints();}) / static_cast<double>(_students.size());
    }
    void recruit(){
        this->sortpoints();
        for(auto& student : _students)
        {
            for(auto* school : student.GetSchools())
            {
                if(school->getmax() > school->GetStudents().size())
                {
                    school->SetStudent(&student);
                    student.SetSchool(school);
                    student.GetSchools().clear();
                    break;
                }
            }
        }
    }
    void printRecruit(){
        for(auto* school : _schools) school->print();
    }

    private:
        std::vector<School*> _schools;
        std::vector<Student> _students;
};