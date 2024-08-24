#ifndef USER_HPP
#define USER_HPP

class User {
public:
    void setUserInfo();
    double getCaloriesToMaintain();
    double getCaloriesToLose();
    double getCaloriesToGain();

private:
    int age;
    double height;
    double weight;
    char gender;

    void calculateCaloricNeeds();
    double BMR;  // Basal Metabolic Rate
};

#endif // USER_HPP
