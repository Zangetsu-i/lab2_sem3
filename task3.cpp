#include <iostream>
#include <vector>
#include <set>
#include "setutils.h"

void runTask3() {
    std::cout << "=== Задание 3: Максимальное пересечение множеств ===" << std::endl;
    std::cout << "Введите количество подмножеств: ";
    int n; std::cin >> n;
    std::vector<std::set<int>> sets(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Множество " << i << " (кол-во элементов, затем элементы): ";
        int k; std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int x; std::cin >> x;
            sets[i].insert(x);
        }
    }

    auto res = findMaxIntersection(sets);
    auto idx = res.first;
    std::size_t cnt = res.second;

    if (idx.first == -1) {
        std::cout << "Недостаточно множеств.\n";
        return;
    }
    std::cout << "Множества с максимальным пересечением: "
              << idx.first << " и " << idx.second
              << ", размер пересечения = " << cnt << "\n";
}