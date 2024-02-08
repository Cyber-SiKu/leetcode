//
// Created by siku on 2024/2/7.
//

#ifndef LEETCODE_993_H
#define LEETCODE_993_H

#include <queue>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	    : val(0)
	    , left(nullptr)
	    , right(nullptr) {}
	TreeNode(int x)
	    : val(x)
	    , left(nullptr)
	    , right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right)
	    : val(x)
	    , left(left)
	    , right(right) {}
};

class Solution {
private:
	static int getNodeDepth(TreeNode* root, int val) {
		TreeNode* node = root;
		std::queue<TreeNode*> s_node;
		std::queue<int> s_depth;
		s_node.push(node);
		s_depth.push(0);
		while (node->val != val) {
			int depth = s_depth.front();
			s_node.pop();
			s_depth.pop();
			auto auto_push = [&s_node, &s_depth, depth](TreeNode* n) {
				if (n != nullptr) {
					s_node.push(n);
					s_depth.push(depth + 1);
				}
			};
			auto_push(node->left);
			auto_push(node->right);
			node = s_node.front();
		}
		return s_depth.front();
	}

	TreeNode* getNodeParent(TreeNode* root, int val) {

		TreeNode* node = root;
		std::queue<TreeNode*> s;
		s.push(node);
		auto is_parent = [val](TreeNode* tn) -> bool {
			auto judge = [val](TreeNode* n) -> bool {
				if (n != nullptr && n->val == val) {
					return true;
				}
				return false;
			};
			if (judge(tn->left) || judge(tn->right)) {
				return true;
			} else {
				return false;
			}
		};
		while (!is_parent(node)) {
			s.pop();
			auto auto_push = [&s](TreeNode* n) {
				if (n != nullptr) {
					s.push(n);
				}
			};
			auto_push(node->left);
			auto_push(node->right);
			node = s.front();
		}
		return s.front();
	}

public:
	bool isCousins(TreeNode* root, int x, int y) {
		int depth_x = getNodeDepth(root, x);
		int depth_y = getNodeDepth(root, y);
		if (depth_x != depth_y) {
			return false;
		}
		TreeNode* x_parent = getNodeParent(root, x);
		TreeNode* y_parent = getNodeParent(root, y);
		if (x_parent == y_parent) {
			return false;
		}
		return true;
	}
};

#endif // LEETCODE_993_H
