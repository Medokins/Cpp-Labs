#pragma once
#include <iostream>

using namespace std;

//main class Zelazko
class Zelazko{
    public:
        //sets _temperature to given value
        void UstawTemperature(int);
        //prints infomration about this iron
        void Wypisz() const;
        //gette to get _temperature
        int GetTemp() {return _temperature;}

    protected:
        string _name;
        int _price;
        int _temperature;
        int _range;
};


class Ubranie{
    public:
        //template print for Ubranie
        virtual void Wypisz() const;
        //funcion to iron given Ubranie if possible
        void Prasuj(Zelazko iron);
        //function to crease given Ubranie
        void Pogniec(){
            if(_ironed) _ironed = false;
        }

    protected:
        string _name;
        int _price;
        int _range = 9;
        bool _ironed = false;
};