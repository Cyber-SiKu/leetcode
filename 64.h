//
// Created by siku on 24-1-12.
//

#ifndef LEETCODE_64_H
#define LEETCODE_64_H

#include <vector>
#include <iostream>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n , 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) +  grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }

    void test() {
        std::vector<std::vector<std::vector<int>>> input{
                {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}},
                {{1,2,3},{4,5,6}}
        };
        std::vector<int> output{7, 12};

        for (int i = 0; i < input.size(); ++i) {
            std::cout << (minPathSum(input[i]) == output[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_64_H
