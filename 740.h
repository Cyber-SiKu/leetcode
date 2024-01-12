#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution_1 {
public:
    int deleteAndEarn(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> map;
        std::vector<int> values;
        for (auto const &num: nums) {
            if (map.find(num) != map.end()) {
                map[num]++;
            } else {
                map[num] = 1;
                values.push_back(num);
            }
        }
        if (values.size() < 2) {
            return map[values[0]] * values[0];
        }
        std::vector<int> selected(values.size(), 0);
        selected[0] = values[0] * map[values[0]];
        std::vector<int> unselected(values.size(), 0);
        for (int i = 1; i < values.size(); ++i) {
            if (values[i] - 1 != values[i - 1]) {
                // 不是邻近数字
                int max_before = std::max(selected[i - 1], unselected[i - 1]);
                selected[i] = max_before + map[values[i]] * values[i];
                unselected[i] = max_before;
            } else {
                // 邻近
                selected[i] = unselected[i - 1] + map[values[i]] * values[i];
                unselected[i] = std::max(selected[i - 1], unselected[i - 1]);
            }
        }
        int ret = std::max(*selected.rbegin(), *unselected.rbegin());
        return ret;
    }

    void test() {
        std::vector<std::vector<int>> input{
                {3, 4,  2},
                {2, 2,  3, 3, 3, 4},
                {1, 1,  1, 2, 4, 5, 5, 5,  6},
                {8, 10, 4, 9, 1, 3, 5, 9,  4, 10},
                {1, 6,  3, 3, 8, 4, 8, 10, 1, 3},
        };
        std::vector<int> output{6, 9, 18, 37, 43};

        for (int i = 0; i < input.size(); ++i) {
            std::cout << (deleteAndEarn(input[i]) == output[i]) << std::endl;
        }
    }
};

class Solution {
public:
    int deleteAndEarn(std::vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> selected(nums.size(), 0);
        std::vector<int> unselected(nums.size(), 0);
        selected[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int max_before = std::max(selected[i - 1], unselected[i - 1]);
            unselected[i] = max_before;
            if (nums[i] - 1 != nums[i - 1]) {
                // 不是邻近数字
                if (nums[i] == nums[i - 1]) {
                    // 相同的数字
                    selected[i] = selected[i - 1] + nums[i];
                    unselected[i] = unselected[i - 1];
                } else {
                    selected[i] = max_before + nums[i];
                }
            } else {
                // 邻近
                selected[i] = unselected[i - 1] + nums[i];
            }
        }
        int ret = std::max(*selected.rbegin(), *unselected.rbegin());
        std::cout << "ans:" << ret << std::endl;
        return ret;
    }

    void test() {
        std::vector<std::vector<int>> input{
                {3, 4,  2},
                {2, 2,  3, 3, 3, 4},
                {1, 1,  1, 2, 4, 5, 5, 5,  6},
                {8, 10, 4, 9, 1, 3, 5, 9,  4, 10},
                {1, 6,  3, 3, 8, 4, 8, 10, 1, 3},
        };
        std::vector<int> output{6, 9, 18, 37, 43};

        for (int i = 0; i < input.size(); ++i) {
            std::cout << (deleteAndEarn(input[i]) == output[i]) << std::endl;
        }
    }
};
