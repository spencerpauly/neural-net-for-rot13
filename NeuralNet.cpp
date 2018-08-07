#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <sstream>

#include "PrecondViolatedExcep.h"
#include "TSVReader.h"

using namespace std;


//Constructors
NeuralNet::NeuralNet() {

}

//Private Methods
void NeuralNet::testAlgorithm() {

    //Matrices Used:
    Matrix l0;
    Matrix l1;
    Matrix l2;

    //Layers
    l0 = X;
    l1 = mt.dot(l0, syn0);
    l1 = mt.sigmoid(l1);

    l2 = mt.dot(l1, syn1);
    l2 = mt.sigmoid(l2);

    results = mt.roundToInt(l2);

    char guess = mt.binaryToLetter(results);

    cout << guess;

    //results = mt.unsigmoid(results);

}

std::vector< std::vector<double> > NeuralNet::vectorStod(std::vector< std::vector<string> > old) {

    std::vector< std::vector<int> >::const_iterator row; 
    std::vector<int>::const_iterator col; 

    std::vector< std::vector<double> > newVector;
    newVector.resize(old.size() );

    for (int i = 0; i < old.size(); i++) {
        newVector[i].resize(old[i].size() );

        for (int j = 0; j < old[0].size(); j++) {
            newVector[i].at(j) = stod(old[i][j]);
        }
    }

    // //For debugging
    // for (int i = 0; i < newVector.size(); i++) {
    //     for (int j = 0; j < newVector[i].size(); j++) {
    //         cout << newVector[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return newVector;
}

//Debug Methods

//Methods
void NeuralNet::setConfig(string configFileLocation) {
    
    configFile = configFileLocation;

    /*
    ifstream inFile;
    inFile.open(configFile.c_str() );
    if (inFile) {
        while (getline(inFile, line) ) {
        }
        inFile.close();
    } else {
            string message("File not found! ");
    throw PrecondViolatedExcep(message);
    }
    */

    inputFile = "alphabetInputBinaryNEW.tsv";
    outputFile = "alphabetOutputBinaryNEW.tsv";

    hiddenLayers.push_back(30);

    iterations = 3000;
    displayStep = 100;
    outputFormat = "print";

    normalize = false;
    showDebug = true;

}

void NeuralNet::importData() {

    TSVReader tsvreader;

    Xoriginal.vectorToMatrix(vectorStod(tsvreader.import(inputFile) ));
    Yoriginal.vectorToMatrix(vectorStod(tsvreader.import(outputFile) ));

    X.copy(Xoriginal);
    Y.copy(Yoriginal);

    if (normalize) {
        X = mt.normalize(X);
        Y = mt.normalize(Y);
    }

}

void NeuralNet::initialize() {

    srand(time(0));

    //Synapses
    syn0.resize(X.getCols(), X.getRows() );
    syn1.resize(syn0.getCols(), Y.getCols());

    //Bias & Stuff
    syn0.randomize();
    syn1.randomize();


    syn0 = mt.scalarMult(syn0, 2);
    syn1 = mt.scalarMult(syn1, 2);

    syn0 = mt.scalarSubtract(syn0, 1);
    syn1 = mt.scalarSubtract(syn1, 1);

}

void NeuralNet::train() {

    for (int i = 0; i < iterations; i++) {
        
        //Matrices Used:
        Matrix l0;
        Matrix l1;
        Matrix l2;

        Matrix l2_error;
        Matrix l2_delta;

        Matrix l1_error;
        Matrix l1_delta;

        //Layers
        l0 = X;
        l1 = mt.dot(l0, syn0);
        l1 = mt.sigmoid(l1);

        l2 = mt.dot(l1, syn1);
        l2 = mt.sigmoid(l2);

        //Backpropogation

        // Debugging
        // l0.print();
        // l1.print();
        // l2.print();

        l2_error = mt.subtract(Y, l2);

        if ( (i % displayStep) == 0 && showDebug == true) {
            cout << "Error at iteration " << i  << ": " << abs(100*mt.mean(l2_error)) << "%" <<endl;
            
        }

        //Calculate Deltas
        l2_delta = mt.mult(l2_error, mt.sigmoid(l2, true));
        l1_error = mt.dot(l2_delta, mt.transpose(syn1) );
        l1_delta = mt.mult(l1_error, mt.sigmoid(l1, true));

        //Update Synapses
        syn1 = syn1 + mt.dot(mt.transpose(l1), l2_delta);
        syn0 = syn0 + mt.dot(mt.transpose(l0), l1_delta); 

        results = l2;

    }


}

Matrix NeuralNet::test(string testFile) {

    TSVReader tsvreader2;
    Matrix XNew;
    std::vector< std::vector<double> > test = vectorStod(tsvreader2.import(testFile) );
    XNew.vectorToMatrix(test);
    X.copy(XNew);

    if (normalize) {
        X = mt.normalize(X);
    }
    
    testAlgorithm();

    return results;

}

Matrix NeuralNet::test(Matrix testMatrix) {

    results.clear();
    results.resize(0,Y.getCols());

    for (int i = 0; i < testMatrix.getRows(); i++) {
        X.copyLine(testMatrix, i);

        if (normalize) {
            X = mt.normalize(X);
        }

        testAlgorithm();
    }
    
    return results;

}

//Mutators
bool NeuralNet::swapInputOutput() {
    string temp = inputFile;
    inputFile = outputFile;
    outputFile = temp;
}


//Operator Overloads



