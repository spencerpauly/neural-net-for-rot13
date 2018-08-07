#include <iostream>
#include <time.h>
#include <random>
#include <memory>
#include <vector>
#include <math.h>
#include <bitset>

#include "NeuralNet.h"

std::vector < std::vector<double> > testBinaryVec = { {0,1,1,0,0,0,1,0},
                                                    {0,1,1,1,1,0,1,0} };

std::vector < std::vector<double> > SPACE = { {1,1,1,1,1,0,1,1} };

std::vector < std::vector<double> > PERIOD = { {1,1,1,1,1,1,0,0} };

std::vector < std::vector<double> > COMMA = { {1,1,1,1,1,1,0,1} };

std::vector < std::vector<double> > EXCLAIMATION_POINT = { {1,1,1,1,1,1,1,0} };

std::vector < std::vector<double> > QUESTION_MARK = { {1,1,1,1,1,1,1,1} };


using namespace std;


void addString(Matrix& oldMatrix, string input) {
    
    MatrixTools mt;

    int curRow = 0;

    for (int i = 0; i < input.length(); i++) {

        char letter = input.at(i);
        int ascii = (int)(letter);

        Matrix addedMatrix;

        if (letter == ' ') {

            addedMatrix.vectorToMatrix(SPACE);
            oldMatrix = mt.appendMatrix(oldMatrix, addedMatrix, i);

        } else if (letter == '.') {

            addedMatrix.vectorToMatrix(PERIOD);
            oldMatrix = mt.appendMatrix(oldMatrix, addedMatrix, i);

        } else if (letter == ',') {

            addedMatrix.vectorToMatrix(COMMA);
            oldMatrix = mt.appendMatrix(oldMatrix, addedMatrix, i);

        } else if (letter == '!') {

            addedMatrix.vectorToMatrix(EXCLAIMATION_POINT);
            oldMatrix = mt.appendMatrix(oldMatrix, addedMatrix, i);

        } else if (letter == '?') {

            addedMatrix.vectorToMatrix(QUESTION_MARK);
            oldMatrix = mt.appendMatrix(oldMatrix, addedMatrix, i);
        
        } else {
            std::bitset<8> binaryVal = bitset<8>(ascii);

            for (int j = 0; j < 8; j++) {

                if (letter >= 65 && letter <=90 && j == 2) { //If capital letter && 3rd digit
                    oldMatrix.setValue(curRow, j, 1);
                } else {
                    oldMatrix.setValue(curRow, j, binaryVal[7-j]);
                }
            }
        }

        curRow++;

    }

}

int main() 
{

    NeuralNet net;
    MatrixTools mt;

    net.setConfig("doesntmatter");

    net.importData();

    net.initialize();

    net.train();

    //net.test("xorTest0.tsv");

    
    //Testing Part
    
    string userInput;
    cout << "enter string: " << endl;
    getline(cin, userInput);

    Matrix testMatrix(userInput.length(), 8);

    addString(testMatrix, userInput);
    // cout << "Input Binary: ";
    // testMatrix.print();
    net.test(testMatrix);

    // Matrix testMat;
    // testMat.vectorToMatrix(testBinaryVec);

    // //testMat = mt.transpose(testMat);
    // //net.test(testMat);



    return 0;

}
