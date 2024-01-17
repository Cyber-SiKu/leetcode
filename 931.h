//
// Created by siku on 24-1-15.
//

#ifndef LEETCODE_931_H
#define LEETCODE_931_H

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
        int n;
        n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::min(dp[i-1][0], dp[i-1][1]) + matrix[i][0];
            for (int j = 1; j < n-1; ++j) {
                int min = dp[i-1][j-1];
                if (min > dp[i-1][j]) {
                    min = dp[i-1][j];
                }
                if (min > dp[i-1][j+1]) {
                    min = dp[i-1][j+1];
                }
                dp[i][j] = min + matrix[i][j];
            }
            dp[i][n-1] = std::min(dp[i-1][n-2], dp[i-1][n-1]) + matrix[i][n-1];
        }

        return *std::min_element(dp[n-1].begin(), dp[n-1].end());
    }

    void test() {
        std::vector<std::vector<std::vector<int>>> input{
                {{2,   1, 3}, {6,   5, 4}, {7, 8, 9}},
                {{-19, 57},   {-40, -5}}
        };
        std::vector<int> output{
                13,
                -59
        };

        for (int i = 0; i < input.size(); ++i) {
            auto ans = minFallingPathSum(input[i]);
            std::cout << "ans: " << ans << std::endl << (ans == output[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_931_H
