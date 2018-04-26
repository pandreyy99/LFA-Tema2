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
    char character;
    string stareFin;
    bool isStareFin ;

public:
    AFD() {
        isStareFin = false ;
    }

    friend void afisare(AFD *M, int nrStari);

    friend void adaugaTranzitie(AFD *M, int pozitie, string starePlecare, char character, string StareDestinatie , bool finOrNot);

    ~AFD() {}

};

#endif //LFA2_AFD_H
