#include <iostream>
#include <ctime>
#include <algorithm>

/**
 * 堆这种数据结构多适用于动态数据的维护
 * 以下堆的根元素是数组下标为1
 */
using namespace std;


/**
 * @param N 元素的个数, 元素存放从1开始
 * @param range_l
 * @param range_r
 * @return
 */
int *generateArray(int N, int range_l, int range_r) {
    int *A = new int[N + 1];
    srand(time(NULL));
    for (int i = 1; i < N + 1; i++) {
        A[i] = rand() % (range_l - range_r + 1) + range_l;
    }
    return A;
}

/**
 * @param A
 * @param i
 */
void shiftUp(int A[], int i) {
    while (i / 2 >= 1) {
        int parent = i / 2;
        if (A[parent] < A[i])
            swap(A[parent], A[i]);
        i = parent;
    }
}

void shiftDown(int A[], int i, int N) {
    int l, r, greater;
    while (i * 2 <= N) {
        l = 2 * i;
        r = l + 1;
        greater = A[l] >= A[r] ? l : r;
        if (A[greater] > A[i])
            swap(A[greater], A[i]);
        i = greater;
    }
}

void shiftDown2(int A[], int i, int N) {
    int l, r, greater;
    while (i * 2 < N) { //注意不能有等于号
        l = 2 * i;
        r = l + 1;
        greater = A[l] >= A[r] ? l : r;
        if (A[greater] > A[i])
            swap(A[greater], A[i]);
        i = greater;
    }
}

/**
 * 将已有数组转变成最大堆, shiftDown操作 O(n)
 * 构建最大堆
 * @param A
 * @param N
 */
void changeToMaximumHeap(int A[], int N) {
    for (int i = N / 2; i >= 1; i--) { // 对每个非叶子结点操作
        shiftDown(A, i, N);
    }
}

/**
 * 将已有数组转变成最大堆, shiftUp操作 O(nlgn)
 * @param A
 * @param N
 */
void changeToMaximumHeap2(int A[], int N) {
    for (int i = 2; i < N + 1; i++) {
        shiftUp(A, i);
    }
}

/**
 * 堆排序, 最大堆, 由大到小, 每次取根元素
 * 需要创建额外的N个空间
 * @param A
 * @param N
 * @return
 */
int *heapSort(int A[], int N) {
    int *B = new int[N];
    int end = N;
    for (int i = 1; i < N + 1; i++) {
        B[i - 1] = A[1];
        A[1] = A[end];
        end -= 1;
        shiftDown(A, 1, end);
    }
    return B;

}

/**
 * 原地排序
 * @param A
 * @param N
 * @return
 */
void heapSort2(int A[], int N) {
    int end = N;
    for (int i = N; i >= 1; i--) {
        swap(A[1], A[end]);
        end -= 1;
        shiftDown2(A, 1, end);
    }
}

/**
 * 打印数组
 * @param A
 * @param N
 */
void trace(int A[], int N) {
    for (int i = 1; i < N + 1; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

/**
 * 弹出优先队列的优先级最高的元素
 * @param A
 * @return
 */
int top(int A[]) {
    return A[1];
}

/**
 * 向堆中添加一个元素, 直接添加至数组末尾
 * @param A
 * @param N
 */
void insert(int A[], int N) {

}

/**
 * 把堆的根元素拿出来
 * @param A
 * @param N
 * @return
 */
int extract(int A[], int N) {

    return 0;
}

int main() {
    int N = 10;
    int *A = generateArray(N, 0, 20);
    int *B; //对堆C排序后的结果保存
    int *C = generateArray(N, 0, 20);
    cout << "原数组: ";
    trace(A, N);

    changeToMaximumHeap(A, N);
    cout << "shiftDown构建堆后: ";
    trace(A, N);
    cout << "shiftDown构建的堆的原地排序结果: ";
    heapSort2(A, N);
    trace(A, N);

    cout << endl << "shiftUp构建堆: ";
    changeToMaximumHeap2(C, N);
    trace(C, N);

    cout << "shiftDown构建的堆的排序结果: ";
    B = heapSort(C, N);
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }

    return 0;
}