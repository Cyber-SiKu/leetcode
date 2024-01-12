#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    int countWords_1(std::vector<std::string>& words1,
        std::vector<std::string>& words2)
    {
        int ret = 0;
        std::map<std::string, std::pair<int, int>> s;
        for (auto& w : words1) {
            if (s.find(w) == s.end()) {
                s[w].first = 1;
            } else {
                s[w].first++;
            }
        }
        for (auto& w : words2) {
            if (s.find(w) == s.end()) {
                s[w].second = 1;
            } else {
                s[w].second++;
            }
        }
        for (auto& w : s) {
            if (w.second.first == 1 && w.second.second == 1) {
                ret++;
            }
        }
        return ret;
    }

    int countWords(std::vector<std::string>& words1,
        std::vector<std::string>& words2)
    {
        int ret = 0;
        std::unordered_map<std::string, std::pair<int, int>> s;
        for (auto& w : words1) {
            if (s.find(w) == s.end()) {
                s[w].first = 1;
            } else {
                s[w].first++;
            }
        }
        for (auto& w : words2) {
            if (s.find(w) == s.end()) {
                s[w].second = 1;
            } else {
                s[w].second++;
            }
        }
        for (auto& w : s) {
            if (w.second.first == 1 && w.second.second == 1) {
                ret++;
            }
        }
        return ret;
    }

    void test()
    {
        {
            std::vector<std::string> words1 {
                "leetcode", "is", "amazing", "as", "is"
            },
                words2 = { "amazing", "leetcode", "is" };
            std::cout << (countWords(words1, words2) == 2) << std::endl;
        }

        {
            std::vector<std::string> words1 { "b", "bb", "bbb" },
                words2 = { "a", "aa", "aaa" };
            std::cout << (countWords(words1, words2) == 0) << std::endl;
        }

        {
            std::vector<std::string> words1 { "a", "ab" },
                words2 = { "a", "a", "a", "ab" };
            std::cout << (countWords(words1, words2) == 1) << std::endl;
        }
    }
};