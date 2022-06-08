#pragma once 

#include "Sum.h"
#include <vector>

/**
*@brief class Data for storing day of week and vector<double>
**/
class Data {
    public:
        /**
        *@brief costructor for class Data
        *@param string name
        *@param vector<double> values
        **/
        Data(const std::string name, std::vector<double> values) : _name(name), _values(values){}
        /**
        *@brief prints content of Data object
        *@param none
        *@return none
        **/
        void print() const{
            std::cout << _name << ": ";
            for(auto& value : _values){
                std::cout << value << ",  ";
            }
            std::cout << std::endl;
        }
        /**
        *@brief gets value from _values vector at given index
        *@param unsigned index
        *@return double
        **/
        double getValue(unsigned i) {return _values[i];}
        /**
        *@brief gets _values vector
        *@param none
        *@return vector<double>
        **/
        std::vector<double> getValues() {return _values; }
    private:
        std::string _name;
        std::vector<double> _values;
};

/**
*@brief summs values of a given Data object
*@param Data object
*@return Sum object
**/
Sum sumData(Data day){
    double sum = 0;
    for(auto& value : day.getValues()) sum += value;
    return Sum(sum);
}