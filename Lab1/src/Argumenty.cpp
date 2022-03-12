#include "Argumenty.h"

Argumenty::Argumenty(int size){
    _nums.resize(size);
}
Argumenty& Argumenty::operator() (int index, double value){
    _nums[index] = value;
    return *this;
}
void Argumenty::print(const string beggining) const{
    cout << beggining << " ";
    for(int i = 0; i < _nums.size(); i++){
        cout << _nums[i] << " ";
    }
    cout << endl;
}
void Argumenty::print(const string beggining, ostream& c) const{
    c << beggining << " ";
    for(int i = 0; i < _nums.size(); i++){
        c << _nums[i] << " ";
    }
    c << endl;
}