#pragma once
#include "Argumenty.h"
#include "Algo.h"

class Suma : public Algo{
    public:
        //method that returns Argumenty object with summ value of given a vector
        Argumenty wykonaj(Argumenty obj) const{
            double summ = 0;
            for(int i = 0; i < obj._nums.size(); i++){
                summ += obj._nums[i];
            }
            Argumenty temp(1);
            temp(0, summ);
            return temp;
        }
        Suma* sklonuj() const{
            return new Suma;
        }
    private:
};