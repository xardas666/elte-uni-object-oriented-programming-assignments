//
// Created by gottf on 27/04/2021.
//

#ifndef BEAD_GI_3FS_1F_PUSZTA_H
#define BEAD_GI_3FS_1F_PUSZTA_H

#include "Foldterulet.h"

class Puszta : public Foldterulet {
public:

    int paratartalomHatas() override;
    Puszta(const string &nev, FoldteruletTipus tipus, int vizmennyiseg);
    void idojarasHatas(IdojarasTipus _aktualisIdojaras) override;
};


#endif //BEAD_GI_3FS_1F_PUSZTA_H
