#pragma once
#include <vector>
#include <functional>

using namespace std;

class DivisibleBy{
    public:
        //constructor
        DivisibleBy(int x) : _num(x) {};
        //overwrite operator()
        bool operator()(int x){return x % _num == 0;}
    private:
        //number to check if given int is divisible by it
        int _num;
};

class GreaterThan{
    public:
        //constructor
        GreaterThan(int x) : _num(x) {};
        //overwrite operator()
        bool operator()(int x){return x > _num;}
    private:
        //number to check if given int is greater than by it
        int _num;
};