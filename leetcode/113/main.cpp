#include <iostream>
#include <vector>

using namespace std;

/**
 * 从根节点到叶子节点的所有路径中, 找出路径 (满足该路径上所有节点和满足指定sum)
 *            5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
 *
 */
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {

public:
    vector<vector<int>> vecs;
    vector<int> vec;

    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == nullptr) return vecs;

        findPath(root, sum, vec);

        return vecs;

    }


    void findPath(TreeNode *node, int sum, vector<int> vec) {
        if (node == nullptr) return;

        if (node->val == sum && node->left == nullptr && node->right == nullptr) {
            vec.push_back(node->val);
            vecs.push_back(vec);
        }

        vec.push_back(node->val);

        findPath(node->left, sum - node->val, vec);
        findPath(node->right, sum - node->val, vec);


    }

};


int main() {


}


