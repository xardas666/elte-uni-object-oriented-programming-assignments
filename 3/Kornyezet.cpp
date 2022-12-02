//
// Created by istvan.gottfried on 2021. 05. 01..
//
#include "Kornyezet.h"

void Kornyezet::writeOutFoldteruletek() {
    for (fe.first(); !fe.end(); fe.next()) {
        cout << *fe.current() << endl;
    }
}

Kornyezet::Kornyezet(string fileName) {
    this->legter = *new Legter();
    initObjectsFromFile(fileName);

    this->fe = *new FoldteruletEnumerator(foldteruletek);
}

void Kornyezet::playRoundsForTime(int _count) {
    for (int i = 0; i < _count; ++i) {
        cout << "----- Round: " << i + 1 << "/" << _count << " -----" << endl;
        kor(_count);
    }
}

void Kornyezet::kor(int _count) {

    idojaras.idojarasKalkulacio(legter.getParatartalom());

    if (idojaras.paratartalomModositasKell()) {
        legter.setParatartalom(idojaras.ujParatartalom());
    }

    for (fe.first(); !fe.end(); fe.next()) {
        fe.current()->idojarasHatas(idojaras.getAktualisIdojaras());

        if (!fe.current()->osztalyTipusEgyezes()) {
            kifuzesEsBefuzes(fe.current(), fe.currentPosition());
        }

        int paratartalom = fe.current()->paratartalomHatas();
        legter.addParatartalom(paratartalom);
    }

    writeOutFoldteruletek();
}

Foldterulet *&Kornyezet::legnagyobbVizmennyiseguFoldterulet() {
    int legnagyobbVizmennyiseg = 0;
    size_t index = 0;
    for (fe.first(); !fe.end(); fe.next()) {
        if (fe.current()->getVizmennyiseg() > legnagyobbVizmennyiseg) {
            legnagyobbVizmennyiseg = fe.current()->getVizmennyiseg();
            index = fe.currentPosition();
        }
    }
    cout << "------------------------" << endl;
    cout << "A legvizesebb foldterulet:" << endl;
    cout << *fe.at(index) << endl;

    return fe.at(index);
}

void Kornyezet::initObjectsFromFile(string fileName) {
    ifstream file(fileName);
    string line;
    bool isFirstLine = true;
    size_t dataCount = 0;
    size_t actualData = 0;

    FILE *fileTest;
    if (fileTest = fopen(fileName.c_str(), "r")) {
        fclose(fileTest);
    } else {
        climaModellException.setText("File doesn't exist");
        throw climaModellException;
    }

    while (getline(file, line)) {
        if (isFirstLine) {
            dataCount = stoi(line);
            isFirstLine = false;
        } else if (dataCount == actualData && !isFirstLine) {
            this->legter.setParatartalom(stoi(line));
        } else {
            actualData++;
            lineToData(line);
        }
    }

    if (foldteruletek.empty()) {
        climaModellException.setText("Could not open file or its empty.");
        throw climaModellException;
    }
}

void Kornyezet::lineToData(string line) {
    size_t MEGNEVEZES = 0;
    size_t TIPUS = 1;
    size_t VIZMENNYISEG = 2;

    istringstream iss(line);
    vector<string> parts((istream_iterator<string>(iss)), istream_iterator<string>());

    string megnevezes = parts[MEGNEVEZES];
    string tipusMarker = parts[TIPUS];
    int vizmennyiseg = stoi(parts[VIZMENNYISEG]);

    if (tipusMarker == "p") {
        FoldteruletTipus tipus = PUSZTA;
        auto *foldterulet = new Zold(megnevezes, tipus, vizmennyiseg);
        foldteruletek.push_back(foldterulet);
    } else if (tipusMarker == "z") {
        FoldteruletTipus tipus = ZOLD;
        auto *foldterulet = new Zold(megnevezes, tipus, vizmennyiseg);
        foldteruletek.push_back(foldterulet);
    } else if (tipusMarker == "t") {
        FoldteruletTipus tipus = TAVAS;
        auto *foldterulet = new Zold(megnevezes, tipus, vizmennyiseg);
        foldteruletek.push_back(foldterulet);
    }
}

void Kornyezet::kifuzesEsBefuzes(Foldterulet *&foldterulet, size_t index) {
    if (foldterulet->getTipus() == ZOLD) {
        foldteruletek[index] =
                new Zold(foldterulet->getNev(), foldterulet->getTipus(), foldterulet->getVizmennyiseg());
    } else if (foldterulet->getTipus() == TAVAS) {
        foldteruletek[index] =
                new Tavas(foldterulet->getNev(), foldterulet->getTipus(), foldterulet->getVizmennyiseg());
    } else if (foldterulet->getTipus() == PUSZTA) {
        foldteruletek[index] =
                new Puszta(foldterulet->getNev(), foldterulet->getTipus(), foldterulet->getVizmennyiseg());
    }
}