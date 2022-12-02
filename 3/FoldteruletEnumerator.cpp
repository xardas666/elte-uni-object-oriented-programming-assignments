//
// Created by istvan.gottfried on 2021. 05. 02..
//

#include "FoldteruletEnumerator.h"

#include <utility>


FoldteruletEnumerator::FoldteruletEnumerator(vector<Foldterulet *> _foldteruletek) {
    foldteruletek = std::move(_foldteruletek);
    _length = foldteruletek.size();
    _currentPosition = 0;
    _end = false;
}

void FoldteruletEnumerator::first() {
    _currentPosition = 0;
}

Foldterulet*& FoldteruletEnumerator::current() {
    return foldteruletek.at(_currentPosition);
}

bool FoldteruletEnumerator::end() {
    if (_currentPosition == _length) {
        _end = true;
    } else {
        _end = false;
    }
    return _end;
}

void FoldteruletEnumerator::next() {
    _currentPosition++;
}

FoldteruletEnumerator::FoldteruletEnumerator() {

}

size_t FoldteruletEnumerator::currentPosition() {
    return _currentPosition;
}

Foldterulet *&FoldteruletEnumerator::at(size_t index) {
    _currentPosition = index;
    return current();
}


