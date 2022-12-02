//
// Created by gottf on 06/03/2021.
//

#include <vector>

using namespace std;

#ifndef BEAD_SAKKTABLA_MATRIX_H
#define BEAD_SAKKTABLA_MATRIX_H

struct Coordinates {
    int i;
    int j;
    int value;
};

struct MatrixSize {
    int m;
    int n;
};

struct MatrixException : public std::exception {

    const char *text;

    void setText(const char text[]) {
        this->text = text;
    }

    const char *what() const throw() {
        return text;
    }
};


class SakktablaMatrix {
public:
    SakktablaMatrix addition(SakktablaMatrix &matrix);

    int getValueByCordinate(int i, int j);

    SakktablaMatrix multiplication(SakktablaMatrix &matrix);

    void writeOutMatrix();

    SakktablaMatrix(int m, int n);

private:
    MatrixException matrixException;

    MatrixSize size();

    void createMatrix();

    void setValueByCordinate(int i, int j, int value);

    std::vector<Coordinates> coordinatesWithValue;
    MatrixSize matrixSize;
};


#endif //BEAD_SAKKTABLA_MATRIX_H
