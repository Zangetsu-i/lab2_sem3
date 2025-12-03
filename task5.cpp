#include <iostream>
#include "bstforks.h"

void runTask5() {
    std::cout << "=== Задание 5: BST - вершины с двумя детьми ===" << std::endl;
    std::cout << "Введите последовательность целых, заканчивающуюся 0:\n";
    Node* root = nullptr;
    int x;
    while (std::cin >> x && x != 0) insert(root, x);

    std::cout << "Вершины с двумя детьми: ";
    printForksInOrder(root);
    std::cout << "\n";
    destroy(root);
}