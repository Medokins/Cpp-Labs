#pragma once
#include <math.h>
#include <iostream>

/**
*   @brief function that checks if given number is prime:
*   @param int x
*   @return boolean: True if is prime, False if isn't
**/
bool isPrime(int x) {
    if (x==1) return false;
    for(int i=2; i <= sqrt(x); i++) if (x % i == 0) return false;
    return true;
}

namespace num {
    /**
    *   @brief function that converts bolean to string
    *   @param boolean sample
    *   @return std::string: "TRUE" or "FALSE"
    **/
    std::string text(bool sample) {return sample ? "TRUE" : "FALSE";}
    /**
    *   @brief function that counts average from given array  of type T
    *   @param const T* array
    *   @param int length
    *   @return double average
    **/
    template<typename T>
    double srednia(const T* tab, int length) {
        double summ = 0;
        for(int i = 0; i < length; i++) summ += tab[i];
        return summ / length;
    }

    /**
    *   @brief function that checks if all numbers in given range are prime 
    *   @param int starting index of checked range
    *   @param int ending index of checked range
    *   @param const T* array
    *   @param int length
    *   @return true if all number in given range are prime, false if they aren't
    **/
    template<int START, int END>
    bool czyWszystkiePierwsze(const int* tab, int length) {
        if(START > END || END > length) {
            std::cout << "Nieprawidlowy zakres!" << std::endl;
            return false;
        }for(int i = START; i < END; i++) {
            if (isPrime(tab[i])) continue;
            return false;
        }
        return true;
    }
}