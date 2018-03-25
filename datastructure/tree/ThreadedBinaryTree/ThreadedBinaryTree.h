//
// Created by wangqing on 2018.3.22.
//

#ifndef THREADEDBINARYTREE_THREADEDBINARYTREE_H
#define THREADEDBINARYTREE_THREADEDBINARYTREE_H

#include <iostream>

using namespace std;


class TreadedBinaryTree {
private:
    struct TreeNode {
        int key;
        int ltag, rtag; // 0: 子节点   1: 线索结点
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode *root;

    /**
     * 中序遍历线索化二叉树
     * @param current
     * @param pre
     */
    void innerTread(TreeNode *current, TreeNode *&pre) {
        if (current != nullptr) {
            innerTread(current->left, pre);
            if (current->left == nullptr) {

                current->left = pre;
                current->ltag = 1;

            }

            if (pre != nullptr && pre->right == nullptr) {
                pre->right = current;
                pre->rtag = 1;
            }

            pre = current;

            innerTread(current->right, pre);
        }
    }

    /**
     * 创建中序线索二叉树
     * @param root
     */
    void createInnerThreadTree(TreeNode *root) {
        if (!root) {
            TreeNode *pre = nullptr;
            innerTread(root, pre);
            pre->right = nullptr;
            pre->rtag = 1;
        }
    }

    /**
     * 得到中序线索树的第一个结点
     * @param root
     * @return
     */
    TreeNode *getFirstNode(TreeNode *root) {
        while (root->ltag == 0) {
            root = root->left;
        }

        return root;
    }

    /**
     * 找到当前结点的后继结点
     * @param pre
     * @return
     */
    TreeNode *next(TreeNode *pre) {
        if (pre->rtag == 1) return pre->right;
        else return getFirstNode(pre->right); // 后继线索结点
    }

    /**
     * 中序遍历中序线索二叉树
     * @param root
     */
    void innerOrder(TreeNode *root) {
        for (TreeNode *current = getFirstNode(root); current != nullptr; current = next(current))
            cout << current->key;
    }

public:
    void createInnerThreadTree() {
        createInnerThreadTree(root);
    }

    void innerOrder() {
        innerOrder(root);
    }
};


#endif //THREADEDBINARYTREE_THREADEDBINARYTREE_H
