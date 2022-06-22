#pragma once
#include <iostream>
#include <functional>
#include "PairOfNumbers.h"

template<typename T>
class RangeArray{
public:
    template <typename T1, typename T2>
    RangeArray(PairOfNumbers<T1, T2> &pair){
        size_t s = static_cast<int>(pair.second) - static_cast<int>(pair.first);
        _vec.reserve(sizeof(T) * s);
        for (size_t i = 0; i < s; i++){
            _vec.push_back(0.0);
        }
    }
    int Size(){
        return _vec.size();
    }
    
    T &operator[](const int &index){
        if(index >= 0){
            return _vec[index];
        }
        else{
            return _vec[_vec.size() + index];
        }
    }

    T &At(const int &index){
        return RangeArray<T>::operator[](index);
    }
private:
    std::vector<T> _vec;
};