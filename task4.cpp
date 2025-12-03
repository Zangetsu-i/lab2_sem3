#include <iostream>
#include <vector>
#include "pyramid.h"

void runTask4() {
    std::cout << "=== Задание 4: Пирамида из блоков ===" << std::endl;
    int n;
    std::cout << "Введите N (число блоков): ";
    std::cin >> n;
    std::vector<Block> blocks(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> blocks[i].w >> blocks[i].h;
    }
    std::cout << "Максимальная высота пирамиды: "
              << maxPyramidHeight(blocks) << "\n";
}