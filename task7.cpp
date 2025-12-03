#include <iostream>
#include <string>
#include "lrucache.h"
#include "task7.h"

void runTask7() {
    std::size_t cap;
    std::cout << "Емкость кэша: ";
    std::cin >> cap;
    LRUCache<int,int> cache(cap);

    while (true) {
        std::cout << "\nLRU меню:\n"
                  << "1 - SET x y\n"
                  << "2 - GET x\n"
                  << "0 - назад\n";
        int c; std::cin >> c;
        if (c == 0) break;
        if (c == 1) {
            int x, y; std::cin >> x >> y;
            cache.set(x, y);
        } else if (c == 2) {
            int x; std::cin >> x;
            int val;
            if (cache.get(x, val)) std::cout << val << "\n";
            else std::cout << -1 << "\n";
        } else {
            std::cout << "Неверный выбор\n";
        }
    }
}
