#include <iostream>
#include <cstring>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"


int main(int argc, char* argv[]) {
    if (argc > 1) {
        runTask2(argc, argv);
        return 0;
    }
    
    
    int choice;
    while (true) {
        std::cout << "\n=== Меню заданий ===\n";
        std::cout << "1 - Арифметическое выражение (стек)\n";
        std::cout << "2 - АТД Множество\n";
        std::cout << "3 - Максимальное пересечение множеств\n";
        std::cout << "4 - Пирамида из блоков\n";
        std::cout << "5 - BST: вершины с двумя детьми\n";
        std::cout << "6 - Хэш-таблица (цепочки)\n";
        std::cout << "7 - LRU кэш\n";
        std::cout << "0 - Выход\n";
        std::cout << "Введите номер задания: ";
        std::cin >> choice;

        switch (choice) {
            case 1: runTask1(); break;
            case 2: 
                std::cout << "\nДля задания 2 используйте командную строку:\n";
                std::cout << "./program --file <файл> --query \"<команда> <элемент>\"\n";
                std::cout << "Команды: SETADD, SETDEL, SET_AT\n";
                std::cout << "Пример: ./program --file data.txt --query \"SETADD apple\"\n";
                break;
            case 3: runTask3(); break;
            case 4: runTask4(); break;
            case 5: runTask5(); break;
            case 6: runTask6(); break;
            case 7: runTask7(); break;
            case 0: std::cout << "Выход..\n"; return 0;
            default: std::cout << "Неверный выбор\n"; break;
        }
    }
}