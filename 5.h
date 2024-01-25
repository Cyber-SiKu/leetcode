//
// Created by Cyber on 2024/1/25.
//

#ifndef LEETCODE_5_H
#define LEETCODE_5_H

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	std::string longestPalindrome(std::string s) {
		int n = s.size();
		std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
		for (int i = 0; i < n; ++i) {
			dp[i][i] = true;
		}
		int pos_i = 0, pos_j = 0;
		for (int i = n - 2; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				dp[i][j] = s[i] == s[j];
				if (j - i > 1) {
					dp[i][j] = dp[i + 1][j - 1] && dp[i][j];
				}
				if (dp[i][j] && (j - i > pos_j - pos_i)) {
					pos_i = i;
					pos_j = j;
				}
			}
		}
		return s.substr(pos_i, pos_j - pos_i + 1);
	}

	void test() {
		std::vector<std::string> inputs{
		    "babad",
		    "cbbd",
		    "a",
		    "bananas",
		};
		std::vector<std::string> outputs{
		    "aba",
		    "bb",
		    "a",
		    "anana",
		};
		for (int i = 0; i < inputs.size(); ++i) {
			std::string const ans = longestPalindrome(inputs[i]);
			std::cout << "ans: " << ans << std::endl
			          << (ans == outputs[i]) << std::endl;
		}
	}
};

#endif // LEETCODE_5_H
