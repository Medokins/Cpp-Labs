#pragma once
#include <iostream>
#include <functional>
#include <initializer_list>

using namespace std;

class MyNode {
  public:
    int val(){return _value;}
    MyNode * _next;
    int _value;
};

class MyList {
  public:
    MyList(): _head(nullptr), _tail(nullptr), _size(0) {
      cout << "KONST: Domyslny\n";
    };
    MyList(int);
    MyList(const MyList&);
    MyList(MyList&&);
    MyList(std::function<int(MyNode*)>, int);
    MyList(std::initializer_list<int>);
    ~MyList();
    bool empty() const;
    int size() const;
    void clear();
    void add(int);
    void print() const;
  private:
    MyNode * _head;
    MyNode * _tail;
    int _size;
};