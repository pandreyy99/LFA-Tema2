//
// Created by Andrei on 25-Apr-18.
//

#ifndef LFA2_AFD_H
#define LFA2_AFD_H

#include <list>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>

using namespace std ;

class AFD {
    int nrStari ;
    vector < list < int > > Stare ;

public:
    AFD( int number ){
        nrStari = number ;
        Stare.resize( number + 1 ) ;
    }
    ///void afisare() ;
    void adauga( int stareDeAdaugat , int indice ) ;
    ~AFD(){
        nrStari = 0 ;
        Stare.resize( 0 ) ;
    }

};


#endif //LFA2_AFD_H
