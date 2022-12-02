//
// Created by gottf on 27/04/2021.
//

#include "Idojaras.h"

IdojarasTipus Idojaras::idojarasKalkulacio(int _paratartalom) {
    if(_paratartalom>70){
        aktualisIdojaras = ESOS;
        return aktualisIdojaras;
    } else if(_paratartalom<40){
        aktualisIdojaras = NAPOS;
        return aktualisIdojaras;
    } else {
        static std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution (0.0f,100.0f);
        float random = distribution(generator);

        float limit = ((float)_paratartalom-40.0f)*3.3f;

        if(random <= limit){
            aktualisIdojaras = ESOS;
            return aktualisIdojaras;
        } else {
            aktualisIdojaras = FELHOS;
            return aktualisIdojaras;
        }
    }
}

Idojaras::~Idojaras() {
//todo
}

IdojarasTipus Idojaras::getAktualisIdojaras() {
    return aktualisIdojaras;
}

bool Idojaras::paratartalomModositasKell() {
    return aktualisIdojaras==ESOS;
}

int Idojaras::ujParatartalom() {
    return 30;
}




