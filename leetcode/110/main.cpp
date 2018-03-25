#include <iostream>
#include <algorithm>
#include <math.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * 左右子树递归, 用一个结构体保存左右子树的高度和左右子树是否是平衡树
 * 用时: 12ms 击败33%
 *
 * 9ms代码:
 * class Solution {
    public:
        int  UNBALANCED = -100;
        int get_height(TreeNode* root){
            if (root == NULL){
                return -1;
            }
            int l = get_height(root->left);
            int r = get_height(root->right);
            if (l == UNBALANCED || r == UNBALANCED || abs(l-r) > 1){
                return UNBALANCED;
            }
            return 1+max(l,r);
        }
        bool isBalanced(TreeNode* root) {
            return get_height(root)!=UNBALANCED;
        }
    };

 * 10ms
 * class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if(!root) return true;
            int left = depth(root->left);
            int right = depth(root->right);
            if(left==-1||right==-1||abs(left-right)>1) return false;
            else return true;
        }
        int depth(TreeNode* cur)
        {
            if(!cur) return 0;
            int left = depth(cur->left);
            int right = depth(cur->right);
            if(left==-1||right==-1||abs(left-right)>1) return -1;
            else return max(left,right)+1;
        }
    };
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
    struct Res {
        int height;
        bool isBalance;

        Res(int height, bool isBalance) {
            this->height = height;
            this->isBalance = isBalance;
        }

    };


    bool isBalanced(TreeNode *root) {
        return solve(root)->isBalance;
    }

    Res *solve(TreeNode *root) {

        if (root == nullptr) return new Res(0, true);

        auto *left_node = solve(root->left);
        auto *right_node = solve(root->right);

        Res *res = nullptr;
        if (abs(left_node->height - right_node->height) <= 1 && right_node->isBalance && left_node->isBalance)
            res = new Res(max(left_node->height, right_node->height) + 1, true);
        else
            res = new Res(max(left_node->height, right_node->height) + 1, false);
        return res;
    }

    int max(int a, int b) {
        return a >= b ? a : b;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}