//
// Created by Andrei on 25-Apr-18.
//

#ifndef LFA2_AFD_H
#define LFA2_AFD_H

#include <iostream>

using namespace std ;

class AFD {

public:
    AFD() {}

    friend void afisare(AFD *M, int nrStari);

    friend void adaugaTranzitie(AFD *M, int pozitie, int starePlecare, char character, int StareDestinatie);

    ~AFD() {}

    int stareInit;
    char character;
    int stareFin;
};

#endif //LFA2_AFD_H
