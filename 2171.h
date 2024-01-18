//
// Created by siku on 24-1-18.
//

#ifndef LEETCODE_2171_H
#define LEETCODE_2171_H

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long minimumRemoval(std::vector<int> &beans) {
        long long dp = std::accumulate(beans.begin(), beans.end(), (long long) 0);
        std::sort(beans.begin(), beans.end());
        dp -= (long long) (beans[0] * beans.size());
        long long ret = dp;
        for (int i = 1; i < beans.size(); ++i) {
            if (beans[i] == beans[i-1]){
                continue;
            }
            long long tmp = dp - (beans[i] - beans[i - 1]) * (beans.size() - i);
            if (beans[i] != beans[i - 1]) {
                for (int j = i-1; j >= 0; --j) {
                    if (beans[j] == beans[i-1]) {
                        tmp += beans[i - 1];
                    } else {
                        break;
                    }
                }
            }
            dp = tmp;
            ret = std::min(ret, dp);
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
