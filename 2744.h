//
// Created by siku on 24-1-17.
//

#ifndef LEETCODE_2744_H
#define LEETCODE_2744_H

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int maximumNumberOfStringPairs(std::vector<std::string> &words) {
        int ret = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[i][0] == words[j][1] && words[i][1] == words[j][0])  {
                    ++ret;
                }
            }
        }
        return ret;
    }

    void test() {
        std::vector<std::vector<std::string>> inputs{
                {"cd", "ac", "dc", "ca", "zz"},
                {"ab", "ba", "cc"},
                {"aa", "ab"}
        };
        std::vector<int> outputs{
                2,
                1,
                0
        };

        for (int i = 0; i < inputs.size(); ++i) {
            int ret = maximumNumberOfStringPairs(inputs[i]);
            std::cout << "ans: " << ret << std::endl << (ret == outputs[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_2744_H
