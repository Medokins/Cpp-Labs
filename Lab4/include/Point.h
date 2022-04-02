#pragma once
#include "Abstract.h"
#include <iostream>

using namespace std;

class Point: public Transformable{
    public:
        //constructor for Point
        Point(double x, double y): _x(x), _y(y) {}
        //friended overloaded operator so Point can be printed easly in other classes
        friend ostream& operator<<(ostream& os, Point p){
            p.draw();
            return os;
        }
        //draw for point
        void draw(){
            cout << "(" << getX() << ", " << getY() << ")";
        }
        //getter for _x
        double getX() const {return _x;}
        //getter for _y
        double getY() const {return _y;}
        //moves point by given values
        void shift(double x, double y) override{
            _x += x;
            _y += y;
        }
        //helper funtion to use in other classes
        double countDistance(Point p) const{
            return sqrt(pow(p._x - _x, 2) + pow(p._y - _y, 2));
        } 
    private:
        double _x;
        double _y;
};