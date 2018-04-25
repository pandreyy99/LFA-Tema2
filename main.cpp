#include <iostream>
#include "AFN.h"
#include "AFD.h"

using namespace std ;

int main() {
    int nrstari , q0 , nrstarifin , *StFin ;
    char word[100] ;
    queue < int > MultimeStari ;
    AFN *T ;
    citire_automat( T , nrstari , q0 , StFin , nrstarifin ) ;
    AFD *M;
    M = new AFD[2];
    adaugaTranzitie(M, 0, 1, 'a', 2);
    adaugaTranzitie(M, 1, 2, 'b', 1);
    afisare(M, 2);
    return 0;
}