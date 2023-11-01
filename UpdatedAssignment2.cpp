#include <iostream>
#include <string>

using namespace std;

class DigestionStep {
public:
    virtual void perform() = 0;
    virtual string getName() = 0;
};

class Ingestion : public DigestionStep {
private:
    string name;

public:
    Ingestion() : name("Ingestion") {}

    void perform() {
        cout << "Ingesting food." << endl;
    }

    string getName() {
        return name;
    }
};

class StomachDigestion : public DigestionStep {
private:
    string name;

public:
    StomachDigestion() : name("Stomach Digestion") {}

    void perform() {
        cout << "Digesting food in the stomach." << endl;
    }

    string getName() {
        return name;
    }
};

class SmallIntestineDigestion : public DigestionStep {
private:
    string name;

public:
    SmallIntestineDigestion() : name("Small Intestine Digestion") {}

    void perform() {
        cout << "Digesting food in the small intestine." << endl;
    }

    string getName() {
        return name;
    }
};

void processDigestionStep(DigestionStep* step) {
    cout << "Performing " << step->getName() << " step:" << endl;
    step->perform();
    cout << endl;
}

int main() {
    Ingestion ingestionStep;
    StomachDigestion stomachDigestionStep;
    SmallIntestineDigestion smallIntestineDigestionStep;

    DigestionStep* step1 = &ingestionStep;
    DigestionStep* step2 = &stomachDigestionStep;
    DigestionStep* step3 = &smallIntestineDigestionStep;

    processDigestionStep(step1);
    processDigestionStep(step2);
    processDigestionStep(step3);

    return 0;
}
