#include "FileReader.h"

#include <iostream>

using namespace std;

FileReader::FileReader(const std::string& fileName)  {
    fileStream.open(fileName,ios::in);
    if (!fileStream) {
        // Handle file open error
        cout << "Error opening file: " << fileName << std::endl;
    }
}

FileReader::~FileReader() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}

std::string FileReader::readNextLine() {
    std::string line;
    if (std::getline(fileStream, line)) {

        return line;
    }
    return ""; // Return an empty string to indicate end of file
}
