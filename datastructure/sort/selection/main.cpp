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
 */
void selectSort(int A[], int N) {
    for (int i = 0; i < N; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) { //找到i后面最小元素的下标
            if (A[j] < A[minIndex]) minIndex = j;
        }
        swap(A[i], A[minIndex]);    //寻找最小下标后交换操作导致不稳定
        trace(A, N);
    }

}

int main() {
    int N;
    int A[100];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    trace(A, N);
    selectSort(A, N);
    trace(A, N);
    return 0;
}