#include "HashMap.hpp"

// Constructor: Initializes the HashMap
HashMap::HashMap() {}

// Destructor: The unordered_map handles its own cleanup
HashMap::~HashMap() {}

// Insert a key-value pair into the HashMap
void HashMap::insert(const std::string& key, const std::string& value) {
    hashMap[key] = value;
}

// Retrieve a value associated with a key from the HashMap
bool HashMap::get(const std::string& key, std::string& value) {
    auto it = hashMap.find(key);
    if (it != hashMap.end()) {
        value = it->second;
        return true;
    }
    return false;
}
