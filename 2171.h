//
// Created by siku on 24-1-18.
//

#ifndef LEETCODE_2171_H
#define LEETCODE_2171_H

#include <vector>
#include <iostream>

class Solution {
public:
    long long minimumRemoval(const std::vector<int> &beans) {
        long long ret = 1e10;
        // 定哪一个不拿
        for (int i = 0; i < beans.size(); ++i) {
            long long times = 0;
            if (beans[i] * beans.size() > ret) {
                continue;
            }
            for (int j = 0; j < beans.size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (beans[j] < beans[i]) {
                    times += beans[j];
                } else if (beans[j] > beans[i]) {
                    times += (beans[j] - beans[i]);
                }
            }
            if (ret > times) {
                ret = times;
            }
        }

        return ret;
    }

    void test() {
        std::vector<std::vector<int>> inputs{
                {4, 1,  6, 5},
                {2, 10, 3, 2},
        };
        std::vector<long long> output{4, 7};
        for (int i = 0; i < inputs.size(); ++i) {
            long long ans = minimumRemoval(inputs[i]);
            std::cout << "ans: " << ans << std::endl << (output[i] == ans) << std::endl;
        }
    }
};

#endif //LEETCODE_2171_H
