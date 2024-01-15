//
// Created by siku on 24-1-15.
//

#ifndef LEETCODE_2182_H
#define LEETCODE_2182_H

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

class Solution {
    static constexpr int N = 26;
public:
    std::string repeatLimitedString(std::string s, int repeatLimit) {
        std::vector<int> char2times(N, 0);
        for (auto const & i : s) {
            ++char2times[i- 'a'];
        }

        auto find_left_first = [&char2times](int pos) {
            int i = pos;
            for (; i >= 0; --i) {
                if (char2times[i] >0) {
                    break;
                }
            }
            return i;
        };

        std::string ret;
        int i = find_left_first(N-1);
        for (; i >=0 ; --i) {
            if (char2times[i] == 0) {
                continue;
            }
            if (char2times[i] <= repeatLimit) {
                ret += std::string(char2times[i], i+'a');
                char2times[i] = 0;
            } else {
                ret += std::string(repeatLimit, i+'a');
                int left = find_left_first(i-1);
                if (left < 0) {
                    break;
                }
                ret += std::string(1, left + 'a');
                char2times[i] -= repeatLimit;
                --char2times[left];
                ++i; //纠正
            }
        }
//        std::cout << "ans: " << ret << std::endl;
        return ret;
    }

    void test() {
        std::vector<std::pair<std::string, int>> input{
                {"cczazcc", 3},
                {"aababab", 2}
        };

        std::vector<std::string> output{
            "zzcccac",
            "bbabaa"
        };
        for (int i = 0; i < input.size(); ++i) {
            std::cout << (repeatLimitedString(input[i].first, input[i].second) == output[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_2182_H
