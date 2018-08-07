#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

using namespace std;


//Matrix Class

class Matrix {
    private:
        const double e = 2.71828182845904523536;
        int rows;
        int cols;

        std::vector< std::vector<double> > matrix; //2-Dimensional Vector

        bool canAdd(Matrix m2);
        bool canSubtract(Matrix m2);
        bool canMult(Matrix m2);
        bool canDot(Matrix m2);
        void checkExtrema(double value);

    public:
        //Constructors
        Matrix();
        Matrix(int r, int c);

        //Debug Methods
        void randomize(double minVal, double maxVal);
        void print();

        //Methods
        bool resize(int newRows, int newCols);
        void clear();
        bool vectorToMatrix(std::vector< std::vector<double> >  newMatrix);
        bool vectorToMatrix(std::vector< std::vector<double> >  newMatrix, int arrayRows, int arrayCols);
        bool copy(Matrix fromMatrix);
        bool copyLine(Matrix fromMatrix, int lineNumber);

        //Mutators
        void setMatrix(int rPos, int cPos, double value);
        void setAll(double value);
        void setRows(int newRowCount);
        void setCols(int newColCount);
        void setValue(int rPos, int cPos, double newValue);

        //Accessors
        int getRows();
        int getCols();
        double getValue(int rPos, int cPos);
        double getMean();

        //Operator Overloads
        Matrix operator+(Matrix rhs);
        Matrix operator-(Matrix rhs);
        Matrix operator*(Matrix rhs);
        void operator=(Matrix rhs);

};

#include "Matrix.cpp"

#endif // MATRIX_H
