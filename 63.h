//
// Created by siku on 24-1-12.
//

#ifndef LEETCODE_63_H
#define LEETCODE_63_H

#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                // 存在障碍物
                break;
            }
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                // 存在障碍物
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                int left = 0;
                int up = 0;
                if (obstacleGrid[i - 1][j] != 1) {
                    left = dp[i - 1][j];
                }
                if (obstacleGrid[i][j - 1] != 1) {
                    up = dp[i][j - 1];
                }

                dp[i][j] = left + up;
            }
        }
        std::cout << "ans:" << dp[m - 1][n - 1] << std::endl;
        return dp[m - 1][n - 1];
    }

    void test() {
        std::vector<std::vector<std::vector<int>>> input{
                {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
                {{0, 1},    {0, 0}},
                {{0, 0},    {0, 1}},
                {{1},       {0}}
        };

        std::vector<int> output{
                2, 1, 0
        };

        for (int i = 0; i < input.size(); ++i) {
            std::cout << (uniquePathsWithObstacles(input[i]) == output[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_63_H
