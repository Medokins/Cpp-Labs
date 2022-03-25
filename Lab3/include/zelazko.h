#pragma once
#include "main.h"

//classes with more specific type of Zelazko
class ZelazkoPhilips : public Zelazko{
    public:
        //constructor ZelazkoPhilips 
        ZelazkoPhilips(int price){
            _price = price;
            _name = "Zelazko Philips";
            _range = 5;
        }
};

class ZelazkoTefal : public Zelazko{
    public:
        //constructor ZelazkoTefal 
        ZelazkoTefal(int price){
            _price = price;
            _name = "Zelazko Tefal";
            _range = 7;
        }
};