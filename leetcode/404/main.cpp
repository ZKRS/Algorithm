#include <iostream>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int sum = 0;

    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) return 0;
        if (root->right->left == nullptr && root->right->right == nullptr) return 0;
        sumOfLeftLeaves(root->left);
        if (root->right == nullptr) return sum += root->val;

        sumOfLeftLeaves(root->right);
        int sum(TreeNode *node, bool isLeft) {
            if (node == nullptr) return 0;
            if (isLeft && node->left == nullptr && node->right == nullptr) return node->val;
            return sum(node->left, true) + sum(node->right, false);
        }

        int sumOfLeftLeaves(TreeNode *root) {
            return sum(root, false);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}