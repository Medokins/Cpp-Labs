#pragma once
#include <iostream>

using namespace std;

//abstract class
class Base{
    public:
        virtual void InnerPrint() const = 0;
        virtual void PrintWithValue() const = 0;
        virtual double getValue() const = 0;
};