//
// Created by Andrei on 25-Apr-18.
//

#include "AFD.h"
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <fstream>

using namespace std ;

/**
 * trebuie adjustat
 */
/**void AFD::afisare() {
    ifstream out("C:\\Users\\Andrei\\Documents\\GitHub\\LFA-Tema2\\output") ;
    for( int i = 0 ; i < nrStari ; i++ ){
        out << "Starea " << i << " : q" ;
        while( !Stare[i].empty() ) {
            out << Stare[i].front() ;
            Stare[i].pop_front() ;
        }
        out << '\n' ;
    }
}
*/
void AFD::adauga( int stareDeAdaugat , int indice ) {
    Stare[ indice ].push_back( stareDeAdaugat ) ;

}


