#ifndef MATRIXTOOLS_H
#define MATRIXTOOLS_H

#include <vector>
#include "Matrix.h"
#include <sstream>

class Matrix;

using namespace std;

//MatrixTools Class

class MatrixTools {
    private:
        bool canAdd(Matrix m1, Matrix m2);
        bool canSubtract(Matrix m1, Matrix m2);
        bool canMult(Matrix m1, Matrix m2);
        bool canDot(Matrix m1, Matrix m2);
        bool canAppend(Matrix m1, Matrix m2);
        int binaryToDecimal(int n);

        const double e = 2.71828182845904523536;


    public:
        //Constructors
        MatrixTools(){};

        //Methods
        Matrix add(Matrix m1, Matrix m2);
        Matrix subtract(Matrix m1, Matrix m2);
        Matrix mult(Matrix m1, Matrix m2);
        Matrix dot(Matrix m1, Matrix m2);

        Matrix scalarAdd(const Matrix m1, double val);
        Matrix scalarSubtract(const Matrix m1, double val);
        Matrix scalarMult(const Matrix m1, double val);

        Matrix sigmoid(Matrix old, bool deriv);
        Matrix unsigmoid(Matrix oldMatrix);
        Matrix transpose(Matrix oldMatrix);
        Matrix normalize(Matrix oldMatrix);
        Matrix roundToInt(Matrix oldMatrix);
        Matrix appendMatrix(Matrix m1, Matrix addedMatrix, int row);
        char binaryToLetter(Matrix binaryMatrix);

        Matrix addRow(Matrix oldMatrix, Matrix newRow);

        
        void print(Matrix oldMatrix);

        double mean(Matrix m1);
};

#include "MatrixTools.cpp"

#endif // MATRIXTOOLS_H
