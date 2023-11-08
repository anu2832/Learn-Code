#include <iostream>
#include <string>

using namespace std;

class Human {
public:
    virtual void organs() {
        cout << "Common human organs: Mouth, Stomach, Intestine, etc." << endl;
    }

    virtual void digestiveProcess() {
        cout << "Digestive process is a similar procedure for all humans." << endl;
    }

    virtual void metabolism() {
        cout << "Metabolism of the human body." << endl;
    }

    virtual void dietaryNeeds() {
        cout << "Dietary needs of the human body." << endl;
    }
};

class Male : public Human {
public:
    void metabolism() override {
        cout << "Males have more metabolism than females." << endl;
    }

    void dietaryNeeds() override {
        cout << "Males need more calories and protein due to higher muscle mass." << endl;
    }
};

class Female : public Human {
public:
    void metabolism() override {
        cout << "Females have less metabolism than males." << endl;
    }

    void dietaryNeeds() override {
        cout << "Females need less calories and protein as compared to males." << endl;
    }
};

int main() {
    Human human;
    Male male;
    Female female;

    cout << "Human Information:" << endl;
    human.organs();
    human.digestiveProcess();
    human.metabolism();
    human.dietaryNeeds();

    cout << "\nMale Information:" << endl;
    male.organs();
    male.digestiveProcess();
    male.metabolism();
    male.dietaryNeeds();

    cout << "\nFemale Information:" << endl;
    female.organs();
    female.digestiveProcess();
    female.metabolism();
    female.dietaryNeeds();

    return 0;
}
