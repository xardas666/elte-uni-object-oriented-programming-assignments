//
// Created by gottf on 27/04/2021.
//

#include "Puszta.h"

void Puszta::idojarasHatas(IdojarasTipus _aktualisIdojaras) {
    if (_aktualisIdojaras == NAPOS) {
        addVizmennyiseg(-3);
    } else if (_aktualisIdojaras == ESOS) {
        addVizmennyiseg(5);
    } else if (_aktualisIdojaras == FELHOS) {
        addVizmennyiseg(1);
    }
}

int Puszta::paratartalomHatas() {
    return 3;
}

Puszta::Puszta(const string &nev, FoldteruletTipus tipus, int vizmennyiseg) : Foldterulet(nev, tipus, vizmennyiseg) {}

