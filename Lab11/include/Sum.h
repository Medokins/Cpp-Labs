#pragma once 
#include <iostream>

/**
*@brief class Sum for storing summ of values
**/
class Sum {
    public:
        /**
        *@brief Sum constructor 
        *@param const double vector 
        **/
        Sum(const double value) : _value(value){}
        /**
        *@brief gets _value 
        *@param none
        *@return double
        **/
        double value() const {return _value;}
        /**
        *@brief makes functor from Sum, adds given double to _value
        *@param const double
        *@return None
        **/
        void operator()(const double value){ _value += value;}
    private:
        double _value;
};