#include "BinarySearchTree.hpp"
#include <iostream>

// Constructor: Initializes an empty BST
template<typename KeyType, typename ValueType>
BinarySearchTree<KeyType, ValueType>::BinarySearchTree() 
    : root(nullptr) {}

// Destructor: Recursively destroys all nodes in the BST
template<typename KeyType, typename ValueType>
BinarySearchTree<KeyType, ValueType>::~BinarySearchTree() {
    destroy(root);
}

// Insert a key-value pair into the BST
template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    insert(root, key, value);
}

// Find the value associated with a key in the BST
template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::find(const KeyType& key, ValueType& value) {
    return find(root, key, value);
}

// Remove a key-value pair from the BST
template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::remove(const KeyType& key) {
    remove(root, key);
}

// Helper function to insert a node into the BST
template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::insert(Node*& node, const KeyType& key, const ValueType& value) {
    if (node == nullptr) {
        node = new Node(key, value);
    } else if (key < node->key) {
        insert(node->left, key, value);
    } else if (key > node->key) {
        insert(node->right, key, value);
    } else {
        node->value = value;
    }
}

// Helper function to find a value by key in the BST
template<typename KeyType, typename ValueType>
bool BinarySearchTree<KeyType, ValueType>::find(Node* node, const KeyType& key, ValueType& value) {
    if (node == nullptr) {
        return false;
    } else if (key < node->key) {
        return find(node->left, key, value);
    } else if (key > node->key) {
        return find(node->right, key, value);
    } else {
        value = node->value;
        return true;
    }
}

// Helper function to remove a node from the BST
template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::remove(Node*& node, const KeyType& key) {
    if (node == nullptr) return;

    if (key < node->key) {
        remove(node->left, key);
    } else if (key > node->key) {
        remove(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->key = temp->key;
            node->value = temp->value;
            remove(node->right, temp->key);
        }
    }
}

// Utility function to recursively destroy all nodes in the BST
template<typename KeyType, typename ValueType>
void BinarySearchTree<KeyType, ValueType>::destroy(Node* node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

// Include the template implementation file
#include "BinarySearchTree.tpp"
