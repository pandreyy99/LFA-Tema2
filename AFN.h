//
// Created by Andrei on 25-Apr-18.
//

#ifndef LFA2_AFN_H
#define LFA2_AFN_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
#include <queue>

using namespace std ;

class AFN {
public:
    AFN();
    AFN ( const AFN& C );
    virtual ~AFN();
    friend void citire_automat( AFN *&T , int &n , int &q , int *&StF , int &nr  , char* alfabet  ) ;

    friend void inchidere( AFN * , int nrStari ) ;

    friend bool isNot(AFN *T, int nrStari, int pozitie, int stare);

    friend vector<int> concatenate(vector<int>, vector<int>);

    friend vector<int> delta(AFN *T, int nrStari, int stare, char character);

    friend vector < vector < int > > tabelPrelim( AFN* T , int nrStari , char* alfabet ) ;

protected:

private:
    int StareInit ;
    vector < int > Inchidere ;
    unsigned int nrchr ;
    char chr[100] ;
    unsigned int nrstf ;
    vector < list < int > > StareFin ;

};


#endif //LFA2_AFN_H
