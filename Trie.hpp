#ifndef TRIE_HPP
#define TRIE_HPP

#include <unordered_map>
#include <string>

// Class for Trie data structure
// Efficiently stores and retrieves words, useful for fast prefix searches
class Trie {
public:
    // Constructor
    Trie();

    // Destructor
    ~Trie();

    // Insert a word into the Trie
    void insert(const std::string& word);

    // Search for a word in the Trie
    bool search(const std::string& word);

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(const std::string& prefix);

private:
    // Node structure to represent each character in the Trie
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool isEndOfWord;

        // TrieNode constructor
        TrieNode() : isEndOfWord(false) {}
    };

    TrieNode* root;  // Root node of the Trie

    void destroy(TrieNode* node);  // Utility function to destroy the Trie
};

#endif // TRIE_HPP
