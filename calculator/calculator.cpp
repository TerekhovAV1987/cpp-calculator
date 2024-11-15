#include "calculator.h"
#include <iostream>
#include <sstream>
#include <cmath>

// Сообщение об ошибке
void errorMessage(const std::string& message) {
    std::cerr << message << '\n';
}

// Чтение числа
bool ReadNumber(Number& result) {
    if (!(std::cin >> result)) {
        errorMessage("Error: Numeric operand expected");
        return false;
    }
    return true;
}

// Основной цикл работы калькулятора
bool RunCalculatorCycle() {
    Number calculatorValue = 0;
    Number memory = 0;
    bool memorySet = false;

    // Считываем начальное значение
    if (!ReadNumber(calculatorValue)) {
        return false;
    }

    std::string command;
    while (std::cin >> command) {
        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            calculatorValue += operand;
        }
        else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            calculatorValue -= operand;
        }
        else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            calculatorValue *= operand;
        }
        else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            calculatorValue /= operand;
        }
        else if (command == "**") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            calculatorValue = std::pow(calculatorValue, operand);
        }
        else if (command == "=") {
            std::cout << calculatorValue << std::endl;
        }
        else if (command == ":") {
            if (!ReadNumber(calculatorValue)) {
                return false;
            }
        }
        else if (command == "c") {
            calculatorValue = 0;
        }
        else if (command == "q") {
            return true;
        }
        else if (command == "s") {
            memory = calculatorValue;
            memorySet = true;
        }
        else if (command == "l") {
            if (!memorySet) {
                errorMessage("Error: Memory is empty");
                return false;
            }
            calculatorValue = memory;
        }
        else {
            errorMessage("Error: Unknown token " + command);
            return false;
        }
    }

    return true;
}
