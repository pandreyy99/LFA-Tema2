#include <iostream>
#include <cstring>
#include "AFN.h"
#include "AFD.h"

struct Table{
    char c;
    vector < int > vector1 ;
};

string toString( vector < int > local , int dim ){
    string stare ;
    stare.resize( dim + 1 );
    for( int i = 0 ; i <= dim ; i++ )
        stare.pop_back() ;
    stare.insert( stare.begin() , 'q' ) ;
    for( int x : local ){
        stare.append( to_string(x) );
    }
    return stare ;
}

bool isNew( vector < string > vector1 , int dimVector , string deCautat ){
    for( int i = 0 ; i < dimVector ; i++ ){
        for( string iterator : vector1 )
            if( iterator == deCautat ) return false ;
    }
    return true ;
}

bool isStareFin( int* multimeStariFin , int nrStariFin , int stareCurenta ){
    for( int i = 0 ; i < nrStariFin ; i++ )
        if( multimeStariFin[i] == stareCurenta ) return true;
    return false ;
}

vector<int> concatenare(vector<int> multime1, vector<int> multime2) {
    vector<int> temp;
    int size = multime1.size() + multime2.size() , k = 1 ;
    temp.resize(size + 1);
    for(int i = 0 ; i <= size ; i++ ) temp.pop_back();
    for (auto iterator = multime1.begin(); iterator != multime1.end(); iterator++)
        temp.push_back(*iterator);
    for (auto iterator = multime2.begin(); iterator != multime2.end(); iterator++) {
        bool ok = true;
        for (auto i = temp.begin(); i != temp.end(); i++)
            if (*iterator == *i) ok = false;
        if (ok) { temp.push_back(*iterator); k++ ;}
    }
    return temp;
}

using namespace std ;

int main() {
    int nrstari , q0 , nrstarifin , *StFin , tableSize , vectorStringSize = 0 , afdSize = 0 ;
    char alfabet[100] ;
    vector < string > stari ;
    AFN *T ;
    AFD M[100];
    citire_automat( T , nrstari , q0 , StFin , nrstarifin , alfabet ) ;
    tableSize = strlen(alfabet) ;
    tableSize *= nrstari ;
    Table local[ tableSize + 1 ] ;
    tableSize = 0 ;

    /**
     * creare tabel
     */
    for( int j = 0 ; j < strlen(alfabet) ; j++ )
        for( int i = 0 ; i < nrstari ; i++ ) {
            local[++tableSize].c = alfabet[j] ;
            local[tableSize].vector1 = delta( T , nrstari , i , alfabet[j] ) ;
        }

    /**
     * reuniune
     */
    string stareInitiala = toString( T[q0].getInchidere() , nrstari ) , stare ;
    vector < int > temp = T[q0].getInchidere() ;
    stari.resize(100);
    stare = stareInitiala ;
    for( int i = 0 ; i < strlen(alfabet) ; i++ ) {
        while ( isNew(stari , vectorStringSize , stare ) ) {
            vector<int> temp2;
            bool ok ;
            stari[vectorStringSize++] = stare;
            for (int iterator : temp) {
                ok = isStareFin( StFin , nrstarifin , iterator ) ;
                temp2 = concatenare(temp2, delta(T, nrstari, iterator, alfabet[i]));
            }
            stare = toString(temp2, nrstari);
            adaugaTranzitie( M , afdSize++ , stareInitiala , alfabet[i] , stare , ok ) ;
            stareInitiala = stare ;
            temp = temp2;
        }
    }
    afisare( M , afdSize ) ;
    return 0;
}