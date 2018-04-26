//
// Created by Andrei on 25-Apr-18.
//

#ifndef LFA2_AFD_H
#define LFA2_AFD_H

#include <iostream>

using namespace std ;

class AFD {
private:
    string stareInit;
    char character[100];
    string stareFin;
    bool isStareFin ;

public:
    AFD() {
        isStareFin = false ;
    }

    friend void afisare(AFD *M, int nrStari);

    friend void adaugaTranzitie(AFD M[100], int pozitie, string starePlecare, char character, string StareDestinatie);

    friend void adaugaCaracter(AFD M[100], int dimAFD, string stare, char characterToIntroduce);

    ~AFD() {}

};

#endif //LFA2_AFD_H
