//
// Created by siku on 24-1-15.
//

#ifndef LEETCODE_120_H
#define LEETCODE_120_H

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
    static constexpr int MAX = 200;
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        std::vector<int> dp(MAX, 0);
        dp[0] = triangle[0][0];
        int size = 1;
        for (int i = 1; i < triangle.size(); ++i) {
            size = triangle[i].size();
            dp[size-1] = dp[size-2];
            for (int j = triangle[i].size()-1; j > 0; --j) {
                dp[j] = std::min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }
        auto ret =  *(std::min_element(dp.begin(), dp.begin()+size));
        std::cout << "ans: " << ret << std::endl;
        return ret;
    }

    void test() {
        std::vector<std::vector<std::vector<int>>> input{
                {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}},
                {{-10}}
        };
        std::vector<int> output{
                11,
                -10
        };
        for (int i = 0; i < input.size(); ++i) {
            std::cout << (minimumTotal(input[i]) == output[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_120_H
