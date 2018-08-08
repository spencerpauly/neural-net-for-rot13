/** @file
 *
 *  ZetaNet - Custom Neural Network Project
 *
 *  @author Spencer D. Pauly
 *
 *  @date 7 Aug 2018
 *
 *  @version 6.1 */

#include <iostream>
#include <time.h>
#include <random>
#include <memory>
#include <vector>
#include <math.h>
#include <bitset>

#include "NeuralNet.h"

//Some hard-coded values necessary for success of the neural network (can be fixed but didn't have the time)
std::vector < std::vector<double> > testBinaryVec = { {0,1,1,0,0,0,1,0},
                                                    {0,1,1,1,1,0,1,0} };

std::vector < std::vector<double> > SPACE = { {1,1,1,1,1,0,1,1} };

std::vector < std::vector<double> > PERIOD = { {1,1,1,1,1,1,0,0} };

std::vector < std::vector<double> > COMMA = { {1,1,1,1,1,1,0,1} };

std::vector < std::vector<double> > EXCLAIMATION_POINT = { {1,1,1,1,1,1,1,0} };

std::vector < std::vector<double> > QUESTION_MARK = { {1,1,1,1,1,1,1,1} };

using namespace std;

/**
    * Stupidly long function that basically turns letter data stored in a string into binary values in each cell of a matrix
    * that can be used to run through the already-trained neural net. Needs to be optimized, shortened and stuck in a class
    * @pre oldMatrix must be the same height as the length of the number of characters in the input string & 8 columns long
    * to accomidate for 8-digit binary ex. [0,1,1,0,0,0,0,1]
    * @post will change values in inputted matrix to be in binary form and ready to be inputted into a trained neural net
*/

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

/*

--- Head/Body Split ---

*/

int main() 
{

    NeuralNet net;
    MatrixTools mt;

    //INITIALIZE
    net.setConfig("doesntmatter");
    net.importData();

    //TRAIN
    net.initialize();
    net.train();

    //TEST
    string userInput;
    cout << "enter string: " << endl;
    getline(cin, userInput);

    Matrix testMatrix(userInput.length(), 8);

    addString(testMatrix, userInput);

    net.test(testMatrix);


    return 0;

}
