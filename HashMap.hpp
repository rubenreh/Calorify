#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <unordered_map>
#include <string>

// Class for HashMap data structure
// Provides fast access to key-value pairs, ideal for storing macros of foods
class HashMap {
public:
    // Constructor
    HashMap();

    // Destructor
    ~HashMap();

    // Insert a key-value pair into the HashMap
    void insert(const std::string& key, const std::string& value);

    // Retrieve a value associated with a key from the HashMap
    bool get(const std::string& key, std::string& value);

private:
    std::unordered_map<std::string, std::string> hashMap;  // Underlying data structure
};

#endif // HASHMAP_HPP
