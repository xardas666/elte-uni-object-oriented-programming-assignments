//
// Created by gottf on 27/04/2021.
//

#include "Legter.h"

Legter::Legter() {
//todo
}

Legter::~Legter() {
//todo
}

void Legter::addParatartalom(int _paratartalom) {
    paratartalom +=_paratartalom;
    if(paratartalom<0){
        paratartalom=0;
    }
}

int Legter::getParatartalom() {
    return paratartalom;
}

void Legter::setParatartalom(int _paratartalom) {
    paratartalom = _paratartalom;
}
