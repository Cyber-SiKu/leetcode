/*
   给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

   你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

class Solution {

public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    int i;
    int j;
    for (i = 0; i < nums.size() - 1; i++) {
      for (j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          goto end;
        }
      }
    }
    j = i + 1;
  end:
    ans.push_back(i);
    ans.push_back(j);
    return ans;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(15);
  Solution cal;
  std::vector<int> ans = cal.twoSum(nums, 9);
  for (auto i = ans.begin(); i != ans.end(); i++) {
    cout << *i << endl;
  }
  return 0;
}
