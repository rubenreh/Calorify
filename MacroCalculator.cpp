#include "MacroCalculator.hpp"
#include <algorithm>

// Constructor: Initializes total calories and macro amounts
MacroCalculator::MacroCalculator(double totalCalories) 
    : totalCalories(totalCalories), proteinAmount(0), carbsAmount(0), fatsAmount(0) {}

// Set the user's diet plan (e.g., "keto", "low-carb", etc.)
void MacroCalculator::setDietPlan(const std::string& dietPlan) {
    this->dietPlan = dietPlan;
}

// Calculate the optimal macronutrient distribution using dynamic programming
void MacroCalculator::calculateOptimalMacros() {
    calculateMacrosUsingDP();
}

// Dynamic programming implementation to calculate macros
void MacroCalculator::calculateMacrosUsingDP() {
    // Example implementation using dynamic programming to optimize macros
    int calorieLimit = static_cast<int>(totalCalories);
    dpTable.resize(calorieLimit + 1, std::vector<double>(3, 0)); // 3 for protein, carbs, fats

    // Fill the DP table based on diet plan
    for (int i = 1; i <= calorieLimit; ++i) {
        // Example of dynamic allocation based on diet
        dpTable[i][0] = dpTable[i - 1][0] + 4;  // Example: 4 calories for protein
        dpTable[i][1] = dpTable[i - 1][1] + 4;  // Example: 4 calories for carbs
        dpTable[i][2] = dpTable[i - 1][2] + 9;  // Example: 9 calories for fats

        // Apply constraints based on diet
        if (dietPlan == "keto") {
            dpTable[i][1] = std::max(dpTable[i][1] - 1, 0.0);  // Reduce carbs
        }
    }

    // Extract the optimal macro values
    proteinAmount = dpTable[calorieLimit][0];
    carbsAmount = dpTable[calorieLimit][1];
    fatsAmount = dpTable[calorieLimit][2];
}

// Return the calculated protein amount
double MacroCalculator::getProteinAmount() {
    return proteinAmount;
}

// Return the calculated carbs amount
double MacroCalculator::getCarbsAmount() {
    return carbsAmount;
}

// Return the calculated fats amount
double MacroCalculator::getFatsAmount() {
    return fatsAmount;
}
