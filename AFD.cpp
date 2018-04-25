//
// Created by Andrei on 25-Apr-18.
//

#include "AFD.h"
#include <fstream>

using namespace std ;

void afisare(AFD *M, int nrStari) {
    ofstream out("C:\\Users\\Andrei\\Documents\\GitHub\\LFA-Tema2\\output");
    for( int i = 0 ; i < nrStari ; i++ ){
        out << "Din starea " << M[i].stareInit;
        out << " ajungi cu caracterul " << M[i].character;
        out << " in starea " << M[i].stareFin;
        out << '\n' ;
    }
}

void adaugaTranzitie(AFD *M, int pozitie, int starePlecare, char characterTranzitie, int stareDestinatie) {
    M[pozitie].stareInit = starePlecare;
    M[pozitie].character = characterTranzitie;
    M[pozitie].stareFin = stareDestinatie;
}