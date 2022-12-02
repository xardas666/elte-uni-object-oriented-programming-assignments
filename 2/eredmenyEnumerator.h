//
// Created by gottf on 03/04/2021.
//

#ifndef BEADANDO2_EREDMENYENUMERATOR_H
#define BEADANDO2_EREDMENYENUMERATOR_H
#include "eredmeny.cpp"
#include <iostream>
#include <sstream>
#include <regex>
#include <fstream>

using namespace std;

class EredmenyEnumerator {
public:
    EredmenyEnumerator(const std::string &fname);
    void first();
    Eredmeny current();
    bool end();
    void next();
    void writeOutAllVersenyzo();



private:
    void readFile(string fileName);
    void lineToData(string line);
    bool isNumber(const string &str);
    vector<Eredmeny> eredmenyek;
    int _currentPosition;
    int _length;
    bool _end;
};



#endif //BEADANDO2_EREDMENYENUMERATOR_H
