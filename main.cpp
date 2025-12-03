#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"

void hashTests() {}

int main() {
    int choice;
    while (true) {
        std::cout << "\nМеню\n";
        std::cout << "1 - Логическое/арифм. выражение (стек)\n";
        std::cout << "2 - Множества: макс. пересечение\n";
        std::cout << "3 - Пирамида из блоков\n";
        std::cout << "4 - BST: вершины с двумя детьми\n";
        std::cout << "5 - HashSet (АТД множество)\n";
        std::cout << "6 - Хэш-таблица (цепочки)\n";
        std::cout << "7 - LRU кэш\n";
        std::cout << "8 - Тесты (заглушка)\n";
        std::cout << "0 - Выход\n";
        std::cout << "Введите номер задания: ";
        std::cin >> choice;

        switch (choice) {
            case 1: runTask1(); break;
            case 2: runTask2(); break;
            case 3: runTask3(); break;
            case 4: runTask4(); break;
            case 5: runTask5(); break;
            case 6: runTask6(); break;
            case 7: runTask7(); break;
            case 8: hashTests(); break;
            case 0: std::cout << "Выход..\n"; return 0;
            default: std::cout << "Неверный выбор\n"; break;
        }
    }
}