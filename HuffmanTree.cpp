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

