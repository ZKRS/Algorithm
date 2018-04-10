#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 求 最长公共子序列
 *
 * 输入: q 对字符串, 每个字符串各占一行
 * 输出: 没对字符串公共子序列长度
 *
 */
using namespace std;


int longestCommonSubsequence(string s1, string s2) {
    auto *common = new char[s1.size()];
    // 二维数组memo[i][j] = k 表示 s1中前i个字符和s2中前j个字符的最长公共子序列长度为k
    // 注: memo[i][j] 中i, j 表示字符的个数, 不是字符的索引
    // 注: s1[i] 中的i表示索引值

    vector<vector<int> > memo(s1.size() + 1, vector<int>(s2.size() + 1));
    for (int i = 0; i < s2.size() + 1; i++) memo[0][i] = 0; // s1中取0个字符时公共最长子序列长度肯定是0
    for (int i = 0; i < s1.size() + 1; i++) memo[i][0] = 0; // s2中取0个字符时公共最长子序列长度肯定为0

    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                memo[i + 1][j + 1] = memo[i][j] + 1;
                common[memo[i][j]] = s1[i];
            }
            if (s1[i] != s2[j]) memo[i + 1][j + 1] = max(memo[i + 1][j], memo[i][j + 1]);
        }
    }

    for (int k = 0; k < memo[s1.size()][s2.size()]; ++k)
        cout << common[k];

    cout << endl;

    return memo[s1.size()][s2.size()];

}

int main() {
    int q;
    string s1, s2;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s1 >> s2;
        cout << longestCommonSubsequence(s1, s2) << endl;
    }


    return 0;
}