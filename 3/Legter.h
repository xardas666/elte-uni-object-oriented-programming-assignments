//
// Created by gottf on 27/04/2021.
//

#ifndef BEAD_GI_3FS_1F_LEGTER_H
#define BEAD_GI_3FS_1F_LEGTER_H


class Legter {
public:
    ~Legter();
    Legter();
    void addParatartalom(int _paratartalom);
    void setParatartalom(int _paratartalom);
    int getParatartalom();
private:
    int paratartalom;
};


#endif //BEAD_GI_3FS_1F_LEGTER_H
