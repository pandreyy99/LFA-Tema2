#include <iostream>
#include <cstring>
#include "AFN.h"
#include "AFD.h"

using namespace std ;

int main() {
    int nrstari , q0 , nrstarifin , *StFin ;
    char word[100] ;
    char alfabet[100] ;
    queue < int > MultimeStari ;
    AFN *T ;
    citire_automat( T , nrstari , q0 , StFin , nrstarifin , alfabet ) ;
    AFD *M;
    char c = 'a';
    vector < vector < int > > L ;
    vector < int > temp = delta( T , nrstari , 0 , c ) ;
    /**L = tabelPrelim( T , 7 , alfabet ) ;
    for( int i = 0 ; i < strlen(alfabet) ; i++ ){
        cout << "*" << alfabet[i] << "*" << " : " << endl;
        for( int j = i*nrstari ; j < (i+1)*nrstari ; j++ ){
            cout << "q" << j%nrstari << " = { " ;
            for( auto it = L[j].begin() ; it != L[j].end() ; it++)
                cout << *it << " " ;
            cout << "}" << endl ;
        }
        cout << '\n' ;
    }*/
    for( auto it = temp.begin() ; it != temp.end() ; it++ )
        cout << *it << " " ;
    return 0;
}