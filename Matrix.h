/** @file
 *
 *  ZetaNet - Custom Neural Network Project
 *
 *  @author Spencer D. Pauly
 *
 *  @date 7 Aug 2018
 *
 *  @version 6.1 */

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

        /**
         * Private methods for checking if 2 matrices can do the defined action
         * @pre Need current matrix to be filled with data and second matrix sent in to compare with
         * @throw preconditionViolatedException if the data won't do the operation & stop the program
         */
        bool canAdd(Matrix m2);
        bool canSubtract(Matrix m2);
        bool canMult(Matrix m2);
        bool canDot(Matrix m2);

        /**
         * Unused method
         */
        void checkExtrema(double value);

    public:
        //Constructors
        Matrix();
        Matrix(int r, int c);

        //Debug Methods

        /**
         * Will randomize each value of the matrix to a random value between minVal & maxVal
         */
        void randomize(double minVal, double maxVal);

        /**
         * Print the matrix in a formatted way using cout
         */
        void print();

        //Methods

        /**
         * Resize matrix to the new size defined by the rows & cols parameters
         * @pre Must have a value that it wants for the new rows & new columns amount
         */
        bool resize(int newRows, int newCols);

        /**
         * Will clear ALL values in this matrix and set size to 0 x 0.
         */
        void clear();

        /**
         * Will turn a 2D STL vector into a matrix (good for bugtesting)
         * @pre Need 2D STL vector as input that has data in it and is of type double
         * @return boolean if the operation works correctly or not
         */
        bool vectorToMatrix(std::vector< std::vector<double> >  newMatrix);
        bool vectorToMatrix(std::vector< std::vector<double> >  newMatrix, int arrayRows, int arrayCols);
        
        /**
         * Will completely copy one matrix to this matrix (size is changed and curent data is lost)
         * @pre Need another matrix to copy into this matrix
         */
        bool copy(Matrix fromMatrix);

        /**
         * Will resize this to a 1xY matrix and copy another 1xY matrix into this matrix
         */
        bool copyLine(Matrix fromMatrix, int lineNumber);

        //Mutators

        /**
         * These will set specific values within this matrix according to the parameters
         * @return Nothing
         */
        void setMatrix(int rPos, int cPos, double value);
        void setAll(double value);
        void setRows(int newRowCount);
        void setCols(int newColCount);
        void setValue(int rPos, int cPos, double newValue);

        //Accessors

        /**
         * Will return the number of columns or rows this matrix has
         */
        int getRows();
        int getCols();

        /**
         * Will get the value at that specific spot in the matrix
         */
        double getValue(int rPos, int cPos);

        /**
         * Will loop through each value in matrix and return the mean of all values within the matrix
         * @pre Matrix needs values in it
         * @return Mean of each value in matrix
         */
        double getMean();

        //Operator Overloads

        /**
         * Do said operation on the current matrix and other input matrix
         * @pre other matrix must have data in it same with your matrix
         * @return New matrix with the result of the 2 matrices' math
         */
        Matrix operator+(Matrix rhs);
        Matrix operator-(Matrix rhs);
        Matrix operator*(Matrix rhs);
        void operator=(Matrix rhs);

};

#include "Matrix.cpp"

#endif // MATRIX_H
