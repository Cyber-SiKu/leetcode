//
// Created by siku on 24-1-22.
//

#ifndef LEETCODE_2788_H
#define LEETCODE_2788_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <strstream>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> splitWordsBySeparator(std::vector<std::string>& words, char separator) {
        std::vector<std::string> ret;
        for (std::string& word: words) {
            int left = 0;
            int right = word.find_first_of(separator, left);
            while (right != std::string::npos) {
                ret.push_back(std::string(words.begin()+left, words.begin()+right));
                left = right;
                right = word.find_first_of()
            }
        }
        return ret;
    }

    void test(){
        std::vector<std::pair<std::vector<std::string>, char>> inputs{};
        std::vector<std::vector<std::string>> outputs;
        auto printVec = [](std::vector<std::string>& outs, std::ostream & os) {
            for (auto const & out: outs) {
                os << out << ",";
            }
        };
        for (int i = 0; i < inputs.size(); ++i) {
            std::vector<std::string> ans = splitWordsBySeparator(inputs[i].first, inputs[i].second);
            printVec(inputs[i].first, std::cout);
            std::cout << std::endl << (ans == outputs[i]) << std::endl;
        }
    }
};

#endif //LEETCODE_2788_H
