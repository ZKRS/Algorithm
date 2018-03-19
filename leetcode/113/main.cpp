#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {

public:
    vector<vector<int>> vecs;

    vector <vector<int>> pathSum(TreeNode *root, int sum) {


        vector<int> vec;
        findPath(root, sum, vec);
        pathSum(root->left, sum, vec);
        pathSum(root->right, sum, vec);

        if (vec != NULL) vecs.push(vec);


        return vecs;



    }


    void findPath(TreeNode *node, int sum, vector<int> &vec) {
        if (node == nullptr) return NULL;

        if (node->val == sum) vec.push(node->val);

        findPath(node->left, sum - node->val, vec);
        findPath(node->right, sum - node->val, vec);

    }


};


int main() {


}


