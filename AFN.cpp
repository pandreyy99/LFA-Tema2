//
// Created by Andrei on 25-Apr-18.
//

#include "AFN.h"

#include <cstring>

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

void citire_automat( AFN *&T , int &n , int &q , int *&StF , int &nr , char alfabet[100]  )
{   int i , j , x  , nrLitereAlfabet ;
    char c ;
    ifstream f( "C:\\Users\\Andrei\\Documents\\GitHub\\LFA-Tema2\\automat.ini" ) ;
    /**
     * citim alfabetul
     */
    cout << "Alfabetul = " ;
    cin >> alfabet ;
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

            f >> T[i].chr[j];
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

bool isNot(AFN *T, int nrStari, int pozitie, int stare) {
    for (auto iterator = T[pozitie].Inchidere.begin(); iterator != T[pozitie].Inchidere.end(); iterator++)
        if (*iterator == stare) return false;
    return true;
}

void inchidere( AFN* T , int nrStari ){
    T->Inchidere.resize( nrStari + 1 ) ;
    list < int > L ;
    for (int i = nrStari - 1; i >= 0; i--) {
        T[i].Inchidere.push_back(i);
        for (int j = 0; j < T[i].nrchr; j++) {
            if (isdigit(T[i].chr[j]))
                L = T[i].StareFin[j];
            while (!L.empty()) {
                int x = L.front();
                if (isNot(T, nrStari, i, x))
                    T[i].Inchidere.push_back(x);
                L.pop_front();
            }
        }
    }
    for (int i = nrStari - 1; i >= 0; i--) {
        for (int j = 0; j < T[i].nrchr; j++) {
            if (isdigit(T[i].chr[j]))
                L = T[i].StareFin[j];
            while (!L.empty()) {
                int x = L.front();
                for (auto iterator = T[x].Inchidere.begin(); iterator != T[x].Inchidere.end(); iterator++) {
                    if (isNot(T, nrStari, i, *iterator))
                        T[i].Inchidere.push_back(*iterator);
                }
                L.pop_front();
            }
        }
    }
}

bool isNotYet( vector < int > temp , int valoare ){
    for( auto it = temp.begin() ; it != temp.end() ; it++ )
        if( *it == valoare ) return false ;
    return true ;
}

vector<int> concatenate(vector<int> multime1, vector<int> multime2) {
    vector<int> temp;
    int size = multime1.size() + multime2.size() , k = 1 ;
    temp.resize(size + 1);
    for (auto iterator = multime1.begin(); iterator != multime1.end(); iterator++)
        temp.push_back(*iterator);
    for (auto iterator = multime2.begin(); iterator != multime2.end(); iterator++) {
        bool ok = true;
        for (auto i = temp.begin(); i != temp.end(); i++)
            if (*iterator == *i) ok = false;
        if (ok) { temp.push_back(*iterator); k++ ;}
    }
    return temp.resize(multime1.size()+k);
}

vector < int > delta( AFN *T , int nrStari , int stare , char character ) {
    inchidere(T, nrStari);
    vector<int> temp1, temp2;
    temp1.resize(nrStari * nrStari); ///trebuie modif marimea
    temp2.resize(nrStari + 1);
    for (auto iterator = T[stare].Inchidere.begin(); iterator != T[stare].Inchidere.end(); iterator++) {
        for (int i = 0; i < T[*iterator].nrchr; i++)
            if (T[*iterator].chr[i] == character) {
                list<int> L = T[*iterator].StareFin[i];
                while (!L.empty()) {
                    int x = L.front();
                    if(isNotYet())
                    temp1.push_back(x);
                    L.pop_front();
                }
            }
    }
    for (auto iterator = temp1.begin(); iterator != temp1.end(); iterator++){
        temp2 = concatenate(temp2, T[*iterator].Inchidere);
        cout << *iterator << " " ;
    }
    cout << endl ;
    return temp2;
}

vector < vector < int > > tabelPrelim( AFN* T , int nrStari , char alfabet[100] ){
    vector < vector < int > > temp ;
    int i , j , size ;
    size = ( strlen(alfabet) ) * nrStari + 1 ;
    temp.resize( size ) ;
    for( i = 0 ; i < size ; i++ )
        temp[i].resize( ( nrStari + 1 ) , -1 ) ;
    for( i = 0 ; i < strlen(alfabet) ; i++ ){
        for( j = 0 ; j < size ; j++ ){
            temp[j] = delta( T , nrStari , (j%nrStari) , alfabet[i] ) ;
        }

    }
    return temp ;
}
