#pragma once
#include "main.h"

//class KoszulaBawelniana with additional _length variable to store sleevs lenght (short or long)
class KoszulaBawelniana : public Ubranie{
    public:
        //change _length to 0 (short)
        void SkrocRekawy() {_length = 0;}
        //KoszulaBawelniana constructor
        KoszulaBawelniana(int price, int length){
            _price = price;
            _length = length;
            _name = "Koszula bawelniana";
            _range = 7;
        }
    
        void Wypisz();
    //variable to store sleevs length
    protected:
        int _length;
};

class KoszulaJedwabna : public Ubranie{
    public:
        KoszulaJedwabna(int price, int length){
            _price = price;
            _length = length;
            _name = "Koszula jedwabna ";
            _range = 3;
        }
        void SkrocRekawy() {_length = 0;}
        void Wypisz();
    protected:
        int _length;
};

//class SpodnieBawelniane with additional _ironed_crease variable to check if it has ironed crease
class SpodnieBawelniane : public Ubranie{
    public:
        //SpodnieBawelniane constructor
        SpodnieBawelniane(int price)
        {
            _price = price;
            _name = "Spodnie bawelniane";
            _range = 7;
        }
        //function to crease edges
        void Pogniec(){if(_ironed_crease) _ironed_crease = false;}
        void Wypisz();
        void PrasujKanty(Zelazko);
    protected:
        //variable to check if creased have been ironed
        bool _ironed_crease = false; 
};

class SpodnieJedwabne : public Ubranie{
    public:
        SpodnieJedwabne(int price)
        {
            _price = price;
            _name = "Spodnie jedwabne";
            _range = 3;
        }
        void Pogniec(){if(_ironed_crease) _ironed_crease = false;}
        void Wypisz();
        void PrasujKanty(Zelazko);
    protected:
        bool _ironed_crease = false; 
};

/*PS I would personally create class Koszula and class Spodnie and than class KoszulaBawelniana : public Koszula
so SkrocRekaw(), Wypisz() and variable _length would be in class Koszula
same for Pogniec(), Wypisz(), PrasujKanty(Zelazko) would be in class Spodnie
(same as I've done with class Zelazko) but it is stated to be done as above in exrecise (if I understand that correctly)*/
