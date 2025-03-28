//
// Created by muham on 2025-03-27.
//

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <map>
#include <queue>




// created HuffmanNode structure  to store character data and tree linkages
struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    // constructors  for both leaf and internal nodes
    HuffmanNode(char ch, int freq)
        : character(ch), frequency(freq), left(nullptr), right(nullptr) {}

    HuffmanNode(int freq)
        : character('\0'), frequency(freq), left(nullptr), right(nullptr) {}
};

//  HuffmanTree class  to encapsulate all compression logic
class HuffmanTree {
public:
    // core interface methods
    HuffmanTree();
    ~HuffmanTree();

    // builds tree from character frequencies
    void buildTree(const std::map<char, int>& freqMap);

    // generates the Huffman codes from the built tree
    std::map<char, std::string> generateCodes() const;

private:
    HuffmanNode* root;

    // helper methods  for memory management and code generation
    void deleteTree(HuffmanNode* node);
    void generateCodesHelper(HuffmanNode* node, std::string code,
                           std::map<char, std::string>& codes) const;

    //  custom comparor for the priority queue
    struct CompareNodes {
        bool operator()(HuffmanNode* a, HuffmanNode* b) {
            return a->frequency > b->frequency;
        }
    };
};








};







#endif //HUFFMANTREE_H
