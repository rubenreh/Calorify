#ifndef FOODSCANNER_HPP
#define FOODSCANNER_HPP

#include <opencv2/opencv.hpp>
#include <string>

class FoodScanner {
public:
    std::string scanFood();
    double getUserInputForMass();
    
private:
    cv::Mat captureImage();
};

#endif // FOODSCANNER_HPP
