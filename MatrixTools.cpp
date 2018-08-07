
#include "PrecondViolatedExcep.h"
#include "Matrix.h"
#include <sstream>

class Matrix;

using namespace std;


//Private Methods
bool MatrixTools::canAdd(Matrix m1, Matrix m2) {

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols() ) {
        string message("MatrixTools::add() called with invalid Matrices: ");
        message += to_string(m1.getRows());
        message += "x";
        message += to_string(m1.getCols());
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());
        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool MatrixTools::canSubtract(Matrix m1, Matrix m2) {

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols() ) {
        string message("MatrixTools::subtract() called with invalid Matrices: ");
        message += to_string(m1.getRows());
        message += "x";
        message += to_string(m1.getCols());
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());

        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool MatrixTools::canMult(Matrix m1, Matrix m2) {

    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols() ) {
        string message("MatrixTools::scalarMult() called with invalid Matrices: ");
        message += to_string(m1.getRows());
        message += "x";
        message += to_string(m1.getCols());
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());
        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool MatrixTools::canDot(Matrix m1, Matrix m2) {

    if (m1.getCols() != m2.getRows() ) {
        string message("MatrixTools::dot() called with invalid Matrices of size: ");
        message += to_string(m1.getRows());
        message += "x";
        message += to_string(m1.getCols());
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());

        throw PrecondViolatedExcep(message);
    }

    return true;
}

bool MatrixTools::canAppend(Matrix m1, Matrix m2) {

    if (m1.getCols() != m2.getCols() ) {
        string message("Matrix class overloaded matrixAppend operator called with invalid Matrices of size: ");
        message += to_string(m1.getRows());
        message += "x";
        message += to_string(m1.getCols());
        message += " & ";
        message += to_string(m2.getRows());
        message += "x";
        message += to_string(m2.getCols());

        throw PrecondViolatedExcep(message);
    }

    return true;
}

int MatrixTools::binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
     
    // Initializing base value to 1, i.e 2^0
    int base = 1;
     
    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp/10;
         
        dec_value += last_digit*base;
         
        base = base*2;
    }
     
    return dec_value;
}


//Methods
Matrix MatrixTools::add(Matrix m1, Matrix m2) {

    canAdd(m1,m2);

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            double newVal = m1.getValue(i,j) + m2.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }
    return newMatrix;

}

Matrix MatrixTools::subtract(Matrix m1, Matrix m2) {

    canSubtract(m1,m2);

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            double newVal = m1.getValue(i,j) - m2.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }
    return newMatrix;

}

Matrix MatrixTools::mult(Matrix m1, Matrix m2) {

    canMult(m1,m2);

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            double newVal = m1.getValue(i,j) * m2.getValue(i,j);

            newMatrix.setValue(i,j, newVal);
        }
    }
    return newMatrix;
}

Matrix MatrixTools::dot(Matrix m1, Matrix m2) {

    canDot(m1,m2);

    Matrix newMatrix(m1.getRows(), m2.getCols() );
    newMatrix.setAll(0);

    double newVal(0);

    //Loop through the # of rows of Matrix1
    for (int i = 0; i < m1.getRows(); i++) {
        //Loop through # of cols of Matrix2
        for (int j = 0; j < m2.getCols(); j++) {
            //Loop through # of cols of Matrix1
            for (int k = 0; k < m1.getCols(); k++) {
                newVal = m1.getValue(i,k) * m2.getValue(k,j);

                newMatrix.setValue(i,j, newMatrix.getValue(i,j) + newVal);
            }
        }
    }

    return newMatrix;

}

Matrix MatrixTools::scalarAdd(Matrix m1, double val) {

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            newMatrix.setValue(i,j, m1.getValue(i,j) + val);

        }
    }
    return newMatrix;
}

Matrix MatrixTools::scalarSubtract(Matrix m1, double val) {

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            newMatrix.setValue(i,j, m1.getValue(i,j) - val);
            
        }
    }
    return newMatrix;
}

Matrix MatrixTools::scalarMult(Matrix m1, double val) {

    Matrix newMatrix(m1.getRows(), m1.getCols() );

    for (int i = 0; i < m1.getRows(); i++) {
        for (int j = 0; j < m1.getCols(); j++) {
            newMatrix.setValue(i,j, m1.getValue(i,j) * val);
            
        }
    }
    return newMatrix;
}


Matrix MatrixTools::sigmoid(Matrix old, bool deriv = false) {

    int rows = old.getRows();
    int cols = old.getCols();

    Matrix newMatrix(rows, cols);

    double oldVal;
    double newVal;
    
    if (deriv == true) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                oldVal = old.getValue(i,j);
                newVal = oldVal * (1-oldVal);
                
                newMatrix.setValue(i, j, newVal);
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                oldVal = old.getValue(i,j);
                newVal =  (1 / (1 + pow(e,-oldVal)));
                newMatrix.setValue(i, j, newVal);
            }
        }
    }

    return newMatrix;
}

