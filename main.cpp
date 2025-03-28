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
// displays character frequency count in a formatted table
void printFrequencyTable(const std::map<char, int>& freqMap) {
    std::cout << "\nFrequency Table:\n";
    for(const auto& pair : freqMap) {
        // Formats special characters for readability
        std::string displayChar;
        if(pair.first == ' ') displayChar = "Space";
        else if(pair.first == '\n') displayChar = "Newline";
        else if(pair.first == '\t') displayChar = "Tab";
        else if(std::isprint(pair.first)) displayChar = std::string("'") + pair.first + "'";

        // this aligns output in columns
        std::cout << std::setw(8) << std::left << displayChar << ": " << pair.second << "\n";
    }


// this prints the  generated huffman codes with good formatting
void printCodes(const std::map<char, std::string>& codes) {
    std::cout << "\nHuffman Codes:\n";
    for(const auto& pair : codes) {
        // the same  same special character formatting as frequency table, to account for space character, new line and tab
        std::string displayChar;
        if(pair.first == ' ') displayChar = "Space";
        else if(pair.first == '\n') displayChar = "Newline";
        else if(pair.first == '\t') displayChar = "Tab";
        else if(std::isprint(pair.first)) displayChar = std::string("'") + pair.first + "'";

        std::cout << std::setw(8) << std::left << displayChar << ": " << pair.second << "\n";
    }
}



