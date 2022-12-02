//
// Created by gottf on 03/04/2021.
//

#include "eredmeny.h"



Eredmeny::Eredmeny(string versenyzo, string verseny) {
    this->versenyzo=versenyzo;
    this->verseny=verseny;

}

void Eredmeny::addFogas(Fogas fogas) {
    this->fogasok.push_back(fogas);
}


ostream &operator<<(ostream &os, const Eredmeny &eredmeny) {
    os << "versenyzo: " << eredmeny.versenyzo << "\n" << "\tverseny: " << eredmeny.verseny << "\n" << "\tfogasok: \n" ;
    for(Fogas fogas : eredmeny.fogasok){
        os << fogas;
    }

    return os;
}

int Eredmeny::getFogasokSzama() {
    return fogasok.size();
}

string Eredmeny::getVerseny() {
    return this->verseny;
}

string Eredmeny::getVersenyzoAzonosito() {
    return this->versenyzo;
}

ostream &operator<<(ostream &os, const Fogas &fogas) {
    os << "\tmegnevezes: " << fogas.megnevezes << " suly: " << fogas.suly << "\n";
    return os;
}
