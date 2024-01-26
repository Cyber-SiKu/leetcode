//
// Created by Cyber on 2024/1/25.
//

#ifndef LEETCODE_139_H
#define LEETCODE_139_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
		int n = s.size();
		std::vector<bool> dp(n, false);
		std::string tmp = s.substr(0, 1);
		if (std::find(wordDict.begin(), wordDict.end(), tmp) !=
		    wordDict.end()) {
			dp[0] = true;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = i; j >= 0; --j) {
				tmp = s.substr(j, i - j + 1);
				if (std::find(wordDict.begin(), wordDict.end(), tmp) !=
				        wordDict.end() &&
				    (j == 0 || dp[j - 1])) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n - 1];
	}

	void test() {
		std::vector<std::pair<std::string, std::vector<std::string>>> inputs{
		    {"leetcode", {"leet", "code"}},
		    {"applepenapple", {"apple", "pen"}},
		    {"catsandog", {"cats", "dog", "sand", "and", "cat"}},
		};
		std::vector<bool> outputs{
		    true,
		    true,
		    false,
		};
		for (int i = 0; i < inputs.size(); ++i) {
			auto ans = wordBreak(inputs[i].first, inputs[i].second);
			std::cout << "ans: " << ans << std::endl
			          << (ans == outputs[i]) << std::endl;
		}
	}
};

#endif // LEETCODE_139_H
