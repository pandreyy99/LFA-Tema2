#include <iostream>
#include <cstring>
#include <algorithm>
#include "AFN.h"

struct Table{
    char c[100];
    vector < int > vector1 ;
};

struct tranzitie {
    char c[100];
    pair<string, string> stari;
} automat[100];

string toString( vector < int > local , int dim ){
    string stare ;
    stare.resize(static_cast<unsigned int>(dim + 1));
    for( int i = 0 ; i <= dim ; i++ )
        stare.pop_back() ;
    stare.insert( stare.begin() , 'q' ) ;
    for( int x : local ){
        stare.append( to_string(x) );
    }
    return stare ;
}

bool isNew(vector<string> vector1, int dimVector, const string &deCautat) {
    for (auto iterator = vector1.begin(); iterator != vector1.end(); iterator++) {
        if ((*iterator) == deCautat) return false;
    }
    return true ;
}

bool isStareFin(int *multimeStariFin, int nrStariFin, string stare) {
    for (int i = 0; i < nrStariFin; i++) {
        string temp, temp2 = to_string(multimeStariFin[i]);
        while (!stare.empty()) {
            temp = stare.back();
            stare.pop_back();
            if (temp == temp2) return true;
        }
    }
    return false ;
}

vector<int> concatenare(vector<int> multime1, vector<int> multime2) {
    vector<int> temp;
    int size = multime1.size() + multime2.size() , k = 1 ;
    temp.resize(static_cast<unsigned int>(size + 1));
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
    AFN *T ;
    citire_automat( T , nrstari , q0 , StFin , nrstarifin , alfabet ) ;
    tableSize = strlen(alfabet) ;
    tableSize *= nrstari ;
    Table local[tableSize + 1];
    tableSize = 0 ;

    for( int j = 0 ; j < strlen(alfabet) ; j++ )
        for( int i = 0 ; i < nrstari ; i++ ) {
            local[++tableSize].c[0] = alfabet[j];
            local[tableSize].vector1 = delta( T , nrstari , i , alfabet[j] ) ;
        }

    queue<vector<int> > Q;
    vector<int> temp, temp2;
    vector<string> stari, stariFinaleAfd;
    vector<pair<pair<string, string>, char> > afd;

    stari.resize(100);
    afd.resize(100);
    stariFinaleAfd.resize(100);
    temp2.resize(100);
    for (int i = 0; i < 100; i++) {
        stari.pop_back();
        afd.pop_back();
        stariFinaleAfd.pop_back();
        temp2.pop_back();
    }
    int k = 0;
    Q.push(T[q0].getInchidere());
    while (!Q.empty()) {
        temp = Q.front();
        sort(temp.begin(), temp.end());
        stari.push_back(toString(temp, temp.size()));
        Q.pop();
        for (int i = 0; i < strlen(alfabet); i++) {
            temp2.clear();
            for (int iterator : temp)
                temp2 = concatenare(temp2, delta(T, nrstari, iterator, alfabet[i]));
            sort(temp2.begin(), temp2.end());
            if (isNew(stari, stari.size(), toString(temp2, temp2.size()))) {
                Q.push(temp2);
                automat[afdSize].stari = make_pair(toString(temp, temp.size()), toString(temp2, temp2.size()));
                automat[afdSize].c[0] = alfabet[i];
                afdSize++;
            } else {
                automat[afdSize].stari = make_pair(toString(temp, temp.size()), toString(temp2, temp2.size()));
                automat[afdSize].c[0] = alfabet[i];
                afdSize++;
            }
        }
    }
    stari.pop_back();
    for (string s : stari)
        if (isStareFin(StFin, nrstarifin, s))
            stariFinaleAfd.push_back(s);
    cout << "Starile sunt : " << endl;
    for (string s : stari)
        cout << s << endl;
    cout << "Starile finale sunt : " << endl;
    for (string s : stariFinaleAfd)
        cout << s << endl;
    cout << "Tranzitiile sunt : ";
    cout << endl;
    for (int i = 0; i < afdSize - strlen(alfabet); i++)
        cout << automat[i].stari.first << " " << automat[i].c << " " << automat[i].stari.second << endl;
    return 0;
}