#include "Trie.hpp"
#include <iostream>

// Constructor: Initializes the root node of the Trie
Trie::Trie() {
    root = new TrieNode();
}

// Destructor: Recursively destroys all nodes in the Trie
Trie::~Trie() {
    destroy(root);
}

// Insert a word into the Trie
void Trie::insert(const std::string& word) {
    TrieNode* currentNode = root;
    for (char c : word) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            currentNode->children[c] = new TrieNode();
        }
        currentNode = currentNode->children[c];
    }
    currentNode->isEndOfWord = true;
}

// Search for a word in the Trie
bool Trie::search(const std::string& word) {
    TrieNode* currentNode = root;
    for (char c : word) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[c];
    }
    return currentNode->isEndOfWord;
}

// Check if any word in the Trie starts with the given prefix
bool Trie::startsWith(const std::string& prefix) {
    TrieNode* currentNode = root;
    for (char c : prefix) {
        if (currentNode->children.find(c) == currentNode->children.end()) {
            return false;
        }
        currentNode = currentNode->children[c];
    }
    return true;
}

// Utility function to recursively destroy nodes in the Trie
void Trie::destroy(TrieNode* node) {
    for (auto& pair : node->children) {
        destroy(pair.second);
    }
    delete node;
}
