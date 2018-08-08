/** @file
 *
 *  ZetaNet - Custom Neural Network Project
 *
 *  @author Spencer D. Pauly
 *
 *  @date 7 Aug 2018
 *
 *  @version 6.1 */

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

        /**
         * Stub for reading only a specific part of the TSV file (ex. range A1:B10)
         */
        void processRange();

    public:
        //Constructors
        TSVReader();
        TSVReader(string newRange);

        //Methods

        /**
         * Main import method for file reading
         * @pre string with the name and filepath of a .tsv file
         * @return Returns every row and column of the tsv file in matrix format
         */
        std::vector< std::vector<string> > import(string filename);
};

#include "TSVReader.cpp"

#endif // TSVREADER_H

