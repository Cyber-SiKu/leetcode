//
// Created by siku on 24-1-22.
//

#ifndef LEETCODE_2788_H
#define LEETCODE_2788_H

#include "Base.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <strstream>
#include <vector>

class Solution {
public:
	std::vector<std::string>
	splitWordsBySeparator(std::vector<std::string>& words, char separator) {
		std::vector<std::string> ret;
		for (std::string& word : words) {
			int left = 0;
			int right = word.find_first_of(separator, left);
			while (right != std::string::npos) {
				std::string tmp(word.begin() + left, word.begin() + right);
				if (!tmp.empty()) {
					ret.emplace_back(tmp);
				}
				left = right + 1;
				right = word.find_first_of(separator, left);
			}
			if (word.begin() + left != word.end()) {
				ret.emplace_back(word.begin() + left, word.end());
			}
		}
		return ret;
	}

	void test() {
		std::vector<std::pair<std::vector<std::string>, char>> inputs{
		    {{"one.two.three", "four.five", "six"}, '.'},
		    {{"$easy$", "$problem$"}, '$'},
		    {{"|||"}, '|'}

		};
		std::vector<std::vector<std::string>> outputs{
		    {"one", "two", "three", "four", "five", "six"},
		    {"easy", "problem"},
		    {},
		};
		for (int i = 0; i < inputs.size(); ++i) {
			std::vector<std::string> ans =
			    splitWordsBySeparator(inputs[i].first, inputs[i].second);
			std::cout << "ans: ";
			Base<std::string>::printVec(ans, std::cout);
			std::cout << std::endl << (ans == outputs[i]) << std::endl;
		}
	}
};

#endif // LEETCODE_2788_H
