#include <iostream>
#include <math.h>

using namespace std;
/*Se da un poligon prin coordonatele varfurilor sale, fiecare varf avand coordonatele x,y doua numere intregi.
Sa se calculeze perimetrul poligonului (suma laturilor).
Sa se rezolve problema folosind structuri.
Obs. A se folosi formula distantei dintre doua puncte.*/

struct punct{
    float x;
    float y;
};

float distanta(punct p1, punct p2)
{
    float d=0;
    d=sqrt((p2.x-p1.x)*(p2.x-p1.x)  + (p2.y-p1.y)*(p2.y-p1.y));
            return d;
}

int main(){
    float perimetru=0;
    int n=5;
    struct punct poligon[] = {{0,0}, {1,0}, {1.5, 0.866}, {0.5, 0.866}, {-0.5, 0.866}};

    for(int i=0;i<n;i++)
    {
        perimetru += distanta(poligon[i],poligon[0]);
    }
    cout<<perimetru;


}


