//
// Created by gottf on 27/04/2021.
//

#include "Zold.h"


void Zold::idojarasHatas(IdojarasTipus _aktualisIdojaras) {
    if (_aktualisIdojaras == NAPOS) {
        addVizmennyiseg(-6);
    } else if (_aktualisIdojaras == ESOS) {
        addVizmennyiseg(10);
    } else if (_aktualisIdojaras == FELHOS) {
        addVizmennyiseg(2);
    }
}

int Zold::paratartalomHatas() {
    return 7;
}

Zold::Zold(const string &nev, FoldteruletTipus tipus, int vizmennyiseg) : Foldterulet(nev, tipus, vizmennyiseg) {}

