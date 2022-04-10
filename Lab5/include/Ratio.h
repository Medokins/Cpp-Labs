#pragma once
#include "Base.h"
#include "Primitive.h"

class Ratio: public Base{
    public:
        Ratio(const Base& x, const Base& y): _x(x), _y(y) {};
        void InnerPrint() const final{
            cout << "("; _x.InnerPrint();
            cout << "/";
            _y.InnerPrint(); cout << ")";
        }
        void PrintWithValue() const final{
            InnerPrint();
            cout << " = " << getValue() << endl;
        }
        //getter to calculate Ratio of _x and _y
        double getValue() const final {
            return _x.getValue() / _y.getValue();
        }
    private:
        const Base& _x;
        const Base& _y;
};