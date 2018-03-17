#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <random>

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
        int index;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;

        TreeNode() {
            val = NULL;
            index = NULL;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };

    int h1, h2;
    TreeNode *root;
    int N, range_min, range_max, range; // N: count of nodes  range_min: minimum value of all nodes
    int decision; // 0: left  1: right  2: both

    int generateNumber() {
        random_device r;
        default_random_engine el(r());
        uniform_int_distribution<int> uniform_dist(range_min, range_max);
        return uniform_dist(el);
    }

    void createRandomBinaryTree(TreeNode *root, int current_count) {
        if (current_count > N) return;

        decision = generateNumber() % 3;
        cout << decision << endl;
        if (decision == 0) { // add left child
            if (root->index * 2 > N) return;
            if (root->left == nullptr) {
                TreeNode *node = new TreeNode();
                node->val = generateNumber();
                node->index = root->index * 2;
                node->parent = root;
                root->left = node;
                current_count++;
            }
            createRandomBinaryTree(root->left, current_count);
        } else if (decision == 1) { // add right child
            if (root->index * 2 + 1 > N) return;
            if (root->right == nullptr) {
                TreeNode *node = new TreeNode();
                node->val = generateNumber();
                node->index = root->index * 2 + 1;
                node->parent = root;
                root->right = node;
                current_count++;
            }
            createRandomBinaryTree(root->right, current_count);
        } else { // add both children
            if (root->index * 2 > N) return;
            if (root->left == nullptr) {
                TreeNode *node = new TreeNode();
                node->val = generateNumber();
                node->index = root->index * 2;
                node->parent = root;
                root->left = node;
                current_count++;
            }
            if (root->index * 2 + 1 > N) return;
            if (root->right == nullptr) {
                TreeNode *node = new TreeNode();
                node->val = generateNumber();
                node->index = root->index * 2 + 1;
                node->parent = root;
                root->right = node;
                current_count++;
            }
            createRandomBinaryTree(root->left, current_count);
            createRandomBinaryTree(root->right, current_count);
        }
    }

    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        h1 = maxDepth(root->left) + 1;
        h2 = maxDepth(root->right) + 1;
        return max(h1, h2);
    }

    void trace(TreeNode *root) {
        if (root != nullptr) {
            trace(root->left);
            cout << root->index << " : " << root->val << endl;
            trace(root->right);
        }
    }

public:
    Solution(int N, int range_min, int range_max) {
        this->N = N;
        this->h1 = this->h2 = this->decision = 0;
        this->range_min = range_min;
        this->range_max = range_max;
        this->range = range_max - range_min + 1;
        this->root = new TreeNode();
        srand((unsigned) time(NULL));
        this->root->val = rand() % range + range_min;
        this->root->index = 1;
    }

    void createRandomBinaryTree() {
        createRandomBinaryTree(root, 1);
    }

    int maxDepth() {
        return maxDepth(root);
    }

    void trace() {
        trace(root);
    }
};

int main() {
    int N = 20;
    int range_min = 1;
    int range_max = 100;
    Solution s = Solution(N, range_min, range_max);
    s.createRandomBinaryTree();
    cout << "中序遍历: " << endl;
    s.trace();
    cout << "max depth: " << s.maxDepth() << endl;
    return 0;
}