#include <iostream>
#include "AFN.h"
#include <vector>
#include <list>

using namespace std ;

int main() {
    int nrstari , q0 , nrstarifin , *StFin ;
    char word[100] ;
    queue < int > MultimeStari ;
    AFN *T ;
    citire_automat( T , nrstari , q0 , StFin , nrstarifin ) ;
    /**for( int i = 0 ; i < nrstari - 1 ; i++ ) {
        cout << i << " : " << '\n' ;
        for ( int j = 0; j < T[i].nrchr; j++){
            cout << T[i].chr[j] << " : " ;
            list < int > L ;
            L = T[i].StareFin[j] ;
            while( !L.empty() ){
                int x = L.front() ;
                cout << x << " " ;
                L.pop_front() ;
                }
            cout << '\n' ;
            }
        cout << '\n' ;
    }*/
    inchidere( T , nrstari ) ;
    for( int i = 0 ; i < nrstari ; i++ ){
        for( auto j = T[i].Inchidere.begin() ; j != T[i].Inchidere.end() ; j++ )
            cout << *j << " " ;
        cout<<endl;
    }
    return 0;
}