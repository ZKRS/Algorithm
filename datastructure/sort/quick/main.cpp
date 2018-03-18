#include <iostream>
#include <ctime>

using namespace std;

/**
 * 产生[range_l, range_r]范围内N个数
 * @param N
 * @param range_l
 * @param range_r
 * @return
 */
int *generateRandomArray(int N, int range_l, int range_r) {
    int *A = new int[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        A[i] = rand() % (range_r - range_l + 1) + range_l;
    }
    return A;
}

/**
 * 在[l..r]范围内将A[l]置于相应的位置(左小右大)
 * 从小到大排序, 原地排序, 不稳定, 平均O(nlogn), 最坏O(n^2)
 * 对于近乎有序数组退化成O(n^2)
 * @param A
 * @param N
 * @param l
 * @param r
 * @return
 */
int partition(int A[], int N, int l, int r) {
    int p = A[l];
    int j = l; //j记录A[l]这个数应该在数组中的位置下标
    for (int i = l + 1; i <= r; i++) {
        if (A[i] < p) { //从小到大排序
            j++;
            swap(A[i], A[j]);
        }
    }
    swap(A[l], A[j]);
    return j;
}

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void quickSort(int A[], int N, int l, int r) {
    if (l >= r) return; //分到只有一个元素时就返回
    int mid = partition(A, N, l, r);
    trace(A, N);
    quickSort(A, N, l, mid - 1);
    quickSort(A, N, mid + 1, r);
}


int main() {
//    int N;
//    int A[100];
//    cin >> N;
//    for (int i = 0; i < N; i++) cin >> A[i];
    int N = 10;
    int *A = generateRandomArray(N, 0, 99);
    quickSort(A, N, 0, N - 1);
    trace(A, N);
    return 0;
}