//
// Created by Cyber on 2024/1/26.
//

#ifndef LEETCODE_BASE_H
#define LEETCODE_BASE_H

#include <iostream>
#include <vector>

template <typename T> class Base {

public:
	static void printVec(const std::vector<T>& outs, std::ostream& os) {
		for (auto const& out : outs) {
			os << out << ", ";
		}
	}
};

#endif // LEETCODE_BASE_H
