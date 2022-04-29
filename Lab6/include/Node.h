#pragma once
#include <iostream>

//  ancestor of NodeInt, NodeFloat and NodeString classes
class Node {
    public:
        //  returns value of node as string
        virtual std::string toString() const = 0;
        //  clones node
        virtual Node * clone() const = 0;
        //  sets next node
        void setNext(Node * element){
            _next = element;
        }
        //  returns next node
        Node * getNext() const {
            return _next;
        }
        //  default destructor
        ~Node() = default;
    protected:
        //  holds pointer to next node
        Node * _next;
};