#include <iostream>

using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

/**
 * 由小到大
 * O(n^2)
 * @param A
 * @param N
 * @param flag
 */
void bubbleSort(int A[], int N, int flag) {
    for (int i = 0; i < N; i++) { //对每个元素进行冒泡
        for (int j = N - 1; j >= i; j--) {
            if (A[j] < A[j - 1]) swap(A[j - 1], A[j]); //稳定排序
            trace(A, N);
        }
    }
}

int main() {
    int N;
    int A[100];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    trace(A, N);
    bubbleSort(A, N, 0);
    trace(A, N);

    return 0;
}