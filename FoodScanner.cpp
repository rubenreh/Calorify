#include "FoodScanner.hpp"
#include <iostream>

std::string FoodScanner::scanFood() {
    // Placeholder for object recognition code
    std::cout << "Scanning food...\n";
    return "chicken";  // Example output
}

double FoodScanner::getUserInputForMass() {
    double mass;
    std::cout << "Enter the mass of the food (grams): ";
    std::cin >> mass;
    return mass;
}
