#include <iostream>
#include <string>
#include "hash_chained.h"
#include "task6.h"

void runTask6() {
    HashMapChained<std::string, int> map;
    int choice;
    std::string key;
    int value;
    while (true) {
        std::cout << "\nHashMap (цепочки):\n"
                  << "1 - insert\n2 - erase\n3 - find\n0 - назад\n";
        std::cin >> choice;
        if (choice == 0) break;
        switch (choice) {
            case 1:
                std::cout << "key value: ";
                std::cin >> key >> value;
                std::cout << (map.insert(key, value) ? "inserted\n" : "exists\n");
                break;
            case 2:
                std::cout << "key: ";
                std::cin >> key;
                std::cout << (map.erase(key) ? "erased\n" : "not found\n");
                break;
            case 3: {
                std::cout << "key: ";
                std::cin >> key;
                std::optional<int> v = map.find(key);
                if (v.has_value()) {
                    std::cout << "value = " << *v << "\n";
                } else {
                    std::cout << "not found\n";
                }
                break;
            }
            default:
                std::cout << "Неверный выбор\n";
        }
    }
}