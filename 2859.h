//
// Created by siku on 24-1-25.
//

#ifndef LEETCODE_2859_H
#define LEETCODE_2859_H

#include <vector>
#include <iostream>

class Solution {
    int getCount(int num) {
        int ret = 0;
        while (num != 0) {
            ret += (num & 1);
            num >>= 1;
        }
        return ret;
    }
public:
    int sumIndicesWithKSetBits(std::vector<int> const &nums, const int k) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (k == getCount(i)) {
                ret += nums[i];
            }
        }
        return ret;
    }

    void test() {
        std::vector<std::pair<std::vector<int>, int>> inputs{
                {{5, 10, 1, 5, 2}, 1},
                {{4, 3,  2, 1},    2},
        };
        std::vector<int> outputs{
                13,
                1,
        };
        for (int i = 0; i < inputs.size(); ++i) {
            const int ans = sumIndicesWithKSetBits(inputs[i].first, inputs[i].second);
            std::cout << "ans: " << ans << std::endl << (ans == outputs[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_2859_H
