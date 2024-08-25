#ifndef CALORIFY_HPP
#define CALORIFY_HPP

#include "UserProfile.hpp"
#include "FoodScanner.hpp"
#include "ChatGPTClient.hpp"
#include "MacroCalculator.hpp"
#include "DatabaseManager.hpp"
#include "BinarySearchTree.hpp"
#include "Trie.hpp"
#include "HashMap.hpp"

// Main class for Calorify application
// Combines all components to provide a complete calorie and macro tracking solution
class Calorify {
public:
    // Constructor: Initializes Calorify with the database path
    Calorify(const std::string& databasePath);

    // Runs the main loop of the application
    void run();

private:
    UserProfile currentUserProfile;               // Manages user profile information
    FoodScanner foodScanner;                      // Handles food scanning functionality
    ChatGPTClient chatGPTClient;                  // Communicates with the ChatGPT API
    MacroCalculator macroCalculator;              // Calculates macronutrients
    DatabaseManager databaseManager;              // Manages database operations
    BinarySearchTree<std::string, UserProfile> userProfileTree;  // Stores user profiles in a BST
    Trie foodTrie;                                // Stores food names for quick lookup
    HashMap foodMacroMap;                         // Stores macros for quick access

    // Calculate and display macros based on user input and profile
    void calculateAndDisplayMacros();
};

#endif // CALORIFY_HPP
