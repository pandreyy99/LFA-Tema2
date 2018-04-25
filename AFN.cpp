//
// Created by Andrei on 25-Apr-18.
//

#include "AFN.h"

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

AFN::AFN()
{
    ///ctor
    StareInit = -1 ;
    nrchr = 0 ;
    nrstf = 0 ;
    chr[nrchr] = '\0' ;
}

AFN::AFN( const AFN& other )
{
    ///copy ctor
    if(this != &other){
        StareInit = other.StareInit ;
        nrchr = other.nrchr ;
        strcpy(chr , other.chr);
        nrstf = other.nrstf ;
        StareFin.resize(nrstf + 1);
        StareFin = other.StareFin ;
    }
}

AFN::~AFN()
{
    ///dtor
    StareInit = -1 ;
    nrchr = 0 ;
    nrstf = 0 ;
}

void citire_automat( AFN *&T , int &n , int &q , int *&StF , int &nr )
{   int i , j , x ;
    ifstream f( "C:\\Users\\Andrei\\Documents\\GitHub\\LFA-Tema2\\automat.ini" ) ;
    /** Citim starea initiala */
    f >> i ;
    q = i ;
    /** Citim nr de stari finale */
    f >> i ;
    nr = i ;
    StF = new int[nr+1] ;
    /** Citim starile finale */
    for( i = 0 ; i < nr ; i++ )
        f >> StF[i] ;
    /** Citim nr total de stari */
    f >> i ;
    n = i ;
    T = new AFN[n+1] ;
    for( i = 0 ; i < n ; i++ ){
        T[i].StareInit = i+1 ;
        /**Citim nr de caractere cu care putem pleca din starea i+1 */
        f >> T[i].nrchr ;
        T[i].StareFin.resize(T[i].nrchr) ;
        /** Citim caracterele cu care putem realiza tranzitii */
        for( j = 0 ; j < T[i].nrchr ; j++ ){
            /** Citim caracterul j+1 pentru starea curenta */
            cout << "Dati caracterul " << j+1 << " pentru starea " << i+1 ;
            cin.get( T[i].chr[j] ) ;
            cin.get() ;
            cout << '\n' ;
            /** Citim starile in care putem ajunge cu caracterul curent , pana la intalnirea valorii -1 */
            f >> x ;
            while( x!=-1 ){
                T[i].StareFin[j].push_back( x ) ;
                f >> x ;
            }
        }
    }
    cout << "Automat citit!" << '\n' ;
}

void delta_prim( AFN *T , int n , queue < int >& MultimeStari , char character )
{
    /**
    Vectorul de tip AFN T contine toate tranzitiile posibile a automatului
    nrstari = nr total de stari
    Coada MultimeStari primita ca parametru este compusa din starile din care vom pleca cu caracterul character
    In coada C_temp vom introduce starile in care se ajunge dupa efectuarea operatiei d*(q,character) , unde q apartine MultimeStari
    character = caracterul cu care se vor face tranzitiile
    Lista L este o copie temporara a listei de stari in care se poate ajunge cu caracterul c din fiecare stare i , unde i apartine MultimeStari
    */
    queue < int > C_temp ;
    while( !MultimeStari.empty() ){
        int x = MultimeStari.front() ;
        MultimeStari.pop() ;
        for( int i = 0 ; i < n ; i++ ){
            if( T[i].StareInit == x ){
                for( int j = 0 ; j < T[i].nrchr ; j++ ){
                    if( T[i].chr[j] == character ){
                        list < int > L ;
                        L = T[i].StareFin[j] ;
                        while( !L.empty() ){
                            int x = L.front() ;
                            C_temp.push( x ) ;
                            L.pop_front() ;
                        }
                    }
                }
            }
        }
    }
    MultimeStari = C_temp ;
}

bool delta( AFN *T , int n , int *StF , int nr , queue < int > &MultimeStari , char word[100])
{
    int i , j , x ;
    if( word[0] == '\0' ){
        for( i = 0 ; i <= MultimeStari.size() ; i++ ){
            x = MultimeStari.front() ;
            MultimeStari.pop() ;
            for( j = 0 ; j < nr ; j++ )
                if( x == StF[j] )
                    return true ;
        }
        return false ;
    }
    else {
        if( MultimeStari.empty() )
            return false ;
        else {
            char x = word[0] ;
            strcpy( word , word + 1 ) ;
            delta_prim( T , n , MultimeStari , x ) ;
            return delta( T , n , StF , nr , MultimeStari , word ) ;
        }
    }
}

void inchidere( AFN* T , int nrStari ){
    T->Inchidere.resize( nrStari + 1 ) ;
    list < int > L ;
    for( int i = 0 ; i < nrStari ; i++ )
        for ( int j = 0; j < T[i].nrchr; j++) {
            if(strchr( " " , T[i].chr[j] ) )
            L = T[i].StareFin[j];
            while( !L.empty() ) {
                int x = L.front() ;
                T[i].Inchidere.push_back( x ) ;
                L.pop_front() ;
            }
        }
}