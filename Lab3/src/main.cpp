#include "main.h"

void Zelazko::UstawTemperature(int temperature){
    if (temperature <= _range) _temperature = temperature;
    else cout<<"Ten model nie obsluguje takiego zakresu temperatur." << endl;    
}

void Zelazko::Wypisz() const{
    cout << _name << " cena: " << _price << " Temperatura " << _temperature << endl;
}

void Ubranie::Wypisz() const {
    cout << _name << " Cena: "<< _price;
    if(_ironed) cout << ". Wyprasowane.";
    else cout << ". Pogniecione.";
}

void Ubranie::Prasuj(Zelazko iron){
    if(_ironed == false){
        if (iron.GetTemp() > _range) cout << "Zelazko za gorace." << endl;
        else{
            cout <<"---Prasuje " << _name << " zelazkiem o temp. " << iron.GetTemp() << "." << endl;
            _ironed = true;
        }
    }
    else cout << "---Ubranie nie wymaga prasowania." << endl;
}