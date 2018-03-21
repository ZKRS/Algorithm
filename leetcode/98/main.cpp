#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

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
    TreeNode *pre = nullptr;

    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        return solve(root);
//        return solve2(root, LONG_MIN, LONG_MAX);
    }

    bool solve(TreeNode *root) {
        if (root == nullptr) return true;

        if (!solve(root->left)) return false;

        if (pre != nullptr && pre->val >= root->val) return false;

        pre = root;

        return solve(root->right);
    }

    bool solve2(TreeNode *root, int min, int max) {
        if (root == nullptr) return true;

        if (root->val <= min || root->val >= max) return false;

        return solve2(root->left, min, root->val) && solve2(root->right, root->val, max);
    }

    /**
     * 二叉树的非递归中序遍历
     */
    vector<int> innerOrder(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNode *> s;
        while (root != nullptr || !s.empty()) {

            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            res.push_back(root->val);
            s.pop();
            root = root->right;
        }
        return res;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}