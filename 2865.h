//
// Created by siku on 24-1-24.
//

#ifndef LEETCODE_2865_H
#define LEETCODE_2865_H

#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    using llong = long long;

    llong maximumSumOfHeights(std::vector<int> &maxHeights) {
        llong ret = 0;
        for (int i = 0; i < maxHeights.size(); ++i) {
            llong sum = maxHeights[i];
            int pre = maxHeights[i];
            for (int j = i - 1; j >= 0; --j) {
                if (maxHeights[j] <= pre) {
                    sum += maxHeights[j];
                    pre = maxHeights[j];
                } else {
                    // maxHeights[j] > pre
                    sum += pre;
                }
            }
            pre = maxHeights[i];
            for (int j = i + 1; j < maxHeights.size(); ++j) {
                if (maxHeights[j] <= pre) {
                    sum += maxHeights[j];
                    pre = maxHeights[j];
                } else {
                    // maxHeights[j] > pre
                    sum += pre;
                }
            }
            ret = std::max(ret, sum);
        }
        return ret;
    }

    void test() {
        std::vector<std::vector<int>> inputs{
                {5, 3, 4, 1, 1},
                {6, 5, 3, 9, 2, 7},
                {3, 2, 5, 5, 2, 3},
                {1, 5, 2, 5, 6, 4, 6, 3, 4, 5},
        };
        std::vector<llong> outputs{
                13,
                22,
                18,
                33,
        };
        for (int i = 0; i < inputs.size(); ++i) {
            llong ans = maximumSumOfHeights(inputs[i]);
            std::cout << "ans: " << ans << std::endl << (ans == outputs[i]) << std::endl;
        }

    }
};

#endif //LEETCODE_2865_H
