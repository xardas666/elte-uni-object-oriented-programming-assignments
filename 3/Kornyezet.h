//
// Created by istvan.gottfried on 2021. 05. 01..
//

#ifndef BEAD_GI_3FS_1F_KORNYEZET_H
#define BEAD_GI_3FS_1F_KORNYEZET_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include "Zold.h"
#include "Tavas.h"
#include "Puszta.h"
#include "Legter.h"
#include "Idojaras.h"
#include "FoldteruletEnumerator.h"
#include <cstdlib>

using namespace std;

struct ClimaModellException : public std::exception {

    const char *text;

    void setText(const char text[]) {
        this->text = text;
    }

    const char *what() const noexcept override {
        return text;
    }
};

class Kornyezet {
public:
    explicit Kornyezet(string fileName);
    void writeOutFoldteruletek();
    void playRoundsForTime(int _count);
    Foldterulet *&legnagyobbVizmennyiseguFoldterulet();
private:
    Legter legter;
    vector<Foldterulet*> foldteruletek;
    FoldteruletEnumerator fe;
    Idojaras idojaras;
    ClimaModellException climaModellException;
    void initObjectsFromFile(string fileName);
    void kifuzesEsBefuzes(Foldterulet *&foldterulet, size_t index);
    void lineToData(string line);
    void kor(int _count);


};


#endif //BEAD_GI_3FS_1F_KORNYEZET_H
