#include <iostream>
#include <vector>

using namespace std;
static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    // 3ms
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        vector<int> result(obstacleGrid.size() + 1, 0);
        int m = obstacleGrid.size() - 1;
        int n = obstacleGrid[0].size() - 1;

        result[m] = 1;

        for (int j = n; j >= 0; j--) {
            for (int i = m; i >= 0; i--) {
                if (obstacleGrid[i][j] == 1)
                    result[i] = 0;
                else
                    result[i] += result[i + 1];
            }
        }

        return result[0];
    }
};

// 5ms
int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
    unsigned long row = obstacleGrid.size();
    unsigned long col = obstacleGrid[0].size();
    vector <vector<int>> dp(row, vector<int>(col, 0));

    for (unsigned long i = 0; i < row; i++) {
        if (!obstacleGrid[i][0]) {
            dp[i][0] = 1;

        } else break;
    }

    for (unsigned long i = 0; i < col; i++) {
        if (!obstacleGrid[0][i]) {
            dp[0][i] = 1;

        } else break;
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (obstacleGrid[i][j]) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

// TODO: dp转换为一维
    
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}