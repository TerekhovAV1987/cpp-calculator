#include <iostream>
#include <string>
#include "calculator.h"

int main() {
    if (!RunCalculatorCycle()) {
        return 1;  // Завершаем работу с кодом ошибки
    }
    return 0;
}
