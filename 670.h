//
// Created by siku on 24-1-22.
//

#ifndef LEETCODE_670_H
#define LEETCODE_670_H

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maximumSwap(int num) {
        std::string numStr = std::to_string(num);
        std::string numStrSorted = numStr;
        std::sort(numStrSorted.begin(), numStrSorted.end(), std::greater<char>());
        int i = 0;
        for (; i < numStrSorted.size(); ++i) {
            if (numStr[i] != numStrSorted[i]) {
                break;
            }
        }
        if (i != numStrSorted.size()) {
            int pos = numStr.find_last_of(numStrSorted[i]);
            std::swap(numStr[i], numStr[pos]);
        }
        return std::stoi(numStr);
    }

    void test() {
        std::vector<int> inputs{
                2736,
                9973,
                98368,
                1993,
        };
        std::vector<int> outputs{
                7236,
                9973,
                98863,
                9913,
        };
        for (int i = 0; i < inputs.size(); ++i) {
            int ans = maximumSwap(inputs[i]);
            std::cout << "ans: " << ans << std::endl << (ans == outputs[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_670_H
