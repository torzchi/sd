#include <iostream>
#include <fstream>

#define DimMax 20
#define DimMaxCoada 400

using namespace std;

// defineste cele 4 directii: STANGA, SUS, DREAPTA, JOS
int dx[4]= {-1, 0, 1, 0}, dy[4]= {0, 1, 0, -1};

struct Element
{
    int l,c;        //pozitia in caroiaj
    unsigned d;     //distanta minima pana la pozitia l,c
    struct Element* next;
};

Element C[DimMaxCoada], x, y;

int A[DimMax][DimMax], n, m, x0, y0, i, j, k;
int IncC;           // inceput coada
int SfC;            // sfarsit coada

Element* q = NULL;  // coada in varianta LSI


Element getElement(){
    Element e;
    e.l = q->l;
    e.c = q->c;
    e.d = q->d;
    Element* t = q;
    q = q->next;
    delete t;
    return e;
}

void addElement(Element e){
    Element* p = new Element;
    p->l = e.l;
    p->c = e.c;
    p->d = e.d;
    p->next = NULL;
    if(!q)
        q = p;
    else
    {
        Element* t = q;
        while(t->next) t = t->next;
        t->next = p;
    }
}



int main()
{
    ifstream fin("date.in");

    // citeste din fisierul de intrare dimensiunile careului
    fin >> n >> m;

    // citeste ozitia initiala a robotului
    fin >> x0 >> y0;

    // initializeaza careul (nicio pozitie nu este accesibia)
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++) A[i][j] = -2;

    // obstacole
    while (fin)
    {
        fin >> i >> j; // citesc coordonatele obstacolelor
        A[i][j] = -1;
    } // marchez obstacolele cu -1
    fin.close();

    // BORDARE
    for (i=1; i<=n; i++) A[i][0] = A[i][m+1] = -1;
    for (i=1; i<=m; i++) A[0][i] = A[n+1][i] = -1;

    // INITIALIZARE COADA
    x.l=x0;
    x.c=y0;
    x.d=0;
    A[x0][y0]=0;                        // pozitia de start
    ////C[IncC]=x;                          // se pune in coada prima pozitie
    addElement(x);

    // algoritmul lui LEE
    while (q)                           // parcurg COADA  /*IncC <= SfC*/
    {
        ////x = C[IncC++];                  // preia element din coada
        x = getElement();
        //// cout << "\nget: (" << e->l << "," << e->c << ")=" << e->d;

        // deplasare succesiva in cele 4 directii
        // (STANGA, SUS, DREAPTA, JOS)
        for (k=0; k<4; k++)
        {
            y.l = x.l + dx[k];          // elementul urmator
            y.c = x.c + dy[k];
            switch(A[y.l][y.c])             // y- POZITIE LIBERA
            {
            case -2:
                // pozitie explorata pentru prima data
                y.d = x.d + 1;
                A[y.l][y.c] = y.d;      // marcheaza atingerea pozitiei

                ////C[++SfC]= y;            // DUC y IN COADA
                addElement(y);
                break;
            case -1:
                // obstacol
                cout << "\nobstacol";
                break;
            case 0:
                // pozitia de start
                cout << "\npozitia start";
                break;
            default:
                // pozitia a mai fost explorata
                if(A[y.l][y.c] == x.d+1)
                {
                    cout << "\npozitie anterior explorata";
                }
                if(A[y.l][y.c] > x.d+1)
                {
                    cout << "\ncorectie";
                    //  *** corectie ***
                    y.d = x.d + 1;
                    A[y.l][y.c] = y.d;  // marcheaza atingerea pozitiei
                    ////C[++SfC]= y;        // DUC y IN COADA
                }
            }
        }
    }

    // afisarea solutiei
    ofstream fout("date.out");
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
            fout << A[i][j]<<' ';
        fout << '\n';
    }
    fout.close();

    return 0;
}
