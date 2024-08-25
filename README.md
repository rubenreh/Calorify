# **Calorify**

<p align="center">
  <img src="https://github.com/rubenreh/Calorify/blob/main/calorifyV2.png?raw=true" alt="Hand Hero Logo">
</p>

**Calorify** is a comprehensive application designed to help users manage their dietary intake by leveraging advanced techniques in data structures and algorithms. This project integrates computer vision, data analysis, and personalized nutrition recommendations to offer a robust tool for tracking and optimizing nutritional intake.

## **Features**

- **Food Scanning**: Utilizes OpenCV and object recognition to identify various foods.
- **Nutritional Information**: Integrates with ChatGPT to retrieve macronutrient data for scanned foods.
- **Personalized Recommendations**: Calculates and displays daily calorie and macronutrient needs based on user profile data.
- **Dynamic Data Structures**: Employs Trie, HashMap, and Binary Search Tree for efficient data management and retrieval.

## **Data Structures and Algorithms**

### **Trie**
- **Purpose**: Efficiently manage and search for food items and their nutritional information.
- **Functions**:
  - `insert(const std::string& word)`: Adds a new word to the Trie.
  - `search(const std::string& word)`: Checks if a word exists in the Trie.
  - `startsWith(const std::string& prefix)`: Checks if any word starts with the given prefix.
- **File**: `src/Trie.cpp`

### **HashMap**
- **Purpose**: Stores and retrieves macronutrient data associated with food items.
- **Functions**:
  - `insert(const std::string& key, const std::string& value)`: Inserts a key-value pair into the HashMap.
  - `get(const std::string& key, std::string& value)`: Retrieves the value for a given key.
- **File**: `src/HashMap.cpp`

### **Binary Search Tree (BST)**
- **Purpose**: Manage and search for user profile data efficiently.
- **Functions**:
  - `insert(const KeyType& key, const ValueType& value)`: Inserts a key-value pair into the BST.
  - `find(const KeyType& key, ValueType& value)`: Finds the value associated with a key.
  - `remove(const KeyType& key)`: Removes a key-value pair from the BST.
- **File**: `src/BinarySearchTree.cpp`

## **Core Components**

### **Food Scanning**
- **Libraries**: OpenCV
- **Purpose**: Scans and identifies food items from images.
- **How it Works**: Uses object recognition algorithms to identify food items and retrieves their nutritional information.

### **ChatGPT Integration**
- **Purpose**: Retrieves macronutrient data for identified foods.
- **How it Works**: Queries the ChatGPT client for detailed macronutrient information when the food item is not found in the local database.

### **Nutritional Calculation**
- **Purpose**: Calculates daily calorie and macronutrient needs based on user inputs.
- **Inputs**: Height, weight, age, gender, and dietary goals (bulk, cut, maintain).
- **Outputs**: Provides personalized recommendations for protein, carbohydrates, fats, and other nutrients.


## **Usage**

1. **Scan Food**: Use the application to scan food items. The system will identify the food and retrieve nutritional information.
2. **Input User Profile**: Enter your height, weight, age, gender, and dietary goals.
3. **View Recommendations**: The application will provide personalized calorie and macronutrient recommendations based on your profile and goals.
