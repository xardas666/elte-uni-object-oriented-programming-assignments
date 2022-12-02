//
// Created by istvan.gottfried on 2021. 05. 02..
//

#ifndef BEAD_GI_3FS_1F_FOLDTERULETENUMERATOR_H
#define BEAD_GI_3FS_1F_FOLDTERULETENUMERATOR_H

#include <utility>
#include "Foldterulet.h"

using namespace std;

class FoldteruletEnumerator {
public:
    FoldteruletEnumerator();
    FoldteruletEnumerator(vector<Foldterulet*> _foldteruletek);
    void first();
    Foldterulet*& current();
    Foldterulet*& at(size_t index);
    bool end();
    void next();
    size_t currentPosition();

private:
    vector<Foldterulet*> foldteruletek;
    size_t _currentPosition;
    size_t _length;
    bool _end;
};


#endif //BEAD_GI_3FS_1F_FOLDTERULETENUMERATOR_H
