#ifndef CALORIFY_HPP
#define CALORIFY_HPP

#include "User.hpp"
#include "FoodScanner.hpp"
#include "ChatGPTClient.hpp"

class Calorify {
public:
    void run();
    
private:
    User user;
    FoodScanner scanner;
    ChatGPTClient chatGPT;
    
    void calculateMacros();
};

#endif // CALORIFY_HPP
