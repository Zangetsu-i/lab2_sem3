#ifndef PYRAMID_H
#define PYRAMID_H

#include <vector>
#include <algorithm>
#include <cstdint>

struct Block {
    std::int64_t w;
    std::int64_t h;
};

inline std::int64_t maxPyramidHeight(std::vector<Block> blocks)
{
    if (blocks.empty()) return 0;

    std::sort(blocks.begin(), blocks.end(),
              [](const Block& a, const Block& b) {
                  if (a.w == b.w) return a.h > b.h;
                  return a.w < b.w;
              });

    const std::size_t n = blocks.size();
    std::vector<std::int64_t> dp(n);
    std::int64_t ans = 0;

    for (std::size_t i = 0; i < n; ++i) {
        dp[i] = blocks[i].h;
        
        for (std::size_t j = 0; j < i; ++j) {
            if (blocks[j].w < blocks[i].w && dp[j] + blocks[i].h > dp[i]) {
                dp[i] = dp[j] + blocks[i].h;
            }
        }
        
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }

    return ans;
}

#endif