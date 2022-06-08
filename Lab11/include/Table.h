#pragma once 

#include "Data.h"
#include <algorithm>
#include <functional>

/**
*@brief functor class Comparator to use in sorting functions
**/
class Comparator{
    public:
        Comparator(unsigned column) : _column(column){}
        bool operator()(Data a, Data b) const {
            return a.getValue(_column) < b.getValue(_column);
        }
        unsigned _column;

};

/**
*@brief class Table with different sort methods
**/
class Table {
    public:
        /**
        *@brief overloaded += opeartor to add Data object to _table
        *@param const Data&
        *@return *this
        **/
        Table& operator+=(const Data& day){
            _table.push_back(day);
            return *this;
        }
        /**
        *@brief prints content of _table
        *@param none
        *@return none
        **/
        void print() const {
            for(auto& date : _table) date.print();
        }
        /**
        *@brief sorts _table at given index column
        *@param none
        *@return *this
        **/
        Table& sort(unsigned column){
            if(column >= _table.size()) {
                std::cout << "Indeks " << column << " nieprawidlowy\n";
                return *this;
            }
            Comparator comparator(column);
            std::sort(_table.begin(), _table.end(), comparator);
            return *this;
        }
        /**
        *@brief sorts _table at with given function
        *@param std::function<bool(const Data&, const Data&)>
        *@return *this
        **/
        Table& sortBy(std::function<bool(const Data&, const Data&)> comparator){
            std::sort(_table.begin(), _table.end(), comparator);
            return *this;
        }
    private:
        std::vector<Data> _table;
};


