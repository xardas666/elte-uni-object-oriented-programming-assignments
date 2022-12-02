//
// Created by gottf on 27/04/2021.
//

#ifndef BEAD_GI_3FS_1F_FOLDTERULET_H
#define BEAD_GI_3FS_1F_FOLDTERULET_H

#include <string>
#include <ostream>
#include "Idojaras.h"

using namespace std;

enum FoldteruletTipus {
    ZOLD, PUSZTA, TAVAS
};

class Foldterulet  {
public:
    ~Foldterulet();
    Foldterulet(string _nev, FoldteruletTipus _tipus, int _vizmennyiseg);
    int getVizmennyiseg() ;
    void addVizmennyiseg(int _vizmennyiseg);
    FoldteruletTipus getTipus();
    string getNev();
    virtual void idojarasHatas(IdojarasTipus _aktualisIdojaras) = 0;
    bool osztalyTipusEgyezes();
    virtual int paratartalomHatas() = 0;
    friend ostream &operator<<(ostream &os, const Foldterulet &foldterulet);
protected:
    void changeTipusByVizmennyiseg();
    int vizmennyiseg;
    FoldteruletTipus tipus;
    FoldteruletTipus originalTipus;
    string nev;
};



#endif //BEAD_GI_3FS_1F_FOLDTERULET_H
