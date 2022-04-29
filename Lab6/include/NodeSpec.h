#pragma once
#include "Node.h"

//  Node class that holds Int value
class NodeInt : public Node {
    public:
        //  constructor
        NodeInt(int value): _value(value) {};
        //  returns value of node
        int valInt() const {
            return _value;
        }
        //  returns value of node as string
        std::string toString() const override {
            return std::to_string(_value);
        }
        //  clones node
        Node * clone() const override {
            return new NodeInt(_value);
        }
        //  default destructor
        ~NodeInt() = default;
    private:
        //  holds value
        int _value;
};

class NodeFloat : public Node {
    public:
        //  constructor
        NodeFloat(float value): _value(value) {};
        //  returns value of node
        float valFloat() const {
            return _value;
        }
        //  returns value of node as string
        std::string toString() const override {
            return std::to_string(_value);
        }
        //  clones node
        Node * clone() const override {
            return new NodeFloat(_value);
        }
        //  default destructor
        ~NodeFloat() = default;
    private:
        //  holds value
        float _value;
};

class NodeString : public Node {
    public:
        //  constructor
        NodeString(std::string value): _value(value) {};
        //  returns value of node
        std::string & valString() {
            return _value;
        }
        //  returns value of node as string
        std::string toString() const override {
            return _value;
        }
        //  clones node
        Node * clone() const override {
            return new NodeString(_value);
        }
        //  default destructor
        ~NodeString() = default;
    private:
        //  holds value
        std::string _value;
};