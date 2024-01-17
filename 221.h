//
// Created by siku on 24-1-17.
//

#ifndef LEETCODE_221_H
#define LEETCODE_221_H

#include <vector>
#include <iostream>

class Solution {
public:
    int maximalSquare(const std::vector<std::vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = matrix[0][0] - '0';
        int max_length = 0;
        for (int i = 1; i < n; ++i) {
            if (matrix[0][i] == '1') {
                max_length = dp[0][i] = 1;
            } else{
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == '1') {
                max_length = dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int value = std::max(dp[i - 1][j], dp[i][j - 1]);
                if (matrix[i][j] == '0') {
                    dp[i][j] = value;
                } else {
                    // matrix[i][j] == '1'
                    if (IsSquare(i, j, matrix, max_length + 1)) {
                        ++max_length;
                        dp[i][j] = max_length * max_length;
                    } else {
                        dp[i][j] = value;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    bool IsSquare(int x, int y, const std::vector<std::vector<char>> &matrix, int max_length) {
        if (x < max_length - 1 || y < max_length - 1) {
            return false;
        }
        for (int i = 0; i < max_length; ++i) {
            for (int j = 0; j < max_length; ++j) {
                if (matrix[x - i][y - j] == '0') {
                    return false;
                }
            }
        }
        return true;
    }

    void test() {
        std::vector<std::vector<std::vector<char>>> inputs{
                {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}},
                {{'0', '1'},                {'1', '0'}},
                {{'0'}}
        };
        std::vector<int> outputs{
                4,
                1,
                0
        };

        for (int i = 0; i < inputs.size(); ++i) {
            int ans = maximalSquare(inputs[i]);
            std::cout << "ans: " << ans << std::endl << (ans == outputs[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_221_H
