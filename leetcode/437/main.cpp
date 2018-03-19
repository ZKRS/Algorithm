#include <iostream>

using namespace std;


/**
 * 二叉树中任意一条路径上的节点的数值和等于指定sum
 *
          10
         /  \
        5   -3
       / \    \
      3   2   11
     / \   \
    3  -2   1
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (root == nullptr) return 0;

        return findPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    /**
     * 从指定node为根节点开始找路径
     * @param node
     * @param sum
     * @return
     */
    int findPath(TreeNode *node, int sum) {
        if (node == nullptr) return 0;
        int res = 0;
        if (sum == node->val) res++;
        //以下这两个递归可以遍历以node为根节点的树
        res += findPath(node->left, sum - node->val);
        res += findPath(node->right, sum - node->val);

        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}