#include <iostream>
#include <queue>
#include "BinarySearchTreeIteration.h"

using namespace std;

/**
 * 二叉搜索树的插入结点, 删除结点, 搜索键值操作
 * 通过二叉搜索树这种数据结构构建 查找表(字典)
 * 对每个有用的信息(value)添加一个索引(key)
 * 通过索引key来构建二叉搜索树
 * 通过每次插入一个结点来构造整棵搜索二叉树, 可能出现生成像链表(或者树的层数太高)一样的树
 * 因此需要进行平衡操作
 * @tparam Key
 * @tparam Value
 * @tparam another
 */
template<typename Key, typename Value>
class BinarySearchTreeRecursion {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) { // new的时候会被调用初始化函数
            this->key = key;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
    };

    Node *root;
    int count; // 结点个数

    /**
     * 递归实现, 插入新的结点(键值对)
     * @param key
     * @param value
     */
    Node *insertNode(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value); //new返回的结构体变量的地址
        }
        if (key == node->key) { // 覆盖, 更该原来信息
            node->value = value;
        } else if (key < node->key) {
            node->left = insertNode(node->left, key, value);
        } else {
            node->right = insertNode(node->right, key, value);
        }
    }

    /**
     * 判断某个结点是否存在字典中
     * @param node
     * @param key
     * @return
     */
    bool isExist(Node *node, Key key) {
        if (node == NULL) return false;
        if (node->key == key) return true;
        if (node->key < key) return isExist(node->right, key);
        else return isExist(node->left, key);
    }

    /**
     * @param node
     * @param key
     * @return Value* 因为返回值可能是Value, 还可能是NULL
     */
    Value *searchNode(Node *node, Key key) {
        if (node == NULL) return NULL; // key不存在
        if (node->key == key) return &(node->value);
        if (node->key > key) return searchNode(node->left, key);
        else return searchNode(node->right, key);
    }

    /**
     * 最小值一定是最左的结点, 从某一节点开始, 一直往该节点的左边递归查找, 直至找不到左孩子
     * @param node
     * @return
     */
    Node *deleteMinimumNode(Node *node) {
        if (node->left == NULL) { // 只有右孩子或者没有
            Node *right = node->right;
            delete node;
            count--;
            return right;
        }
        node->left = deleteMinimumNode(node->left);
        return node;
    }

    Node *deleteMaximumNode(Node *node) {
        if (node->right == NULL) { // 只有左孩子或者没有
            Node *left = node->left;
            delete node;
            count--;
            return left;
        }
        node->right = deleteMaximumNode(node);
        return node;
    }

    Node *minimumNode(Node *node) {
        if (node->left == NULL) return node;
        else return minimumNode(node->left);
    }

    Node *maximumNode(Node *node) {
        if (node->right == NULL) return node;
        else return maximumNode(node->right);
    }

    /**
     * 分情况: 删除的结点只有一个孩子, 把那个孩子结点替换成待删除结点自身
     *         删除的结点有两个孩子, 把右孩子为根的树的最小结点替换成待删除结点自身
     *                              或者把左孩子为根的树最大结点替换成待删除结点自身
     *
     * @param node
     * @param key
     * @return
     */
    Node *removeNode(Node *node, Key key) {
        if (node == NULL) return NULL;
        if (node->key == key) {
            if (node->right != NULL && node->left != NULL) { // 待删除结点有两个孩子结点
                Node *right = node->right;
                count--;
                delete node;
                Node *swapNode = minimumNode(right); // 先找到
                Node *copySwapNode = new Node(swapNode->key, swapNode->value); // 再copy
                delete swapNode; // deleteMinimum(right); 最后删除
                return copySwapNode;
            } else if (node->right == NULL && node->left != NULL) { // 待删除结点只有左孩子
                Node *left = node->left;
                delete node;
                count--;
                return left;
            } else if (node->right != NULL && node->left == NULL) { // 待删除结点只有右孩子
                Node *right = node->right;
                delete node;
                count--;
                return right;
            } else { // 待删除结点为叶子结点
                return NULL;
            }
        }

        if (node->key < key) node->right = removeNode(node->right, key);
        if (node->key > key) node->left = removeNode(node->left, key);
        return node;
    }

    void postOrderTree(Node *node) {
        if (node != NULL) {
            postOrderTree(node->left);
            postOrderTree(node->right);
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

    void preOrderTree(Node *node) {
        if (node != NULL) {
            cout << node->key << " : " << node->value << endl;
            preOrderTree(node->left);
            preOrderTree(node->right);
        }
    }

    /**
     * 二叉搜索树的层序遍历, 使用队列
     * @param node
     */
    void levelOrderTree(Node *node) {
        queue<Node *> q;
        Node *frontNode;
        q.push(node);
        while (!q.empty()) {
            frontNode = q.front();
            q.pop();
            cout << frontNode->key << " : " << frontNode->value << endl;
            if (frontNode->left) q.push(frontNode->left);
            if (frontNode->right) q.push(frontNode->right);
        }
    }

public:
    BinarySearchTreeRecursion() {
        root = NULL;
        count = 0;
    }

    void insert(Key key, Value value) {
        root = insertNode(root, key, value);
    }

    Value *search(Key key) {
        return searchNode(root, key);
    }

    void remove(Key key) {
        removeNode(root, key);
    }

    void levelOrder() {
        levelOrderTree(root);
    }

    void inOrder() {
        inOrderTree(root);
    }
//    ~BinarySearchTree() {
//        //TODO
//    }
};

int main() {
    BinarySearchTreeIteration<int, int> bst = BinarySearchTreeIteration<int, int>();
    bst.insert(4, 40);
    bst.insert(1, 10);
    bst.insert(5, 50);
    bst.insert(2, 20);
    bst.insert(6, 60);
    bst.insert(3, 30);
//    cout << *(bst.search(4));
    cout << "==========层序遍历===========" << endl;
//    bst.levelOrder();
//    cout << "==========中序遍历===========" << endl;
    bst.inOrder();
//    bst.remove(6);
//    cout << "=====删除结点6后中序遍历======" << endl;
//    bst.inOrder();
    return 0;
}