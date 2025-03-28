#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include "HuffmanTree.h"

// counts character frequencies from input file
std::map<char, int> countCharacterFrequencies(const std::string& filename) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::map<char, int> freqMap;
    char ch;
    while(file.get(ch)) {
        // filters non printable characters
        if (std::isprint(ch) || ch == ' ' || ch == '\n' || ch == '\t') {
            freqMap[ch]++;
        }
    }
    file.close();

    // validates the file contains usable characters
    if(freqMap.empty()) {
        throw std::runtime_error("File is empty or contains no printable characters");
    }

    return freqMap;
}


