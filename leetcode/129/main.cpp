#include <iostream>
#include <cmath>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 从根到叶子结点的每条路径的结点组成的数进行求和, 每个结点的数字是0 ~ 9
 *
 * 构造递归函数的参数列表很重要!很重要!很重要!
 * 或者是递归函数的返回值很重要
 * 并且明确每个参数的具体含义, 有点循环不变量的意思
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


    int sumNumbers(TreeNode *root) {
        return sum(root, 0);
    }

    /**
     * s 是父节点的值, 不是当前结点root的值
     * @param root
     * @param s
     * @return
     */
    int sum(TreeNode *root, int s) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return s * 10 + root->val; // 递归到叶子结点就开始回溯
        return sum(root->left, s * 10 + root->val) + sum(root->right, s * 10 + root->val);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}