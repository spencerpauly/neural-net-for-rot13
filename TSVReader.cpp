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

using namespace std;


//Constructors
TSVReader::TSVReader() {

}

TSVReader::TSVReader(string newRange) {
    range = newRange;
}

//Private Methods
void TSVReader::processRange() {
    //stub
}

//Methods
std::vector< std::vector<string> > TSVReader::import(string filename) {

    ifstream inFile;

    std::vector< std::vector<string> > data;
    
    inFile.open(filename.c_str() );

    if (inFile) {

        string line;

        //Process 1st Line Of Data (Header Line)
        getline(inFile, line);

        colCount = 1;

        for (char c : line) {
            if (c == '\t') {
                colCount++;
            }
        }

        //Process rest of file
        rowCount = 1;

        while (getline(inFile, line) ) {
            data.resize(rowCount);
            data[rowCount-1].resize(colCount);

            std::istringstream iss(line);
            
            string word;
            int curCol = 0;

            for (string line; iss >> word; ) {

                data[rowCount-1].at(curCol) = word;
                curCol++;
            }

            rowCount++;
            iss.clear();

        }

        inFile.close();

        return data;


    } else {
            string message("File not found! ");
    throw PrecondViolatedExcep(message);

    }

}