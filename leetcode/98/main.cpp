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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return  solve(root, root->val, false);
    }

    bool solve(TreeNode *root, int num, bool isLeft) {
        if (root != nullptr) {
            solve(root->left, root->val, true);
            if (root->val >= num && isLeft) return false;
            solve(root->right, root->val, false);
        }

        return true;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}