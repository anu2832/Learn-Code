
#include <iostream>
#include <string>

using namespace std;

class Human {
protected:
    string name;
    int age;

public:
    virtual string getName() = 0;
    virtual int getAge() = 0;
    virtual void setName(string newName) = 0;
    virtual void setAge(int newAge) = 0;
    virtual void describe(){};
};

class Male : public Human {
public:
    Male(string name, int age) {
        this->name = name;
        this->age = age;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(string newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void describe()  {
        cout << "This is " << getName() << "," << getAge() << " years old." <<endl;
    }
};

class Female : public Human {
public:
    Female(string name, int age) 
    {
        this->name = name;
        this->age = age;
    }
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    void setName(string newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }
    void describe() {
        cout << "This is " << getName() << "," << getAge() << " years old." << endl;
    }
};

int main() {
    Male male("John", 30);
    Female female("Teena", 28);
    Human *h1 = &male;
    h1->describe();
    Human* h2 = &female;
    h2->describe();
 
    return 0;
}
