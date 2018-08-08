/** @file
 *
 *  ZetaNet - Custom Neural Network Project
 *
 *  @author Spencer D. Pauly
 *
 *  @date 7 Aug 2018
 *
 *  @version 6.1 */

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

        /**
         * Check to see if this operation can be done on the current 2 matrices
         */
        bool canAdd(Matrix m1, Matrix m2);
        bool canSubtract(Matrix m1, Matrix m2);
        bool canMult(Matrix m1, Matrix m2);
        bool canDot(Matrix m1, Matrix m2);
        bool canAppend(Matrix m1, Matrix m2);

        /**
         * Will convert binary integer values to decimal. Ex: 00000010 -> 2
         * @pre Binary number in int format
         * @return Decimal value of whatever binary integer was inputted
         */
        int binaryToDecimal(int n);

        const double e = 2.71828182845904523536;


    public:
        //Constructors
        MatrixTools(){};

        //Methods

        /**
         * Perform mathematic operations on two matrices. 
         * mult = By-value multiplication
         * dot = dot-product multiplication
         * @return New matrix with data containing result of two matrices after operation is applied
         */
        Matrix add(Matrix m1, Matrix m2);
        Matrix subtract(Matrix m1, Matrix m2);
        Matrix mult(Matrix m1, Matrix m2);
        Matrix dot(Matrix m1, Matrix m2);

        /**
         * Will perform math operations on each cell of a matrix from a specified value of type double
         * @pre Matrix must contain values, val must not be 0
	     * @post
         * @return New matrix with results of operation
         */
        Matrix scalarAdd(const Matrix m1, double val);
        Matrix scalarSubtract(const Matrix m1, double val);
        Matrix scalarMult(const Matrix m1, double val);

        /**
         * Perform mathematic operations on the specified matrix
         * @return New matrix after operation is performed
         */
        Matrix sigmoid(Matrix old, bool deriv);
        Matrix unsigmoid(Matrix oldMatrix);
        Matrix transpose(Matrix oldMatrix);

        /**
         * Normalize all values of the matrix between 0-1
         * @return New matrix with each cell normalized
         */
        Matrix normalize(Matrix oldMatrix);

        /**
         * Will round the values of the matrix to 0 if < .5 and 1 if >= .5
         * @return New matrix with solid integer rounded values
         */
        Matrix roundToInt(Matrix oldMatrix);

        /**
         * Create a new matrix with the values of m1 and m2 added as another row to the end of m1
         * @pre m1 & m2 must have the same amount of cols, m2 must be 1 cell tall (rows = 1)
         * @return New matrix of new size with m2 added to the end of it
         */
        Matrix appendMatrix(Matrix m1, Matrix addedMatrix, int row);

        /**
         * Will convert a matrix where each cell is 1 letter of binary of the ASCII value the number converts to
         * @pre Matrix must be 1 tall, and 8 wide
	     * @post
         * @return Letter that the binary code corresponds to
         */
        char binaryToLetter(Matrix binaryMatrix);

        /**
         * Create a new matrix with the values of m1 and m2 added as another row to the end of m1
         * @pre m1 & m2 must have the same amount of cols, m2 must be 1 cell tall (rows = 1)
         * @return New matrix of new size with m2 added to the end of it
         */
        Matrix addRow(Matrix oldMatrix, Matrix newRow);

        /**
         * Will print out the matrix in formatted style
         */
        void print(Matrix oldMatrix);

        /**
         * Will find the mean of all the values within m1
         * @pre Matrix must not be empty
         * @return mean of all values
         */
        double mean(Matrix m1);
};

#include "MatrixTools.cpp"

#endif // MATRIXTOOLS_H
