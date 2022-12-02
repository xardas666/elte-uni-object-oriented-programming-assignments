//
// Created by gottf on 27/04/2021.
//

#ifndef BEAD_GI_3FS_1F_ZOLD_H
#define BEAD_GI_3FS_1F_ZOLD_H
#include "Foldterulet.h"

class Zold : public Foldterulet {
public:
    Zold(const string &nev, FoldteruletTipus tipus, int vizmennyiseg);
    void idojarasHatas(IdojarasTipus _aktualisIdojaras) override;
    int paratartalomHatas() override;
};


#endif //BEAD_GI_3FS_1F_ZOLD_H
