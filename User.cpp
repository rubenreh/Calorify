#include "User.hpp"
#include <iostream>

void User::setUserInfo() {
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter height (cm): ";
    std::cin >> height;
    std::cout << "Enter weight (kg): ";
    std::cin >> weight;
    std::cout << "Enter gender (M/F): ";
    std::cin >> gender;

    calculateCaloricNeeds();
}

void User::calculateCaloricNeeds() {
    if (gender == 'M') {
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else {
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }
}

double User::getCaloriesToMaintain() {
    return BMR * 1.2;  // Sedentary activity level
}

double User::getCaloriesToLose() {
    return getCaloriesToMaintain() - 500;  // Approx. 500 calories deficit
}

double User::getCaloriesToGain() {
    return getCaloriesToMaintain() + 500;  // Approx. 500 calories surplus
}
