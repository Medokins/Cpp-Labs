#include "ubranie.h"

void KoszulaBawelniana::Wypisz(){
    cout << _name << " Cena: "<< _price;
    if(_ironed) cout << ". Wyprasowane.";
    else cout << ". Pogniecione.";
    if(_length == 1) cout << " Dlugi rekaw." << endl;
    else cout << " Krotki rekaw." << endl;
}

void KoszulaJedwabna::Wypisz(){
    cout << _name << " Cena: "<< _price;
    if(_ironed) cout << ". Wyprasowane.";
    else cout << ". Pogniecione.";
    if(_length == 1) cout << " Dlugi rekaw." << endl;
    else cout << " Krotki rekaw." << endl;
}

void SpodnieBawelniane::Wypisz(){
    cout << _name << " Cena: "<< _price;
    if(_ironed) cout << ". Wyprasowane.";
    else cout << ". Pogniecione.";
    if(_ironed_crease) cout << " Kanty." << endl;
    else cout << " Brak kantow." << endl;
}

void SpodnieJedwabne::Wypisz(){
    cout << _name << " Cena: "<< _price;
    if(_ironed) cout << ". Wyprasowane.";
    else cout << ". Pogniecione.";
    if(_ironed_crease) cout << " Kanty." << endl;
    else cout << " Brak kantow." << endl;
}

void SpodnieJedwabne::PrasujKanty(Zelazko iron){
    if(_ironed_crease == false){
        if (iron.GetTemp() > _range) cout << "Zelazko za gorace." << endl;
        else{
            cout <<"---Prasuje nogawki " << _name << " zelazkiem o temp. " << iron.GetTemp() << "." << endl;
            _ironed_crease = true;
        }
    }
    else cout << "Ubranie ma kanty." << endl;
}