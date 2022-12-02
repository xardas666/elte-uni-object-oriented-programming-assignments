//
// Created by gottf on 04/04/2021.
//

#ifndef BEADANDO2_EREDMENYHIRDETES_H
#define BEADANDO2_EREDMENYHIRDETES_H
#include "eredmenyEnumerator.cpp"
struct VersenyHal {
    friend ostream &operator<<(ostream &os, const VersenyHal &hal);

    string verseny;
    int db;
};

class EredmenyHirdetes {
public:
    Eredmeny egyHalatSeFogottElsoAListabol();
    VersenyHal aVersenyAholALegtobbHalatFogtak();
    EredmenyHirdetes(EredmenyEnumerator ee);

private:
    EredmenyEnumerator eE;
};


#endif //BEADANDO2_EREDMENYHIRDETES_H

