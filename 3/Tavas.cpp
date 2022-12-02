//
// Created by gottf on 27/04/2021.
//

#include "Tavas.h"

void Tavas::idojarasHatas(IdojarasTipus _aktualisIdojaras) {
    if (_aktualisIdojaras == NAPOS) {
        addVizmennyiseg(-10);
    } else if (_aktualisIdojaras == ESOS) {
        addVizmennyiseg(15);
    } else if (_aktualisIdojaras == FELHOS) {
        addVizmennyiseg(3);
    }
}

int Tavas::paratartalomHatas() {
    return 10;
}

Tavas::Tavas(const string &nev, FoldteruletTipus tipus, int vizmennyiseg) : Foldterulet(nev, tipus, vizmennyiseg) {}


