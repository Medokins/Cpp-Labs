#pragma once
#include "Node.h"

//  class that contains begin and end of a cyclic list
class CyclicList {
    public:
        //  default constructor
        CyclicList() = default;
        //  adds element to cyclic list
        void addElement(Node * element){
            if(_begin == _end && _begin == nullptr){
                _begin = _end = element;
            } else {
                _end->setNext(element);
                _end = _end->getNext();
                _end->setNext(_begin);
            }
        }
        //  overloads << operator to add element to list on call
        CyclicList & operator<<(Node * element){
            addElement(element);
            return * this;
        }
        //  returns number of elemnts that list contains
        int count() const {
            Node * temp = _begin;
            int counter = (_begin == _end && _begin == nullptr) ? 0 : 1;
            while(temp != _end){
                counter += 1;
                temp = temp->getNext();
            }
            return counter;
        }
        //  overloads << operator to output list content
        friend std::ostream& operator<<(std::ostream& os, const CyclicList& list){
            Node * temp = list._begin;
            while(temp != list._end){
                os << temp->toString() << " ";
                temp = temp->getNext();
            }
            os << temp->toString() << " ";
            return os;
        }
        // overloads () operator to return begin
        Node * operator()() const {
            return _begin;
        }
        // shifts one element forwards
        CyclicList & rotate(){
            _begin = _begin->getNext();
            _end = _end->getNext();
            return * this;
        }
        // shifts one element backwards
        CyclicList & rotate_back(){
            Node * temp = _begin;
            while(temp->getNext() != _end){
                temp = temp->getNext();
            }
            _begin = temp->getNext();
            _end = temp;
            return * this;
        }
        //  copy constructor
        CyclicList(const CyclicList & other){
            Node * temp = other._begin;
            Node * clonned;
            while(temp != other._end){
                clonned = temp -> clone();
                if(_begin == nullptr){
                _begin = _end = clonned;
                } else {
                _end -> setNext(clonned);
                _end = clonned;
                _end -> setNext(_begin);
                }
                temp = temp->getNext();
            }
            clonned = temp -> clone();
            _end -> setNext(clonned);
            _end = clonned;
            _end -> setNext(_begin);
        }
        // destructor
        ~CyclicList(){
            _end->setNext(nullptr);
            Node * temp;
            while(_begin != nullptr){
                temp = _begin;
                _begin = temp->getNext();
                delete temp;
            }
        }
    private:
        //  holds begin of list
        Node * _begin = nullptr;
        //  holds end of list
        Node * _end = nullptr;
};