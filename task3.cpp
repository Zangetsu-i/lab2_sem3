#include <iostream>
#include <vector>
#include "pyramid.h"
#include "task3.h"

void runTask3() {
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
