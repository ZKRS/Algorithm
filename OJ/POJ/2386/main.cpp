#include <iostream>
#include <vector>
#define MAX_N 100
#define MAX_M 100

char field[MAX_N][MAX_M];

using namespace std;


void sovle(int N, int M, char& feild[][]) {

} 
int main() {
    int N, M;
    cin >> N >> M; // N:高 M:宽
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> field[i][j];
        }
    }
    return 0;
}