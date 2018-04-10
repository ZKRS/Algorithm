#include <iostream>

using namespace std;

/**
 * 用一维数组实现队列
     * 指定大小的一维数组作为环形缓冲区
 *
 * 使用数组用循环构造队列
     * tail始终指向最后一个元素的后一位
     * head始终指向第一个元素
 *
 * 也可以使用单链表或双向链表实现
 *
 * 堆栈也可以使用链表实现
 *      如果链表是头插法构造, 则可以使用单链表
 *      如果链表是尾插法构造, 则要使用双向链表
 */
template<typename Key>
class Queue {
private:
    Key *queue;
    int n;
    int head;
    int tail;
public:

    Queue(int n) {
        this->n = n;
        head = 0;
        tail = 0;
        queue = new Key[n];
    }

    bool isEmpty() { // 空
        return head == tail;
    }

    bool isFull() { // 满, 实际上数组中还有一个位置就是tail这个位置上是空的
        return head == (tail + 1) % n;
    }

    void enqueue(Key key) { // 添加元素时是tail指针在变化
        if (isFull()) return;
        queue[tail] = key;

        tail = (tail + 1) % n;
    }

    Key dequeue() { // 删除元素时是head指针在变化
        if (isEmpty()) return NULL;
        head = (head + 1) % n;
        return queue[head + 1];
    }

    Key front() {
        return queue[head];
    }

    void trace() {
        for (int i = 0; i < n - 1; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    struct pp {
        char name[100];
        int time;
    };

    int n, page_time;
    int end_time = 0;
    cin >> n >> page_time;

    Queue<pp *> q = Queue<pp *>(n + n);

    for (int i = 0; i < n; i++) {
        auto *p = new pp();
        cin >> p->name;
        cin >> p->time;
        q.enqueue(p);
    }

    while (!q.isEmpty()) {
        if (q.front()->time <= page_time) {
            pp *pp1 = q.dequeue();
            end_time += pp1->time;
            cout << pp1->name << " : " << end_time << endl;
        } else {
            pp *pp2 = q.dequeue();
            pp2->time = pp2->time - page_time;
            q.enqueue(pp2);
            end_time += page_time;
        }
    }

    return 0;
}