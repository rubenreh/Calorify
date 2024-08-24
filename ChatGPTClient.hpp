#ifndef CHATGPTCLIENT_HPP
#define CHATGPTCLIENT_HPP

#include <string>

class ChatGPTClient {
public:
    std::string getFoodMacros(const std::string &foodItem);
};

#endif // CHATGPTCLIENT_HPP
