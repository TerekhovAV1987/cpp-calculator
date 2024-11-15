#pragma once
#include <string>

// Псевдоним для чисел
using Number = double;

// Чтение числа с обработкой ошибок
bool ReadNumber(Number& result);

// Основной цикл работы калькулятора
bool RunCalculatorCycle();
