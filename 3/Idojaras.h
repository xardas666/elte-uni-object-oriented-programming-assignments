//
// Created by gottf on 27/04/2021.
//

#ifndef BEAD_GI_3FS_1F_IDOJARAS_H
#define BEAD_GI_3FS_1F_IDOJARAS_H

#include <random>
#include "iostream"

using namespace std;

enum IdojarasTipus {
    NAPOS, FELHOS, ESOS
};

class Idojaras {
public:
    ~Idojaras();
    IdojarasTipus idojarasKalkulacio(int _paratartalom);
    IdojarasTipus getAktualisIdojaras();
    bool paratartalomModositasKell();
    int ujParatartalom();
private:
    IdojarasTipus aktualisIdojaras;
};


#endif //BEAD_GI_3FS_1F_IDOJARAS_H
