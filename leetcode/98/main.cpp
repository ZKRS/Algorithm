#include <iostream>
#include <climits>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *pre;
    = nullptr;

    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        return solve(root);
        return solve2(root, LONG_MIN, LONG_MAX);
    }

    bool solve(TreeNode *root) {
        if (root == nullptr) return true;

        if (!solve(root->left)) return false;

        if (pre != nullptr && pre->val > root->val) return false;

        pre = root;

        return solve(root->right);
    }

    bool solve2(TreeNode *root, int min, int max) {
        if (root == nullptr) return true;

        if (root->val <= min || root->val >= max) return false;

        return solve2(root->left, min, root->val) && solve2(root->right, root->val, max);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}