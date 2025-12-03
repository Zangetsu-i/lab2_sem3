#include <iostream>
#include "hashset.h"
#include "task5.h"

void runTask5() {
    HashSet set;
    int choice;
    std::string s;
    while (true) {
        std::cout << "\nHashSet меню:\n"
                  << "1 - добавить\n2 - удалить\n3 - проверить\n4 - вывести\n0 - назад\n";
        std::cin >> choice;
        if (choice == 0) break;
        switch (choice) {
            case 1:
                std::cout << "Элемент: ";
                std::cin >> s;
                std::cout << (set.add(s) ? "Добавлено\n" : "Уже есть\n");
                break;
            case 2:
                std::cout << "Элемент: ";
                std::cin >> s;
                std::cout << (set.remove(s) ? "Удалено\n" : "Не найдено\n");
                break;
            case 3:
                std::cout << "Элемент: ";
                std::cin >> s;
                std::cout << (set.contains(s) ? "TRUE\n" : "FALSE\n");
                break;
            case 4:
                set.print();
                break;
            default:
                std::cout << "Неверный выбор\n";
        }
    }
}
