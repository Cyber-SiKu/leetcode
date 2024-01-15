//
// Created by siku on 24-1-15.
//

#ifndef LEETCODE_82_H
#define LEETCODE_82_H

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = nullptr;
        ListNode *insert = nullptr;
        ListNode *now = head;
        ListNode *next = now->next;
        while (now != nullptr) {
            // 找到第一个与 now->val 不相同或者找到链表末尾
            while (next != nullptr && next->val == now->val) {
                next = next->next;
            }
            if (next == nullptr) {
                // 找到链表尾(或者now没有后继节点)
                if (now->next == nullptr) {
                    // now 无后继节点
                    if (insert == nullptr) {
                        // 没有插入
                        ret = insert = now;
                    } else {
                        insert->next = now;
                        insert = now;
                    }
                } else {
                    // now 以后包括 now 都是重复的
                    if (insert != nullptr) {
                        insert->next = nullptr;
                    }
                    ListNode *toDel = now;
                    while (toDel != next) {
                        ListNode *tmp = toDel->next;
                        if (toDel != head) {
                            delete toDel;
                        }
                        toDel = tmp;
                    }
                }
                now = nullptr;
            } else {
                // 找到第一个与 now 值不同的节点
                if (now->next != next) {
                    // 说明存在与now值重复的节点
                    ListNode *toDel = now;
                    now = next;
                    next = now->next;
                    // 删除中间重复的值
                    while (toDel != now) {
                        ListNode *tmp = toDel->next;
                        if (toDel != head) {
                            delete toDel;
                        }
                        toDel = tmp;
                    }
                } else {
                    // 无相同节点
                    if (insert == nullptr) {
                        // 尚未插入元素
                        ret = insert = now;
                    } else {
                        // 已经插入元素
                        insert->next = now;
                        insert = now;
                    }
                    now->next = nullptr;
                    now = next;
                    next = now->next;
                }
            }

        }
        return ret;
    }

    void test() {
        std::vector<std::vector<int>> input
                {
                        {1, 2, 3, 3, 4, 4, 5},
                        {1, 1, 1, 2, 3}
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
            while (result != nullptr) {
                std::cout << result->val << " ";
                result = result->next;
            }
            std::cout << std::endl;
        }
    }
};


#endif //LEETCODE_82_H
