//
// Created by gottf on 03/04/2021.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef BEADANDO2_EREDMENY_H
#define BEADANDO2_EREDMENY_H

struct Fogas {
    friend ostream &operator<<(ostream &os, const Fogas &fogas);



    string megnevezes;
    int suly;
};

class Eredmeny {
public:
    Eredmeny();
    string getVerseny();
    void addFogas(Fogas fogas);
    int getFogasokSzama();
    Eredmeny(string versenyzo, string verseny);
    string getVersenyzoAzonosito();
    friend ostream &operator<<(ostream &os, const Eredmeny &eredmeny);


private:
    string versenyzo;
    string verseny;
    vector<Fogas> fogasok;

};


#endif //BEADANDO2_EREDMENY_H
