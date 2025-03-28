#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include "HuffmanTree.h"

//prototypes
std::map<char, int> countCharacterFrequencies(const std::string& filename);
void printFrequencyTable(const std::map<char, int>& freqMap);
void printCodes(const std::map<char, std::string>& codes);

//main function
int main() {
    std::string filename;
    std::cout << "Enter text file to compress: ";
    std::cin >> filename;

    try {
        // reads the file and count frequencies
        std::map<char, int> freqMap = countCharacterFrequencies(filename);

        // prints the frequency table
        printFrequencyTable(freqMap);

        // builds the huffman tree
        HuffmanTree huffmanTree;
        huffmanTree.buildTree(freqMap);

        // generate the huffmancode
        std::map<char, std::string> codes = huffmanTree.generateCodes();

        // display the codes
        printCodes(codes);

    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}


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



