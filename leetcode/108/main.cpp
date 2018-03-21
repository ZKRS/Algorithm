#include <iostream>
#include <vector>

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
    TreeNode *sortedArrayToBST(vector<int> &nums) {

        if (nums.empty() || nums.size() == 0)
            return nullptr;
        vector<int>::iterator it = nums.begin();
        solve(nums, it, 0, nums.size()); // 左闭右开
    }

    TreeNode *solve(vector<int> nums, vector<int>::iterator it, int left, int right) {
        if (it != nums.end() && left < right) {
            it++;
            int mid = left + ((right - left) >> 1);
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = solve(nums, it, left, mid);
            root->right = solve(nums, it, mid + 1, right);
            return root;
        }

        return nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}