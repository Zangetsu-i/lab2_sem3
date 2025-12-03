#include <iostream>
#include "bstforks.h"
#include "task4.h"

void runTask4() {
    std::cout << "Введите последовательность целых, заканчивающуюся 0:\n";
    Node* root = nullptr;
    int x;
    while (std::cin >> x && x != 0) insert(root, x);

    std::cout << "Вершины с двумя детьми: ";
    printForksInOrder(root);
    std::cout << "\n";
    destroy(root);
}
