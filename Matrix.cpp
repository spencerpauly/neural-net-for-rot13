#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

#include "PrecondViolatedExcep.h"

using namespace std;


//Constructors

Matrix::Matrix() {
    
    rows = 0;
    cols = 0;
}


Matrix::Matrix(int r, int c) {

    rows = r;
    cols = c;

    //Set # of rows for matrix
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        //Set # of columns for matrix
        matrix[i].resize(cols);
    }
}

//Private Methods
bool Matrix::canAdd(Matrix m2) {

    if (rows != m2.getRows() || cols != m2.getCols() ) {
        string message("Matrix class overloaded '+' operator called with invalid Matrices. ");
        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool Matrix::canSubtract(Matrix m2) {

    if (rows != m2.getRows() || cols != m2.getCols() ) {
        string message("Matrix class overloaded '-' operator called with invalid Matrices. ");
        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool Matrix::canMult(Matrix m2) {

    if (rows != m2.getRows() || cols != m2.getCols() ) {
        string message("Matrix class overloaded '*' operator called with invalid Matrices of size: ");
        message += to_string(rows);
        message += "x";
        message += to_string(cols);
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());

        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool Matrix::canDot(Matrix m2) {

    if (cols != m2.getRows() ) {
        string message("Matrix class overloaded dot product operator called with invalid Matrices of size: ");
        message += to_string(rows);
        message += "x";
        message += to_string(cols);
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());

        throw PrecondViolatedExcep(message);
    }

    return true;
}


//Debug Methods
void Matrix::randomize(double minVal = 0.0, double maxVal = 1.0) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double newRand = (double)rand() / RAND_MAX;
            matrix[i][j] = minVal + newRand * (maxVal - minVal); 
        }
    }

}

void Matrix::print() {
    
    for (int i = 0; i < rows; i++) {
        cout << " [";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "]" << endl;
    }

    cout << endl;

}

//Methods
bool Matrix::resize(int newRows, int newCols) {

    rows = newRows;
    cols = newCols;

    matrix.clear();

    //Set # of rows for matrix
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        //Set # of columns for matrix
        matrix[i].resize(cols);
    }

    return true;
}  

void Matrix::clear() {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    resize(0,0);

}

bool Matrix::vectorToMatrix(std::vector< std::vector<double> >  newMatrix) {

    resize(newMatrix.size(), newMatrix[0].size());

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }

}

bool Matrix::vectorToMatrix(std::vector< std::vector<double> >  newMatrix, int arrayRows, int arrayCols) {

    resize(arrayRows, arrayCols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }


}

bool Matrix::copy(Matrix fromMatrix) {

    resize(fromMatrix.getRows(), fromMatrix.getCols() );
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = fromMatrix.getValue(i, j);
        }
    }

}

bool Matrix::copyLine(Matrix fromMatrix, int lineNumber) {

    resize(1, fromMatrix.getCols());
    
    for (int j = 0; j < cols; j++) {
        matrix[0][j] = fromMatrix.getValue(lineNumber, j);
    }

}



//Mutators
void Matrix::setMatrix(int rPos, int cPos, double value) {
    matrix[rPos][cPos] = value;
}

void Matrix::setAll(double value) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }

}

void Matrix::setRows(int newRowCount) {
    resize(newRowCount, cols);
}

void Matrix::setCols(int newColCount) {
    resize(rows, newColCount);
}

void Matrix::setValue(int rPos, int cPos, double newValue) {
    matrix[rPos][cPos] = newValue;
}


//Accessors
int Matrix::getRows() {
    return rows;
}

int Matrix::getCols() {
    return cols;
}

double Matrix::getValue(int rPos, int cPos) {
    return matrix[rPos][cPos];
}

double Matrix::getMean() {

    double mean = 0;
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            count++;
            mean += matrix[i][j];
        }
    }
    mean = mean/count;
    return mean;

}


//Operator Overloads
Matrix Matrix::operator+(Matrix rhs) {

    canAdd(rhs);

    Matrix newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double newVal = matrix[i][j] + rhs.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }

    return newMatrix;
}

Matrix Matrix::operator-(Matrix rhs) {

    canSubtract(rhs);

    Matrix newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double newVal = matrix[i][j] - rhs.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }

    return newMatrix;
}

Matrix Matrix::operator*(Matrix rhs) {

    canMult(rhs);

    Matrix newMatrix(rows, rhs.getCols() );
    newMatrix.setAll(0);

    //Loop through the # of rows of Matrix1
    for (int i = 0; i < rows; i++) {
        //Loop through # of cols of Matrix2
        for (int j = 0; j < cols; j++) {
            newMatrix.setValue(i,j, matrix[i][j] * rhs.getValue(i,j) );
        }
    }

    return newMatrix;
}


void Matrix::operator=(Matrix rhs) {
    copy(rhs);
}





