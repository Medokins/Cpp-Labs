#pragma once
#include <iostream>
#include <functional>

template <typename FirstType, typename SecondType>
class PairOfNumbers{
public:
    FirstType &first;
    SecondType &second;
    
    explicit PairOfNumbers(FirstType &num1, SecondType &num2): first{num1}, second{num2} {}
    PairOfNumbers(const PairOfNumbers<FirstType, SecondType> &p): first{std::ref(p.first)}, second{std::ref(p.second)}{}
    ~PairOfNumbers() = default;

    PairOfNumbers<SecondType, FirstType> Swapped() const{  
        return PairOfNumbers<SecondType, FirstType>(std::ref(second), std::ref(first));
    }
    void Print() const{
        std::cout << "Print method: " << first << " " << second << std::endl;
    }
    void Add(int num){
        first += num;
        second += num;
    }
    void Scale(int mutiplier){
        first *= mutiplier;
        second *= mutiplier;
    }
    void Info(){
        std::cout << "This is NON-const pair of numbers" << std::endl;
    }
    void Info() const{
        std::cout << "This is const pair of numbers" << std::endl;
    }
};