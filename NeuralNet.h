#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>

#include "Matrix.h"
#include "MatrixTools.h"

using namespace std;


//NeuralNet Class

class NeuralNet {
    private:
        string configFile;

        //Data Input
        string inputFile;
        //string inputRange
        string outputFile;
        //string outputRange

        //Neural Net Shape
        std::vector<double> hiddenLayers;

        //Runtime Settings
        int iterations;
        int displayStep;
        string outputFormat;

        bool normalize;

        //Debug settings
        bool showDebug;

        Matrix Xoriginal;
        Matrix Yoriginal;

        Matrix X;
        Matrix Y;
        Matrix syn0;
        Matrix syn1;
        Matrix results;

        MatrixTools mt;

        //Private Methods
        void testAlgorithm();

        //trainIteration
        std::vector< std::vector<double> > vectorStod(std::vector< std::vector<string> > old);

    public:
        //Constructors
        NeuralNet();

        //Methods
        void setConfig(string configFileLocation);
        void importData();  //training, test, and final data
        //cleanData ex. turn letters to numbers
        //Pre-process Data (sigmoid, etc)
        void initialize();
        
        void train();
        
        Matrix test(string testFile);
        Matrix test(Matrix testMatrix);

        //output
        //exportSynapses
        //importSynapses
        



        //Mutators
        bool swapInputOutput();

        //Accessors

        //Operator Overloads

};

#include "NeuralNet.cpp"

#endif // NEURALNET_H
