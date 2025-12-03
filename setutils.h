#ifndef SETUTILS_H
#define SETUTILS_H

#include <set>
#include <vector>
#include <utility>


inline std::pair<std::pair<int, int>, std::size_t>
findMaxIntersection(const std::vector<std::set<int>>& sets)
{
    int best_i = -1, best_j = -1;
    std::size_t best_size = 0;

    for (std::size_t i = 0; i < sets.size(); ++i) {
        for (std::size_t j = i + 1; j < sets.size(); ++j) {
            std::size_t cnt = 0;
            auto it1 = sets[i].begin();
            auto it2 = sets[j].begin();
            while (it1 != sets[i].end() && it2 != sets[j].end()) {
                if (*it1 == *it2) {
                    ++cnt;
                    ++it1;
                    ++it2;
                } else if (*it1 < *it2) {
                    ++it1;
                } else {
                    ++it2;
                }
            }

            if (cnt > best_size) {
                best_size = cnt;
                best_i = static_cast<int>(i);
                best_j = static_cast<int>(j);
            }
        }
    }

    return {{best_i, best_j}, best_size};
}

#endif 
