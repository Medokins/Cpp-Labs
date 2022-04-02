#pragma once
#include "Figures.h"

//stworzylem plik Abstract.h w ktorym trzymam wszystkie klasy abstrakcyjne,
//ktore traktuje jak "kategorie" np czy dany obiekt mozna narysowac/policzyc pole/przesunac
//utowrzylem w pliku Point.h klase Point ktora dziedziczy po Transformable (bo mozna przesunac punkt)
//ale nie po Drawable czy tez ClosedShape (bo nie mozna narysowac punktu i nie ma on powierzchni)
//w pliku Figures znajduja sie wszystkie figury (lacznie z odcinkiem bo tylko tu mi pasowal) kazda z nich dziedziczy
//odpowiednio po klasach ktorych metody przyjmuje zgodnie z powyzszym wytlumaczeniem.

void draw(Drawable* obj){
    obj->draw();
}