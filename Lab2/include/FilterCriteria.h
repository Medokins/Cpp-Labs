#pragma once
#include <vector>
#include <functional>

using namespace std;

class FilterCriteria{
    public:
        //add function to functions vector
        void add(function<bool(int)> func) {_funcVect.push_back(func);}
        //getter to get function from _funVect at given index
        function<bool(int)> get(int x) {return _funcVect[x];}
        //getter to get size of _funVect
        int size() {return _funcVect.size();}
    private:
        //vector storing all functions
        vector<function<bool(int)>> _funcVect;
};