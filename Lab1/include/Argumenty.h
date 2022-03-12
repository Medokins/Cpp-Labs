#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Argumenty{

    // friending Suma and Pierwiastek so I can access _nums in class Suma and Pierwiastek
    friend class Suma;
    friend class Pierwiastek;

    public:
        //vector initializer
        Argumenty(int);
        //overwritten opeartor() that puts double values with given int index into the _nums vector
        Argumenty& operator() (int, double);
        //two print functions
        void print(const string) const;
        void print(const string, ostream&) const;
    private:
        //vector to store all values
        vector<double> _nums;
};