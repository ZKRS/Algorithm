#include <iostream>

#define MIN -10000000000;

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
    int maxPathSum(TreeNode *root) {

        if (root != nullptr) {

            int left_tree_path = findChildMaxPath(root->left);
            int root_node = root->val;
            int right_tree_path = findChildMaxPath(root->right);

            int left_tree, right_tree;

            if (root->left != nullptr)
                left_tree = maxPathSum(root->left);
            else
                left_tree = -100000000;

            if (root->right != nullptr)
                right_tree = maxPathSum(root->right);
            else
                right_tree = -100000000;

            return max(max(max(max(max(left_tree_path + root_node, root_node), right_tree_path + root_node),
                               left_tree_path + root_node + right_tree_path), left_tree), right_tree);
        }


    }

    int max(int a, int b) {
        return a >= b ? a : b;
    }


    int findChildMaxPath(TreeNode *node) {
        if (node == nullptr) return 0;

        int left = findChildMaxPath(node->left);
        int right = findChildMaxPath(node->right);

        int left_res = max(left + node->val, left);
        int right_res = max(right + node->val, right);

        return max(left_res, right_res);
    }

    int max_sum = -10000000;

    int maxPath(TreeNode *root) {
        int left_res = 0, right_res = 0;
        int root_val = root->val;
        if (root->left != nullptr) left_res = maxPathSum(root->left);
        if (root->right != nullptr) right_res = maxPathSum(root->right);

        root_val = root_val + (left_res > 0 ? left_res : 0) + (right_res ? right_res : 0);
        if (root_val > max_sum)
            max_sum = root_val;

        return root_val + max(left_res, right_res);

    }


    int maxVal = -100000;

    int maxPathSum(TreeNode *root) {
        if (root == NULL)
            return 0;

        maxSum(root);
        return maxVal;
    }

    /*递归函数*/
    int maxSum(TreeNode *root) {
        if (root == NULL)
            return 0;

        /*求以root为根的当前子树的最大路径和*/
        int curVal = root->val;
        int lmaxSum = maxSum(root->left), rmaxSum = maxSum(root->right);
        if (lmaxSum > 0)
            curVal += lmaxSum;
        if (rmaxSum > 0)
            curVal += rmaxSum;

        if (curVal > maxVal)
            maxVal = curVal;

        /*返回以当前root为根的子树的最大路径和*/
        return max(root->val, max(root->val + lmaxSum, root->val + rmaxSum));
    }

};

};


int main() {
//    std::cout << maximum3(0, -3, 0) << std::endl;
    return 0;
}