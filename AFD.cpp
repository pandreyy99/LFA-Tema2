//
// Created by Andrei on 25-Apr-18.
//

#include "AFD.h"
#include <fstream>
#include <cstring>

using namespace std ;

void afisare( AFD *M , int nrStari ) {
    ofstream out("C:\\Users\\Andrei\\Documents\\GitHub\\LFA-Tema2\\output");
    for( int i = 0 ; i <= nrStari ; i++ ){
        out << "Din starea " << M[i].stareInit;
        if( M[i].isStareFin ) out << " , care este si stare finala , " ;
        out << " ajungi cu caracterul " << M[i].character;
        out << " in starea " << M[i].stareFin;
        out << '\n' ;
    }
}

void adaugaTranzitie(AFD M[100], int pozitie, string starePlecare, char characterTranzitie, string stareDestinatie) {
    M[pozitie].stareInit = starePlecare;
    M[pozitie].character[0] = characterTranzitie;
    M[pozitie].stareFin = stareDestinatie;
}

void adaugaCaracter(AFD *M, int dimAFD, string stare, char characterToIntroduce) {
    for (int i = 0; i < dimAFD; i++) {
        if (M[i].stareInit == stare)
            if (strchr(M[i].character, characterToIntroduce) == nullptr)
                strcat(M[i].character, reinterpret_cast<const char *>(characterToIntroduce));
    }
}
