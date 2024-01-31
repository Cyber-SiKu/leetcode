//
// Created by Cyber on 2024/1/31.
//

#ifndef LEETCODE_2670_H
#define LEETCODE_2670_H

#include "Base.h"
#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
	std::vector<int> distinctDifferenceArray(std::vector<int>& nums) {
		int n = nums.size();
		std::vector<int> dp1(n, 1);
		for (auto i = 1; i < nums.size(); ++i) {
			dp1[i] = dp1[i - 1];
			if (std::find(nums.begin(), nums.begin() + i, nums[i]) ==
			    nums.begin() + i) {
				++dp1[i];
			}
		}

		std::vector<int> dp2(n, 0);
		for (auto i = n - 2; i >= 0; --i) {
			dp2[i] = dp2[i + 1];
			if (std::find(nums.begin() + i + 2, nums.end(), nums[i + 1]) ==
			    nums.end()) {
				++dp2[i];
			}
		}
		std::vector<int> ret(n, 0);
		for (int i = 0; i < n; ++i) {
			ret[i] = dp1[i] - dp2[i];
		}
		return ret;
	}

	void test() {
		std::vector<std::vector<int>> inputs{
		    {1, 2, 3, 4, 5},
		    {3, 2, 3, 4, 2},
		};
		std::vector<std::vector<int>> outputs{
		    {-3, -1, 1, 3, 5},
		    {-2, -1, 0, 2, 3},
		};
		for (int i = 0; i < inputs.size(); ++i) {
			auto ans = distinctDifferenceArray(inputs[i]);
			std::cout << "ans: ";
			Base<int>::printVec(ans, std::cout);
			std::cout << std::endl << (ans == outputs[i]) << std::endl;
		}
	}
};

#endif // LEETCODE_2670_H
