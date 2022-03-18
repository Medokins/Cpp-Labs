#pragma once
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class List{
    public:
        //insert element into vector
        void insert(int x){_vec.push_back(x);}
        //print functions
        void print(const string) const;
        void print() const;
        //overwrite operator []
        int& operator[](int x){return _vec[x];}
        //returns List object with vector filled with filtered values
        List filter(function<bool(int)>) const;
    private:
        //vector to store values
        vector<int> _vec;
};