//
// Created by wangqing on 2018.3.7.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREEITERATION_H
#define BINARYSEARCHTREE_BINARYSEARCHTREEITERATION_H

#include <iostream>
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BinarySearchTreeIteration {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node *parent;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
        }
    };

    Node *root;

    Node *insertNode(Key key, Value value, Node *root) {
        if (root == NULL) {
            return new Node(key, value);

        }
        Node *node = root;
        Node *tempNode = NULL;
        Node *newNode = new Node(key, value);
        while (node != NULL) { //找到待插入结点应该所在的父节点(保存到tempNode)
            tempNode = node;
            if (key < node->key)
                node = node->left;
            else if (key > node->key)
                node = node->right;
//            if (key == (*node)->key) {
//                (*node)->value = value;
//                return;
//            }
        }


        if (tempNode->key < key) tempNode->left = newNode;
        else tempNode->right = newNode;

        newNode->parent = tempNode;
    }

    Value *searchNode(Key key, Node *root) {
        if (root == NULL) return NULL;
        Node *node = root;
        while (node) {
            if (key < node->key) node = node->left;
            else if (key > node->key) node = node->right;
            else return &(node->value);
        }
        return NULL;
    }

    Node *getMinimumNode(Node *root) {
        if (root == NULL) return NULL;
        Node *node = root;
        Node *min;
        while (node) {
            min = node;
            node = node->left;
        }
        return min;

    }

    bool removeNode(Key key, Node *root) {
        if (root == NULL) return true;

        Node *node = root;

        while (node) { // 找到待删除结点保存到node
            if (key < node->key) node = node->left;
            else if (key > node->key) node = node->right;
            else break;
        }

        if (node == NULL) return false; // 没找到指定key的结点


        if (node->left && node->right) {    // 待删除结点有左右孩子
            Node *minNode = getMinimumNode(node->right); // 待删除结点的右子树中最小结点
            minNode->parent->left = NULL;
            minNode->right = node->right;
            minNode->parent = node->parent;
            if (node->parent->left == node) node->parent->left = minNode;
            if (node->parent->right == node) node->parent->right = minNode;
            delete node;
        } else if (node->left && node->right == NULL) { // 待删除结点只有左孩子
            node->left->parent = node->parent;
            if (node->parent->left == node) node->parent->left = node->left;
            if (node->parent->right == node) node->parent->right = node->left;
            delete node;
        } else if (node->right && node->left == NULL) { // 待删除结点只有右孩子
            node->right->parent = node->parent;
            if (node->parent->left == node) node->parent->left = node->right;
            if (node->parent->right == node) node->parent->right = node->right;
            delete node;
        } else if (node->right == NULL && node->left == NULL) {
            delete node;
        }

        return true;
    }


    void levelOrderTree(Node *root) {
        queue<Node *> q;
        Node *node;
        q.push(root);
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            cout << node->key << " : " << node->value << endl;
        }
    }

    void inOrderTree(Node *node) {
        if (node != NULL) {
            inOrderTree(node->left);
            cout << node->key << " : " << node->value << endl;
            inOrderTree(node->right);
        }
    }

public:
    BinarySearchTreeIteration() {
        this->root = NULL;
    }

    void insert(Key key, Value value) {
        root = insertNode(key, value, root);
    }

    Value *search(Key key) {
        return searchNode(key, root);
    }

    bool remove(Key key) {
        return removeNode(key, root);
    }

    void inOrder() {
        inOrderTree(root);
    }

    void levelOrder() {
        levelOrderTree(root);
    }

};


#endif //BINARYSEARCHTREE_BINARYSEARCHTREEITERATION_H
