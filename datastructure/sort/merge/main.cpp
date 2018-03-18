#include <iostream>

using namespace std;
#define MAX 100
#define SENTINEL 2000000

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(int A[], int N, int left, int mid, int right) {
    int L[MAX / 2 + 2], R[MAX / 2 + 2];
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) A[k] = L[i++]; //稳定排序
        else A[k] = R[j++];
        trace(A, N);
    }
}

/**
 * 左闭右开, 由大到小排序
 * @param A
 * @param N
 * @param left
 * @param right
 */
void mergeSort(int A[], int N, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, N, left, mid);
        mergeSort(A, N, mid, right);
        merge(A, N, left, mid, right);
    }

}


int main() {
    int N;
    int A[MAX];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    mergeSort(A, N, 0, N);
    trace(A, N);

    return 0;
}