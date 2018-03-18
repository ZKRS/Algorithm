#include <iostream>

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
class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode() : val(NULL), left(nullptr), right(nullptr) {}
    };

    TreeNode *left_result, *right_result;


    /**
     * 普通二叉树
     * 寻找两个给定结点的公共最近祖先
                _______3______
               /              \
            ___5__          ___1__
           /      \        /      \
           6      _2       0       8
                 /  \
                 7   4

     * @param root
     * @param p
     * @param q
     * @return
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {


        if (!root || root == p || root == q) return root;

        left_result = lowestCommonAncestor(root->left, p, q);
        right_result = lowestCommonAncestor(root->right, p, q);

        if (left_result && right_result) return root;
        else if (!right_result) return left_result;
        else if (!left_result) return right_result;

    }


public:


};

int main() {
    return 0;
}