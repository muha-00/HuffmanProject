//
// Created by muham on 2025-03-27.
//

#include "HuffmanTree.h"
#include <stdexcept>

//constructor initialized with a null root
HuffmanTree::HuffmanTree() : root(nullptr) {}

//destructor to clean up all the nodes
HuffmanTree::~HuffmanTree() {
    deleteTree(root);
}

//recursive deletion method implemented for tree cleanup
void HuffmanTree::deleteTree(HuffmanNode* node) {
    if(!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// tree construction algorithm, implemented using a priority queue
void HuffmanTree::buildTree(const std::map<char, int>& freqMap) {
    if(freqMap.empty()) {
        throw std::invalid_argument("Empty frequency map handling was added");
    }

    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, CompareNodes> pq;

    // creating leaf nodes for each character frequency pair
    for(const auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Nodes are repeatedly merged until one tree remains
    while(pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* internalNode = new HuffmanNode(left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        pq.push(internalNode);
    }

    root = pq.top();
}

// main function to generate all Huffman codes from the tree,this returns a map of characters to their binary codes

std::map<char, std::string> HuffmanTree::generateCodes() const {
    std::map<char, std::string> codes;

    // will only proceed if tree isnt empty
    if(root) {
        // start recursive code generation from root with empty string
        generateCodesHelper(root, "", codes);

        // if only one character exists, its code should be 0
        if(codes.size() == 1) codes.begin()->second = "0";
    }
    return codes;
}

// recursive code helper that traverses the tree to build codes

void HuffmanTree::generateCodesHelper(HuffmanNode* node, std::string code,
                                     std::map<char, std::string>& codes) const {
    if(!node) return; // safety check

    // if we hit a leaf node (no children), store the code
    if(!node->left && !node->right) {
        codes[node->character] = code;
        return;
    }

    // recursively explore left path (add 0) and right path (add 1)
    generateCodesHelper(node->left, code + "0", codes);
    generateCodesHelper(node->right, code + "1", codes);
}
