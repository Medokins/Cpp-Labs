#pragma once
 
//class with figures that can be drawn
class Drawable{
    public:
        virtual void draw() const = 0;
        virtual double length() const = 0;
};

//class with figures that can be moved
class Transformable{
    public:
        virtual void shift(double x, double y) = 0;
};

//class with figures that have area
class ClosedShape{
    public:
        virtual double area() const = 0;
};