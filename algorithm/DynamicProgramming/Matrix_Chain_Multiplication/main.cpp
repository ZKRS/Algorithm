#include <iostream>
#include <vector>

using namespace std;

/**
 * 矩阵链乘法
 *
     * 确定计算顺序已达到最少乘法运算次数
     * 不一定是从左到右依序计算
 */

int main() {
    unsigned n; // n is number of matrix
    int row, column;
    cin >> n;
    vector<int> p = vector<int>(n + 1); // p[i] = j : the number of row of the matrix i is j
    vector<vector<int> > m = vector<vector<int> >(n, vector<int>(
            n)); // m[i][j] = k : matrix i multiply to matrix j (min operation number is k)

    for (int i = 0; i < n; i++) {
        cin >> row >> column;
        p[i] = row;
        if (i == n - 1) p[n] = column;
    }

    // 动态规划的初始化很重要, 这是后面计算的基础
    for (int i = 1; i < n + 1; i++)
        m[i][i] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = )
    }


    return 0;
}