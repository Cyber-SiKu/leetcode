//
// Created by siku on 24-1-18.
//

#ifndef LEETCODE_875_H
#define LEETCODE_875_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

class Solution {
public:
    int minEatingSpeed(std::vector<int> &piles, int h) {
        int max = *std::max_element(piles.begin(), piles.end()); // 最快速度 是可以的
//        unsigned long long sum = std::accumulate(piles.begin(), piles.end(), 0);
        int min = int(sum / (unsigned long long) h); // 最慢速度
        int ret = max;

        int cost = piles.size();

        while (max != min) {
            int mid = (max + min) / 2;
            if (mid == 0) {
                break;
            }
            int cost = 0;
            for (int j = 0; j < piles.size(); ++j) {
                int count = piles[j] / mid;
                if ((count * mid) < piles[j]) {
                    count++;
                }
                cost += count;
            }
            if (cost > h) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        return max;
    }

    void test() {
        std::vector<std::pair<std::vector<int>, int>> inputs{
                {{3,         6,         7,         11},                                                                                                                                                                  8},
                {{30,        11,        23,        4,         20},                                                                                                                                                       5},
                {{30,        11,        23,        4,         20},                                                                                                                                                       6},
                {{312884470},                                                                                                                                                                                            312884469},
                {{312884470},                                                                                                                                                                                            968709470},
                {{332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184}, 823855818}
        };
        std::vector<int> outputs{4, 30, 23, 2, 1, 915906740};

        for (int i = 0; i < inputs.size(); ++i) {
            int ans = minEatingSpeed(inputs[i].first, inputs[i].second);
            std::cout << "ans: " << ans << std::endl << (ans == outputs[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_875_H
