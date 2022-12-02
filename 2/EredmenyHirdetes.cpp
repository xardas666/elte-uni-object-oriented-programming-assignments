//
// Created by gottf on 04/04/2021.
//

#include "EredmenyHirdetes.h"

VersenyHal EredmenyHirdetes::aVersenyAholALegtobbHalatFogtak() {
    vector<VersenyHal> vhv;
    eE.first();
    VersenyHal vh;
    vh.verseny = eE.current().getVerseny();
    vh.db = 0;
    vhv.push_back(vh);
    int index = 0;

    for (eE.first(); !eE.end(); eE.next()) {
        if (vhv.at(index).verseny == eE.current().getVerseny()) {
            vhv.at(index).db+=eE.current().getFogasokSzama();

        } else {
            VersenyHal uj;
            uj.verseny = eE.current().getVerseny();
            uj.db = eE.current().getFogasokSzama();
            vhv.push_back(uj);
            index++;
        }
    }

    int max = 0;
    int ind = 0;
    for (int i = 0; i < vhv.size(); i++) {
        if (vhv.at(i).db > max) {
            max = vhv.at(i).db;
            ind = i;
        }
    }

    cout << "A verseny ahol a legtöbb halat fogták: " << vhv.at(ind).verseny;

    return vhv.at(ind);
}

Eredmeny EredmenyHirdetes::egyHalatSeFogottElsoAListabol() {
    for (eE.first(); !eE.end(); eE.next()) {
        if (eE.current().getFogasokSzama() == 0) {
            cout << "Egy halat se fogott: " << eE.current().getVersenyzoAzonosito() <<" verseny: " << eE.current().getVerseny() << endl;
            return eE.current();
        }
    }
    throw runtime_error("Found none.");
}

EredmenyHirdetes::EredmenyHirdetes(EredmenyEnumerator ee) : eE(ee) {
    this->eE = ee;
}


ostream &operator<<(ostream &os, const VersenyHal &hal) {
    os << "verseny: " << hal.verseny << " db: " << hal.db;
    return os;
}