//
// Created by siku on 24-1-12.
//

#ifndef LEETCODE_62_H
#define LEETCODE_62_H

#include <vector>
#include <iostream>
#include <array>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> arr(m, std::vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            arr[0][i] = 1;
        }
        for (int i = 0; i < m; ++i) {
            arr[i][0] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                arr[i][j] = arr[i][j-1] + arr[i-1][j];
            }
        }
        return arr[m-1][n-1];
    }

    void test() {
        std::vector<std::pair<int, int>> input{
                {3, 7},
                {3, 2},
                {7,3},
                {3, 3}
        };
        std::vector<int> output{28, 3, 28, 6};

        for (int i = 0; i < input.size(); ++i) {
            std::cout << (uniquePaths(input[i].first, input[i].second) == output[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_62_H
