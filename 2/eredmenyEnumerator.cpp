//
// Created by gottf on 03/04/2021.
//

#include "eredmenyEnumerator.h"


EredmenyEnumerator::EredmenyEnumerator(const std::string &fileName) {
    readFile(fileName);
    _length = eredmenyek.size();
}

void EredmenyEnumerator::first() {
    _currentPosition = 0;
    eredmenyek.at(_currentPosition);
}

Eredmeny EredmenyEnumerator::current() {
    return eredmenyek.at(_currentPosition);
}

bool EredmenyEnumerator::end() {
    if (_currentPosition == _length ) {
        _end = true;
    } else {
        _end = false;
    }
    return _end;
}

void EredmenyEnumerator::next() {
    _currentPosition += 1;
}

void EredmenyEnumerator::writeOutAllVersenyzo() {
    for(first();!end();next()){
        cout << current() << endl;
    }
}

void EredmenyEnumerator::readFile(string fileName) {
    ifstream file(fileName);
    string line;

    FILE *fileTest;
    if (fileTest = fopen(fileName.c_str(), "r")) {
        fclose(fileTest);
    } else {
        throw runtime_error("File doesn't exist");
    }

    while (getline(file, line)) {
        lineToData(line);
    }

    if(eredmenyek.size()==0){
        throw runtime_error("Could not open file or its empty");
    }
}

void EredmenyEnumerator::lineToData(string line) {
    size_t HORGASZ_NEV_INDEX = 0;
    size_t VERSENY_ID_INDEX = 1;

    istringstream iss(line);
    vector<string> parts((istream_iterator<string>(iss)), istream_iterator<string>());

    auto *eredmeny = new Eredmeny(parts.at(HORGASZ_NEV_INDEX), parts.at(VERSENY_ID_INDEX));

    parts.erase(parts.begin());
    parts.erase(parts.begin());

    if(parts.size()>0){
        string fogasMegnevezes;
        for (string part : parts) {
            Fogas fogas;

            if (!isNumber(part)) {
                fogasMegnevezes = part;
            } else {
                fogas.megnevezes = fogasMegnevezes;
                fogas.suly = stoi(part);
                eredmeny->addFogas(fogas);
            }
        }
    }



    eredmenyek.push_back(*eredmeny);
}

bool EredmenyEnumerator::isNumber(const string &str) {
    for (char const &c : str) {
        if (isdigit(c) == 0) {
            return false;
        }
    }
    return true;
}
