#include <iostream>
#include <vector>

using namespace std;


int main() {
    unsigned n;
    cin >> n;
    vector<int> row(n + 1); // row[i] = j 第i个矩阵行数为j, row[n]表示第n个矩阵的列数
    vector<vector<int> > m(n + 1, vector<int>(n + 1)); // m[i][i] = k 表示第i个矩阵到第j个矩阵之间最小运算量为k


    for (int i = 0; i <= n; i++) // 0~n-1都是矩阵行数， n是最后一个矩阵的列数
        cin >> row[i];

    for (int i = 1; i < n + 1; i++)
        m[i][i] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n - i + 1; j++) {

        }
    }


    return 0;

}