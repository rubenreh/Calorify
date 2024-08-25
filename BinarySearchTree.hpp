#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <string>

// Template class for Binary Search Tree (BST)
// Allows for efficient storage and retrieval of key-value pairs
template<typename KeyType, typename ValueType>
class BinarySearchTree {
public:
    // Constructor
    BinarySearchTree();

    // Destructor
    ~BinarySearchTree();

    // Insert a key-value pair into the BST
    void insert(const KeyType& key, const ValueType& value);

    // Find the value associated with a key in the BST
    bool find(const KeyType& key, ValueType& value);

    // Remove a key-value pair from the BST
    void remove(const KeyType& key);

private:
    // Node structure to represent each element in the BST
    struct Node {
        KeyType key;
        ValueType value;
        Node* left;
        Node* right;

        // Node constructor
        Node(const KeyType& k, const ValueType& v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;  // Root node of the BST

    // Helper functions for recursive operations
    void insert(Node*& node, const KeyType& key, const ValueType& value);
    bool find(Node* node, const KeyType& key, ValueType& value);
    void remove(Node*& node, const KeyType& key);
    void destroy(Node* node);  // Utility function to destroy the BST
};

#include "BinarySearchTree.tpp"  // Implementation file
#endif // BINARYSEARCHTREE_HPP
