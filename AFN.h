//
// Created by Andrei on 25-Apr-18.
//

#ifndef LFA2_AFN_H
#define LFA2_AFN_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std ;

class AFN {
public:
    AFN();
    AFN ( const AFN& C );
    virtual ~AFN();
    friend void citire_automat( AFN *&T , int &n , int &q , int *&StF , int &nr ) ;
    friend bool delta( AFN *T , int n , int *StF , int nr , queue < int > &MultimeStari , char word[100]) ;
    friend void delta_prim( AFN *T , int n , queue < int >& MultimeStari , char character ) ;
    friend void inchidere( AFN * , int nrStari ) ;

/**protected:

private:
*/
     ///vector < list < int > > StareInit ;
    int StareInit ;
    vector < int > Inchidere ;
    unsigned int nrchr ;
    char chr[100] ;
    unsigned int nrstf ;
    vector < list < int > > StareFin ;

};


#endif //LFA2_AFN_H
