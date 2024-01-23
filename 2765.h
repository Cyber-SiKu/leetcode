//
// Created by siku on 24-1-23.
//

#ifndef LEETCODE_2765_H
#define LEETCODE_2765_H

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int alternatingSubarray(std::vector<int> &nums) {
        int n = nums.size();
        int dp = 1;
        int max = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = dp + 1;
            if ((tmp % 2 == 0 && nums[i] == nums[i - 1] + 1) || (tmp % 2 == 1 && nums[i] == nums[i - 1] - 1)) {
                dp = dp + 1;
            } else if (nums[i] == nums[i - 1] + 1) {
                dp = 2;
            } else {
                dp = 1;
            }
            max = std::max(max, dp);
        }
        if (max == 1) {
            return -1;
        } else {
            return max;
        }
    }

    void test() {
        std::vector<std::vector<int>> inputs{
                {2, 3, 4, 3, 4},
                {4, 5, 6},
        };
        std::vector<int> outputs{
                4,
                2,
        };

        for (int i = 0; i < inputs.size(); ++i) {
            int ans = alternatingSubarray(inputs[i]);
            std::cout << "ans: " << ans << std::endl << (outputs[i] == ans) << std::endl;
        }
    }
};

#endif //LEETCODE_2765_H
