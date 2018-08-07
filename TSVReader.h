#ifndef TSVREADER_H
#define TSVREADER_H

#include <vector>

using namespace std;


//TSVReader Class

class TSVReader {
    private:
        int rowCount;
        int colCount;
        string range;

        //Private Methods
        void processRange(); //stub going to be used to specify parts of an excel file ex. range A1:B10

    public:
        //Constructors
        TSVReader();
        TSVReader(string newRange);

        //Methods
        std::vector< std::vector<string> > import(string filename);
};

#include "TSVReader.cpp"

#endif // TSVREADER_H

