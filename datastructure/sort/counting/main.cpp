#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

/**
 * 桶排序, 计数排序 O(n + k), n为元素个数, k为元素中(最大值-最小值), 所有元素均为非负数
 * 稳定排序
 */

int *generateArray(int N, int range_l, int range_r) {
    int *A = new int[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        A[i] = rand() % (range_l - range_r + 1) + range_l;
    return A;
}

int *countingSort(int A[], int N, int min, int max) {
    int count = max - min + 1;
    int *B = new int[count];
    int *res = new int[N];

    for (int i = 0; i < count; i++) B[i] = 0;

    for (int i = 0; i < N; i++) res[i] = 0;

    for (int i = 0; i < N; i++) B[A[i] - min]++;

    for (int i = 1; i < count; i++) B[i] = B[i - 1] + B[i];

    for (int i = N - 1; i >= 0; i++) { //从A[N-1]开始, 则为稳定排序
        res[B[A[i] - min] - 1] = A[i]; //B[A[i]-min]表示第几大, 在res数组中的索引为第几大-1
        B[A[i] - min]--;
    }
    return res;
}

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int N = 5;
    int range_l = 8;
    int range_r = 16;
    int *A, *res;
    A = generateArray(N, range_l, range_r); //随机生成[range_l, range_r]范围内的N个数
    res = countingSort(A, N, range_l, range_r);
    trace(A, N);
    trace(res, N);
}