#include "Calorify.hpp"
#include <iostream>

// Constructor: Initializes Calorify with a given database path
Calorify::Calorify(const std::string& databasePath) 
    : databaseManager(databasePath), 
      currentUserProfile("defaultUser"), 
      macroCalculator(0), 
      chatGPTClient(), 
      foodScanner() {
    currentUserProfile.loadProfile();
}

// Main loop of the application
void Calorify::run() {
    // Scan food and get its name
    std::string scannedFood = foodScanner.scanFood();
    std::string macros;
    
    // Check if the macros for the scanned food are already in the map
    if (!food
