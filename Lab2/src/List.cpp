#include "List.h"

void List::print(const string s) const{
    cout << s << "[ ";
    for(int i = 0; i < _vec.size(); i++){
        cout << _vec[i] << " ";
    }
    cout << "]" << endl;

}

void List::print() const{
    cout << "[ ";
    for(int i = 0; i < _vec.size(); i++){
        cout << _vec[i] << " ";
    }
    cout << "]" << endl;
}

List List::filter(function<bool(int)> func) const{
    List temp;
    for(int i = 0; i < _vec.size(); i++){
        if(func(_vec[i]))
            temp.insert(_vec[i]);
    }
    return temp;
}