Matrix MatrixTools::unsigmoid(Matrix oldMatrix) {

    int rows = oldMatrix.getRows();
    int cols = oldMatrix.getCols();

    Matrix newMatrix(rows, cols);

    double oldVal;
    double newVal;
    

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            oldVal = oldMatrix.getValue(i,j) / (1 - (oldMatrix.getValue(i,j)) );
            newVal =  log(oldVal);
            newMatrix.setValue(i, j, newVal);
        }
    }

    return newMatrix;
}

Matrix MatrixTools::transpose(Matrix oldMatrix) {

    int rows = oldMatrix.getRows();
    int cols = oldMatrix.getCols();

    Matrix newMatrix(cols, rows);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix.setValue(j, i, oldMatrix.getValue(i,j));
        }
    }

    return newMatrix;
}

double MatrixTools::mean(Matrix m1) {
    return m1.getMean();

}

Matrix MatrixTools::normalize(Matrix oldMatrix) {

    int rows = oldMatrix.getRows();
    int cols = oldMatrix.getCols();

    Matrix newMatrix(rows, cols);

    double minVal = oldMatrix.getValue(0,0);
    double maxVal = oldMatrix.getValue(0,0);

    double currentVal;
    double lengthCount;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            currentVal = oldMatrix.getValue(i,j);
            lengthCount++;

            if (currentVal >= maxVal) {
                maxVal = currentVal;
            }

            if (currentVal <= minVal) {
                minVal = currentVal;
            }
        }
    }

    if (maxVal == minVal) {

        double temp = 1/lengthCount;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                newMatrix.setValue(i,j, temp);
            }
        }

    } else {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                double temp = (oldMatrix.getValue(i,j) - minVal) / (maxVal - minVal);

                newMatrix.setValue(i,j, temp);
            }
        }
    }

    return newMatrix;

}

void MatrixTools::print(Matrix oldMatrix) {

    int rows = oldMatrix.getRows();
    int cols = oldMatrix.getCols();

    for (int i = 0; i < rows; i++) {
        cout << " [";
        for (int j = 0; j < cols; j++) {
            cout << oldMatrix.getValue(i,j) << "\t";
        }
        cout << "]" << endl;
    }

    cout << endl;

}

Matrix MatrixTools::roundToInt(Matrix oldMatrix) {

    int rows = oldMatrix.getRows();
    int cols = oldMatrix.getCols();

    Matrix newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (oldMatrix.getValue(i,j) >= .25) {
                newMatrix.setValue(i, j, 1);

            } else {
                newMatrix.setValue(i, j, 0);

            }
        }
    }

    //Debug
    // oldMatrix.print();

    return newMatrix;

}

Matrix MatrixTools::addRow(Matrix oldMatrix, Matrix newRow) {

    int rows = oldMatrix.getRows()+1;
    int cols = oldMatrix.getCols();

    Matrix newMatrix(rows, cols);

    for (int i = 0; i < rows-1; i++) {
        for (int j = 0; j < cols; j++) {
            newMatrix.setValue(i, j, oldMatrix.getValue(i,j));
        
        }
    }

    for (int i = 0; i < cols; i++) {
        newMatrix.setValue(rows-1, i, newRow.getValue(0,i));
    }

    return newMatrix;

}

char MatrixTools::binaryToLetter(Matrix binaryMatrix) {

        // //Debug
    // cout << " Output Binary: ";
    // fromMatrix.print();

    stringstream ss;

    for (int i = 0; i < binaryMatrix.getCols(); i++) {
        ss << binaryMatrix.getValue(0,i);
    }

    string currLetter(ss.str());

    int currNum = binaryToDecimal(stoi(currLetter));
    // cout << "CURRNUM: " << currNum << endl;
    char returnVal;


    if (currNum == 96) {
        returnVal = 'p';
    } else if (currNum == 123) {
        returnVal = ' ';
    } else if (currNum == 124) {  
        returnVal = '.';
    } else if (currNum == 125) {
        returnVal = ',';
    } else if (currNum == 126) {
        returnVal = '!';
    } else if (currNum == 127) {
        returnVal = '?';
    } else if (currNum == 7) {
        returnVal = '\'';
    } else if (currNum == 127) {
        returnVal = '?';
    } else {
        returnVal = (char)currNum;
    }

    return returnVal;

}


Matrix MatrixTools::appendMatrix(Matrix m1, Matrix addedMatrix, int row) {

    canAppend(m1, addedMatrix);

    for (int j = 0; j < m1.getCols(); j++) {

        m1.setValue(row, j, addedMatrix.getValue(0,j) );
    }

    return m1;

}