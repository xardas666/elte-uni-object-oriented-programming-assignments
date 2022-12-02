//
// Created by gottf on 27/04/2021.
//

#include "Foldterulet.h"

int Foldterulet::getVizmennyiseg()  {
    return vizmennyiseg;
}

void Foldterulet::addVizmennyiseg(int _vizmennyiseg) {
    vizmennyiseg += _vizmennyiseg;
    if(vizmennyiseg<0){
        vizmennyiseg=0;
    }
    changeTipusByVizmennyiseg();
}

FoldteruletTipus Foldterulet::getTipus() {
    return tipus;
}

Foldterulet::~Foldterulet() {
//TODO
}

string Foldterulet::getNev() {
    return this->nev;
}

void Foldterulet::changeTipusByVizmennyiseg() {
    if (vizmennyiseg >= 51) {
        tipus = TAVAS;
    } else if (vizmennyiseg <= 50 && vizmennyiseg >= 16) {
        tipus = ZOLD;
    } else if (vizmennyiseg <= 15) {
        tipus = PUSZTA;
    }
}

bool Foldterulet::osztalyTipusEgyezes() {
    return originalTipus == tipus;
}

Foldterulet::Foldterulet(string _nev, FoldteruletTipus _tipus, int _vizmennyiseg) {
    nev = move(_nev);
   tipus = _tipus;
   originalTipus = _tipus;
   vizmennyiseg = _vizmennyiseg;
}

ostream &operator<<(ostream &os, const Foldterulet &foldterulet) {
    string tipus = "";
    if (foldterulet.tipus == PUSZTA) {
        tipus = "p";
    } else if (foldterulet.tipus == ZOLD) {
        tipus = "z";
    } else if (foldterulet.tipus == TAVAS) {
        tipus = "t";
    }

    os << foldterulet.nev << " " << tipus << " " << foldterulet.vizmennyiseg;
    return os;
}
