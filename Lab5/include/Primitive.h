#pragma once
#include "Base.h"

class Primitive: public Base{
    public:
        Primitive(double x): _x(x) {};
        void InnerPrint() const final{
            cout << getValue();
        }
        void PrintWithValue() const final{
            InnerPrint();
            cout << endl;
        }
        //getter for _x value
        double getValue() const final {return _x;}
        //setter for _x value
        void Set(double x) {_x = x;}
    private:
        double _x;
};