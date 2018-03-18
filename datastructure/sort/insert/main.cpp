#include<iostream>

using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

/**
 * 插入排序稳定
 * O(n^2)
 * @param A
 * @param N
 * @param flag 0: 小->大 1: 大-> 小
 */
void insertSort(int A[], int N, int flag) {
    for (int i = 1; i < N; i++) {
        int p = A[i];
        for (int j = i - 1; j >= 0; j--) {
            if (flag == 0) {
                if (p >= A[j]) { //稳定排序
                    A[j + 1] = p;
                    break;
                }
                if (p < A[j]) A[j + 1] = A[j];
                A[j] = p;
            }
            if (flag == 1) {
                if (p <= A[j]) {
                    A[j + 1] = p;
                    break;
                }
                if (p > A[j]) A[j + 1] = A[j];
                A[j] = p;
            }
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
    insertSort(A, N, 1);

    return 0;
}