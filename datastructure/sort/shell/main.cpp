#include <iostream>

using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void shellSort(int A[], int N) {
    int h = 1;     //求最大步长
    while (h < N / 3) {
        h = h * 3 + 1;
    }

    while (h >= 1) {
        for (int i = h; i < N; ++i) {
            int p = A[i];
            int j;
            for (j = i; j >= h && p < A[j - h]; j -= h) {
                A[j] = A[j - h];
            }
            A[j] = p;
        }
        h /= 3;
    }
}

int main() {
    int N;
    int A[100];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    trace(A, N);
    shellSort(A, N);
    trace(A, N);
    return 0;
}