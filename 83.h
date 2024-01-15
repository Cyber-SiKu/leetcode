//
// Created by siku on 24-1-15.
//

#ifndef LEETCODE_83_H
#define LEETCODE_83_H

#include <vector>
#include <iostream>

namespace Leetcode_83 {
    struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}

        ListNode(int x) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            ListNode *now = head;
            while (now != nullptr) {
                ListNode *next = now->next;
                // 找到第一个不相等的或者链表尾
                while (next != nullptr && next->val == now->val) {
                    next = next->next;
                }

                // 删除重复元素
                ListNode *toDel = now->next;
                now->next = next;
                while (toDel != next) {
                    ListNode *tmp = toDel->next;
                    delete toDel;
                    toDel = tmp;
                }
                now = next;
            }
            return head;
        }

        void test() {
            std::vector<std::vector<int>> input
                    {
                            {1, 1, 2},
                            {1, 1, 2, 3, 3}
                    };
            std::vector<std::vector<int>> output{
                    {1, 2},
                    {1, 2, 3}
            };

            for (int i = 0; i < input.size(); ++i) {
                ListNode head = 1;
                head.val = input[i][0];
                ListNode *tmp = &head;
                for (int j = 1; j < input[i].size(); ++j) {
                    ListNode *l = new ListNode(input[i][j]);
                    tmp->next = l;
                    tmp = tmp->next;
                }

                auto result = deleteDuplicates(&head);
                if (result == nullptr) {
                    std::cout << "nullptr";
                }
                std::vector<int> ret;
                while (result != nullptr) {
                    std::cout << result->val << " ";
                    ret.push_back(result->val);
                    result = result->next;
                }
                std::cout << " ans:" << (ret == output[i]) << std::endl;
            }
        }
    };
};


#endif //LEETCODE_83_H
