#pragma once
#include <iostream>

//  Template for class Node
template <typename T>
class Node{
    public:
        //  constructor
        Node(const T val): _value(val) {};

        //  function that sets _next as given Node element
        void setNext(Node<T>* element) {_next = element;}

        //  function that returns _value
        T getValue() const {return _value;}

        //  function that returns _next
        Node<T>* getNext() const {return _next;}

    private:
        // Node<T> that stores _next pointer
        Node<T>* _next = nullptr;

        // T value that stores Node _value
        const T _value;
};

//  Template for class List
template<typename T>
class List{
    public:

        //  default consturctor
        List() = default;

        //  move constructor
        List(List<T>&& list){
            _begin = std::exchange(list._begin, nullptr);
            _end = std::exchange(list._end, nullptr);
        }

        //  copy constructor
        List(const List<T>& list){
            Node<T>* current = list.getHead();
            while(current){
                add(current->getValue());
                current = current->getNext();
            }
        }

        //  function that returns beggining of list
        Node<T>* getHead() const {return _begin;}

        //  function that adds Node of type T to list
        List& add(const T val) {
            Node<T>* temp = new Node<T>(val);
            if(_begin == nullptr) {
                _begin = temp;
                _end = _begin;
            }else {
                _end->setNext(temp);
                _end = temp;
            }
            return *this;
        }

        //  function that checks if given value is in list
        bool contains(const T val) const{
            Node<T>* temp = _begin;
            while(temp != nullptr) {
                if(temp->getValue() == val) return true;
                temp = temp->getNext();
            }
            return false;
        }

        //  overloaded << operator to print contents of list
        friend std::ostream &operator<<(std::ostream &os, const List<T> &list){
            Node<T>* temp = list.getHead();
            while(temp != nullptr) {
                os << temp->getValue() << " ";
                temp = temp->getNext();
            }
            return os;
        }

        //  destructor
        ~List(){
            Node<T>* temp = _begin;
            while(temp != _end) {
                temp = temp->getNext();
                delete _begin;
                _begin = temp;
            }
            delete _end;
        }
    private:
        //  holds begin of list
        Node<T> * _begin = nullptr;
        
        //  holds end of list
        Node<T> * _end = nullptr;
};