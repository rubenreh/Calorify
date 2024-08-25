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
    if (!foodMacroMap.get(scannedFood, macros)) {
        // If not, query the ChatGPT client
        macros = chatGPTClient.queryMacros(scannedFood);
        foodMacroMap.insert(scannedFood, macros); // Store the retrieved macros in the map
    }

    // Display the retrieved macros
    std::cout << "Macros for " << scannedFood << ": " << macros << std::endl;

    // Calculate and display the optimal macros based on user input and profile
    calculateAndDisplayMacros();
}

// Calculate and display macros based on user input and profile
void Calorify::calculateAndDisplayMacros() {
    macroCalculator.setDietPlan(currentUserProfile.getDietPlan());
    macroCalculator.calculateOptimalMacros();

    // Display the calculated macros
    std::cout << "Optimal Macros - Protein: " << macroCalculator.getProteinAmount()
              << ", Carbs: " << macroCalculator.getCarbsAmount()
              << ", Fats: " << macroCalculator.getFatsAmount() << std::endl;
}
