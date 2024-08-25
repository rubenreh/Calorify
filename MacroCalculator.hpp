#ifndef MACROCALCULATOR_HPP
#define MACROCALCULATOR_HPP

#include <string>
#include <vector>

// Class to calculate optimal macronutrient distribution
// Implements dynamic programming to optimize macro calculations
class MacroCalculator {
public:
    // Constructor: Initializes with total calorie intake
    MacroCalculator(double totalCalories);

    // Set the user's diet plan (e.g., "keto", "low-carb", etc.)
    void setDietPlan(const std::string& dietPlan);

    // Calculate the optimal macronutrient distribution
    void calculateOptimalMacros();

    // Get the calculated protein amount
    double getProteinAmount();

    // Get the calculated carbs amount
    double getCarbsAmount();

    // Get the calculated fats amount
    double getFatsAmount();
    
private:
    double totalCalories;  // Total calorie intake for the user
    std::string dietPlan;  // User's diet plan

    double proteinAmount;  // Calculated protein intake
    double carbsAmount;    // Calculated carbs intake
    double fatsAmount;     // Calculated fats intake

    // Dynamic programming table to store intermediate results
    std::vector<std::vector<double>> dpTable;

    // Helper function to perform the dynamic programming calculation
    void calculateMacrosUsingDP();
};

#endif // MACROCALCULATOR_HPP
