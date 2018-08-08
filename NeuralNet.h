#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>

/** @file
 *
 *  ZetaNet - Custom Neural Network Project
 *
 *  @author Spencer D. Pauly
 *
 *  @date 7 Aug 2018
 *
 *  @version 6.1 */

#include "Matrix.h"
#include "MatrixTools.h"

using namespace std;


//NeuralNet Class

class NeuralNet {
    private:
        //Config file (unused currently)
        string configFile;

        //Data Files
        string inputFile;
        string outputFile;

        //Neural Net Shape
        std::vector<double> hiddenLayers;

        //Runtime Settings
        int iterations;
        int displayStep;
        string outputFormat;

        //Decide if data should be put between 0-1 when inputted into matrix
        bool normalize;

        //Debug settings
        bool showDebug;

        //Helper matrices
        Matrix Xoriginal;
        Matrix Yoriginal;
        Matrix X;
        Matrix Y;
        Matrix syn0;
        Matrix syn1;
        Matrix results;

        //MatrixTools library
        MatrixTools mt;

        //Private Methods

        /**
         * Will test the current neural network against a dataset using current weights
         * @pre Neural net MUST be trained
         * @post Will output on screen the resulting letters that the neural network guesses
         */
        void testAlgorithm();

        //trainIteration

        /**
         * Helping method to turn a vector from a type string to type double
         * @pre Data must each be numbers ex. 5.4594
         * @return New vector where each data value is a double
         */
        std::vector< std::vector<double> > vectorStod(std::vector< std::vector<string> > old);

    public:
        //Constructors
        NeuralNet();

        //Methods

        /**
         * Meant to be used to read from a config file with the neural network settings but instead
         * just sets the variables in a hard-coded fashion to initialize the neural network
         */
        void setConfig(string configFileLocation);

        /**
         * Will use TSVReader class to read the data from the defined input & output files
         * and put them into matrix form for neural network training
         * @pre setConfig must have been run to initialize neural network variables
         */
        void importData(); 
        
        /**
         * Will prepare neural network for running bu setting initial synapse values and data variables
         * @pre importData() must have been done to get the current dataset we want to run against
         */
        void initialize();
        
        /**
         * Run through X amount of iterations and train the neural network, this method does
         * all the heavy lifting of the program
         * @post Each weight should now be trained and optimized for the dataset
         */
        void train();
        
        /**
         * Will test the neural network using new input data from either the matrix or file specified
         * @pre NeuralNet must be trained and file/matrix must be same amount of columns as the inputData
         * the network was trained using
         * @post Should output the best guess for the neural network results out on the screen
         */
        Matrix test(string testFile);
        Matrix test(Matrix testMatrix);

        //Mutators

        /**
         * Will swap the input datafile and output datafile (for encoding and decoding) (UNUSED!!!)
         */
        bool swapInputOutput();

        //Accessors

        //Operator Overloads

};

#include "NeuralNet.cpp"

#endif // NEURALNET_H
