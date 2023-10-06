#ifndef PACKETSHANDLER_FILEREADER_H
#define PACKETSHANDLER_FILEREADER_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileReader {
private:
    ifstream fileStream;

public:
    FileReader(const string& fileName);
    ~FileReader();
    string readNextLine();
};

#endif // PACKETSHANDLER_FILEREADER_H
