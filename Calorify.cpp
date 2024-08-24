#include "Calorify.hpp"
#include <iostream>

void Calorify::run() {
    user.setUserInfo();
    std::string food = scanner.scanFood();
    std::string macros = chatGPT.getFoodMacros(food);
    std::cout << "Macros for " << food << ": " << macros << std::endl;
    calculateMacros();
}

void Calorify::calculateMacros() {
    double calories = user.getCaloriesToMaintain();
    std::cout << "Calories to maintain weight: " << calories << std::endl;
    // Add more logic for gaining/losing weight
}
