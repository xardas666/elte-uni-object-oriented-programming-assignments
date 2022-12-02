
#include "sakktabla_matrix.h"


void SakktablaMatrix::writeOutMatrix() {
    for (int i = 0; i < matrixSize.m; i++) {
        for (int j = 0; j < matrixSize.n; j++) {
            std::cout << getValueByCordinate(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int SakktablaMatrix::getValueByCordinate(int i, int j) {
    if ((i > matrixSize.m || i < 0) || (j > matrixSize.n || j < 0)) {
        matrixException.setText("A koordináták nagyobbak/kisebbek mint a mátrix mérete!");
        throw matrixException;
    }
    int value = 0;
    for (int x = 0; x < coordinatesWithValue.size(); x++) {
        if (coordinatesWithValue.at(x).i == i
            && coordinatesWithValue.at(x).j == j) {
            value = coordinatesWithValue.at(x).value;
        }
    }
    return value;
}

SakktablaMatrix::SakktablaMatrix(int m, int n) {
    if ((m <= 0) || (n <= 0)) {
        matrixException.setText("A mátrix minimum 1x1-es lehet!");
        throw matrixException;
    }
    matrixSize.m = m;
    matrixSize.n = n;
    createMatrix();
}

void SakktablaMatrix::createMatrix() {
    for (int i = 0; i < matrixSize.m; i++) {
        for (int j = 0; j < matrixSize.n; j++) {
            if ((i + j) % 2 == 0) {
                Coordinates coordinates = {i, j, 1};
                coordinatesWithValue.push_back(coordinates);
            }
        }
    }
}

void SakktablaMatrix::setValueByCordinate(int i, int j, int value) {
    if ((i > matrixSize.m || i < 0) || (j > matrixSize.n || j < 0)) {
        matrixException.setText("A koordináták nagyobbak/kisebbek mint a mátrix mérete!");
        throw matrixException;
    }
    bool found = false;
    for (int x = 0; x < coordinatesWithValue.size(); x++) {
        if (coordinatesWithValue.at(x).i == i && coordinatesWithValue.at(x).j == j) {
            coordinatesWithValue.at(x).value = value;
            found = true;
        }
    }
    if (!found) {
        Coordinates coordinates = {i, j, value};
        coordinatesWithValue.push_back(coordinates);
    }
}

SakktablaMatrix SakktablaMatrix::addition(SakktablaMatrix &matrix) {

    //ellenörzés két mátrixnak azonosnak kell lennie méretben
    if (this->size().m != matrix.size().m || this->size().n != matrix.size().n) {
        matrixException.setText("A két mátrixnak összeadáshoz azonosnak kell lennie méretben!");
        throw matrixException;
    }

    SakktablaMatrix result = SakktablaMatrix(matrixSize.m, matrixSize.n);

    for (int i = 0; i < matrixSize.m; i++) {
        for (int j = 0; j < matrixSize.n; j++) {
            int value = this->getValueByCordinate(i, j) + matrix.getValueByCordinate(i, j);
            result.setValueByCordinate(i, j, value);
        }
    }
    return result;
}

SakktablaMatrix SakktablaMatrix::multiplication(SakktablaMatrix &matrix) {
    //ellenörzés két mátrixnak azonosnak kell lennie méretben
    if (this->size().m != matrix.size().n || this->size().n != matrix.size().m) {
        matrixException.setText("Az első mátrix oszlopszámának meg kell egyeznie a második mátrix sorszámával!");
        throw matrixException;
    }

    SakktablaMatrix result = SakktablaMatrix(this->size().m, matrix.size().n);

    for (int i = 0; i < this->size().m; ++i) {
        for (int j = 0; j < matrix.size().n; ++j) {
            for (int k = 0; k < this->size().n; ++k) {
                int value = result.getValueByCordinate(i, j) +
                            this->getValueByCordinate(i, k) * matrix.getValueByCordinate(k, j);
                result.setValueByCordinate(i, j, value);
            }
        }
    }
    return result;
}

MatrixSize SakktablaMatrix::size() {
    return matrixSize;
}
