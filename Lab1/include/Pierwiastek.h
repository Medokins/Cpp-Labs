#pragma once
#include <cmath>

class Pierwiastek : public Algo{
    public:
        //method that returns Argumenty object with sqaure-rooted values
        Argumenty wykonaj(Argumenty obj) const{
            for(int i = 0; i < obj._nums.size(); i++){
                obj._nums[i] = sqrt(obj._nums[i]);
            }
            return obj;
        }
        Pierwiastek* sklonuj() const{
            return new Pierwiastek;
        }
    private:
};