cmake_minimum_required(VERSION 3.10)

project(Calorify)

set(CMAKE_CXX_STANDARD 17)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Include directories
include_directories(include)

# Source files
add_executable(Calorify
    src/main.cpp
    src/Calorify.cpp
    src/User.cpp
    src/FoodScanner.cpp
    chatgpt/ChatGPTClient.cpp
)

# Link OpenCV
target_link_libraries(Calorify ${OpenCV_LIBS})
