#include <bits/stdc++.h>
using namespace std;

void swapChars(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void descendingOrderSort(string &numbers) {
    int number = numbers.size();
    for (int i = 0; i < number - 1; ++i) {
        for (int j = i + 1; j < number; ++j) {
            if (numbers[i] < numbers[j]) {
                swapChars(numbers[i], numbers[j]);
            }
        }
    }
}

void ascendingOrderSort(string &numbers) {
    int number = numbers.size();
    for (int i = 0; i < number - 1; ++i) {
        for (int j = i + 1; j < number; ++j) {
            if (numbers[i] > numbers[j]) {
                swapChars(numbers[i], numbers[j]);
            }
        }
    }
}

int stringToInt(string &numberString) {
    int resultant = 0;
    for (int i = 0; i < numberString.length(); ++i) {
        resultant = resultant * 10 + (numberString[i] - '0');
    }
    return resultant;
}

int kaprekarLogic(int number) {
    string numberString = to_string(number);
    while (numberString.size() < 4) {
        numberString = "0" + numberString;
    }
    descendingOrderSort(numberString);
    int descendingOrder = stringToInt(numberString);

    ascendingOrderSort(numberString);
    int ascendingOrder = stringToInt(numberString);

    return descendingOrder - ascendingOrder;
}

int kaprekarMove(int number) {
    int move = 0;
    while (number != 6174 && move < 8) {
        number = kaprekarLogic(number);
        move++;
    }
    return move;
}

int main() {
    string number;
    cout << "Enter a four-digit number: ";
    cin >> number;
    string temp = number;

    int count[10] = {0};

    for (char digit : temp) {
        if (isdigit(digit)) {
            int digitValue = digit - '0';
            count[digitValue]++;
        }
    }

    if (number.size() != 4) {
        cout << "Please enter a valid four-digit number." << std::endl;
        return -1;
    }

    int uniqueDigitCount = 0;
    for (int i = 0; i < 10; ++i) {
        if (count[i] > 0) {
            uniqueDigitCount++;
        }
    }

    if (uniqueDigitCount <= 1) {
        cout << "Please enter a valid number with at least 2 different digits." << std::endl;
        return -1;
    }
    int num = stringToInt(number);
    int steps = kaprekarMove(num);
    if (steps > 7) {
        cout << "Number of iterations to reach Kaprekar's Constant (6174) is more than : " << steps << std::endl;
    } else {
        cout << "Number of iterations to reach Kaprekar's Constant (6174): " << steps << std::endl;
    }

    return 0;
}
