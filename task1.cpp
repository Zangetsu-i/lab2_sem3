#include <iostream>
#include "task1.h"
#include "stack.h"

extern long long evaluateExpression(const std::string&);

void runTask1() {
    std::cout << "Введите арифметическое выражение:\n";
    std::string expr;
    std::getline(std::cin >> std::ws, expr);
    long long res = evaluateExpression(expr);
    std::cout << "Результат: " << res << "\n";
}
