//
// Created by siku on 24-1-17.
//

#ifndef LEETCODE_221_H
#define LEETCODE_221_H

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	int maximalSquare(const std::vector<std::vector<char>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
		dp[0][0] = matrix[0][0] - '0';
		int ret = dp[0][0];
		for (int i = 1; i < n; ++i) {
			if (matrix[0][i] == '1') {
				dp[0][i] = 1;
				ret = 1;
			} else {
				dp[0][i] = 0;
			}
		}
		for (int i = 1; i < m; ++i) {
			if (matrix[i][0] == '1') {
				dp[i][0] = 1;
				ret = 1;
			} else {
				dp[i][0] = 0;
			}
		}

		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j] == '0') {
					dp[i][j] = 0;
				} else {
					// matrix[i][j] == '1
					std::vector<int> pre{dp[i][j - 1], dp[i - 1][j],
					                     dp[i - 1][j - 1]};
					dp[i][j] =
					    (*std::min_element(pre.cbegin(), pre.cend())) + 1;
					if (dp[i][j] > ret) {
						ret = dp[i][j];
					}
				}
			}
		}

		return ret * ret;
	}

	void test() {
		std::vector<std::vector<std::vector<char>>> inputs{
		    {{'1', '0', '1', '0', '0'},
		     {'1', '0', '1', '1', '1'},
		     {'1', '1', '1', '1', '1'},
		     {'1', '0', '0', '1', '0'}},
		    {{'0', '1'}, {'1', '0'}},
		    {{'0'}},
		    {{'1'}}};
		std::vector<int> outputs{4, 1, 0, 1};

		for (int i = 0; i < inputs.size(); ++i) {
			int ans = maximalSquare(inputs[i]);
			std::cout << "ans: " << ans << std::endl
			          << (ans == outputs[i]) << std::endl;
		}
	}
};

#endif // LEETCODE_221_H
