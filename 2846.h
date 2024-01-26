//
// Created by Cyber on 2024/1/26.
//

#ifndef LEETCODE_2846_H
#define LEETCODE_2846_H

#include "Base.h"
#include <algorithm>
#include <array>
#include <stack>
#include <vector>

static constexpr int MAX_EDGE = 27;

class Solution {

	std::vector<int> findRoad(int start, int end,
	                          std::vector<std::vector<int>> edges) {
		std::stack<int> road;
		std::stack<std::vector<int>> length;
		road.push(start);
		length.push(std::vector<int>());
		while (!road.empty()) {
			auto top = road.top();
			auto pre = length.top();
			if (top == end) {
				break;
			}
			road.pop();
			length.pop();
			for (auto i = edges.begin(); i != edges.end();) {
				if ((*i)[0] == top || (*i)[1] == top) {
					auto preLength(pre);
					preLength.push_back((*i)[2]);
					length.push(preLength);
					if ((*i)[0] == top) {
						road.push((*i)[1]);
					} else {
						road.push((*i)[0]);
					}
					i = edges.erase(i);
				} else {
					++i;
				}
			}
		}
		return length.top();
	}

public:
	std::vector<int>
	minOperationsQueries(int n, std::vector<std::vector<int>>& edges,
	                     std::vector<std::vector<int>>& queries) {
		std::vector<int> ret;

		for (int i = 0; i < queries.size(); ++i) {
			int result = 0;
			auto road = findRoad(queries[i][0], queries[i][1], edges);
			for (int j = 0; j + result < road.size(); ++j) {
				int num = std::count(road.cbegin(), road.cend(), road[i]);
				result = std::max(num, result);
			}
			ret.push_back(road.size() - result);
		}
		return ret;
	}

	void test() {
		std::vector<int> ns{
		    7,
		    8,
		};
		std::vector<std::vector<std::vector<int>>> edgess{
		    {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 4, 2}, {4, 5, 2}, {5, 6, 2}},
		    {{1, 2, 6},
		     {1, 3, 4},
		     {2, 4, 6},
		     {2, 5, 3},
		     {3, 6, 6},
		     {3, 0, 8},
		     {7, 0, 2}},
		};
		std::vector<std::vector<std::vector<int>>> queriess{
		    {{0, 3}, {3, 6}, {2, 6}, {0, 6}},
		    {{4, 6}, {0, 4}, {6, 5}, {7, 4}},
		};
		std::vector<std::vector<int>> outputs{
		    {0, 0, 1, 3},
		    {1, 2, 2, 3},
		};
		for (int i = 0; i < ns.size(); ++i) {
			std::vector<int> ans =
			    minOperationsQueries(ns[i], edgess[i], queriess[i]);
			std::cout << "ans:";
			Base<int>::printVec(ans, std::cout);
			std::cout << std::endl << (ans == outputs[i]) << std::endl;
		}
	}
};

#endif // LEETCODE_2846_H
