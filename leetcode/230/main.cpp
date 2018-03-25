#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 中序遍历求第k小元素
 * kth: 表示遍历到第k个元素
 * res: 存放结果
 * 用时: 18ms
 *
 * 用堆栈中序遍历: 用时15ms
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kth = 1;
    int res;

    int kthSmallest(TreeNode *root, int k) {
//        recursionSolve(root, k);
//        return res;
        return stackSolve(root, k);
    }

    int stackSolve(TreeNode *root, int k) {
        stack<TreeNode *> s;
        vector<int> res;
        while (root || !s.empty()) { // 只要还存在结点没有放在vector中就进行循环
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res[k - 1];
    }

    void recursionSolve(TreeNode *root, int k) {
        if (root) {
            recursionSolve(root->left, k);
            if (kth == k) {
                res = root->val;
                kth++;
                return; //一旦找到第k个元素就返回, 不用再递归下去, 又18ms减少至16ms, 击败66%
            }
            kth++;
            recursionSolve(root->right, k);
        }

    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}