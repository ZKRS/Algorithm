#include <iostream>
#include <vector>

using namespace std;

/**
 * dp[i][j] = z 走到第i行第j列的方法数z
 */

class Solution {
public:


    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) return 0;

        int dp[101][101];

        for (int i = 0; i < 100; i++)
            dp[i][0] = 1;
        for (int j = 0; j < 100; j++)
            dp[0][j] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }


};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}