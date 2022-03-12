#pragma once

//template class with virtual methods
class Algo{
    public:
        virtual Argumenty wykonaj(Argumenty obj) const{
            return obj;
        }
        virtual Algo* sklonuj() const{
            return new Algo;
        }
    private:
};