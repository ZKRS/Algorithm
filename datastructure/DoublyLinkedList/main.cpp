#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>

using namespace std;


/**
 * vector<> v 动态数组, 可变长的数组, 动态添加数据, 删除数据
 *              可以使用[]运算符来查找赋值写入操作
 *          method: size(), empty(), push_back(), pop_back(), begin(), end(), insert(), erase(), clear()
 *          insert()和erase()和clear() 是O(n)
 *
 *
 * list<> l: 使用[]运算符来访问特定元素
 *          method: size(), begin(), end(), push_back(), pop_back(), push_front(), pop_front(), insert(), erase(), clear()
 *          insert()和erase()是O(1)
 *          clear()是O(n)
 *
 * queue<int> q
 *          method: pop(), push(), front(), empty(), size()
 *
 * stack<int> s
 *          method: pop(), push(), top(), empty(), size()
 *
 *
 *
 * @tparam Key
 */
template<typename Key>
class DoublyLinkedList {
private:
    struct Node {
        Key key;
        Node *pre;
        Node *next;
    };

    // 头结点可以存储数据标题, 表长等信息, 也可以不存储信息
    Node *nil; // 头结点


    void init() {
        nil = new Node();
        nil->key = NULL;
        nil->pre = nil;
        nil->next = nil;
    }

    Node *listSearch(Key key) {
        Node *cur = nil->next;
        while (cur != nil && cur->key != key) {
            cur = cur->next;
        }

        return cur;

    }

    void deleteNode(Node *node) {
        if (node == nil) return;

        node->pre->next = node->next;
        node->next->pre = node->pre;

        free(node); // 手动释放内存
    }

    /**
   * 头插法
       * 链表的最后一个元素的next是nil头结点
       * nil头结点的pre是链表的最后一个元素
       * 实际上可看成一个环
       *
   */
    void insert(Key key) {
        auto *node = new Node();
        node->key = key;
        node->next = nil->next;
        nil->next->pre = node;
        nil->next = node;
        node->pre = nil;
    }

    /**
      * 尾插法
            * 每次插入的新结点放在链表的尾部
     */
    void insertEnd(Key key) {
        auto *node = new Node();
        node->key = key;
        node->next = nil;
        node->pre = nil->pre;
        nil->pre->next = node;
        nil->pre = node;
    }

public:

    DoublyLinkedList() {
        init();
    }

    void insertNode(Key key) {
        insert(key);
//        insertEnd(key);

    }

    void deleteFirst() {
        deleteNode(nil->next);
    }

    void deleteLast() {
        deleteNode(nil->pre);
    }

    void deleteKey(Key key) {
        deleteNode(listSearch(key));
    }

    void trace() {
        Node *cur = nil->next;
        while (cur != nil) {
            cout << cur->key << " ";
            cur = cur->next;
        }

        cout << endl;
    }
};


int main() {
    DoublyLinkedList<int> l = DoublyLinkedList<int>();

    // 头插法
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(3);
    l.insertNode(4);
    l.insertNode(5);
    l.insertNode(6);
    l.insertNode(7);
    l.insertNode(8);

    // 因为是头插法, 所以输出是按照输入的倒序
    l.trace();

    l.deleteKey(5);
    l.trace();

    return 0;
}