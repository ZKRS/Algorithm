#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == NULL) return "";
        if (s.size() == 1) return s;
        return dp_solve(s);
    }

    /**
     * dp[i][j] 表示字符串i到j是否回文串
     * 112ms
     * 由外向内判断子串是否回文
     */
    string dp_solve(string &s) {
        unsigned long len = s.size();
        bool dp[len][len];
        unsigned int start = 0;      // 最长回文子串开始索引
        unsigned int maxStrLen = 1; // 最长回文子串长度

        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                dp[i][j] = false;

        // 初始化dp数组, 字符串长度为1肯定为回文, 连续两个字符相等也回文
        for (unsigned int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (s.at(i) == s.at(i + 1)) {
                dp[i][i + 1] = true;
                maxStrLen = 2;
                start = 0;
            }
        }

        for (unsigned int strlen = 3; strlen <= len; strlen++) {
            for (unsigned int i = 0; i <= len - strlen; i++) { // i 表示子串的长度为strlen的开始索引为i
                unsigned int j = i + strlen - 1; //  j为结束索引
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    start = i;
                    maxStrLen = strlen;
                }
            }
        }

        return s.substr(start, maxStrLen);
    }

    /**
     * 由内而外
     * 7ms
     * @param s
     * @return
     */
    string solve(string &s) {
        int min_start = 0, max_len = 1;

        for (int i = 0; i < s.size();) {
            //if(s.size()-i<=max_len/2) break;
            int k = i, j = i; // j为开始索引, k为结束索引

            while (k < s.size() - 1 && s[k] == s[k + 1])
                k++;
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
                k++;
                j--;
            }
            int new_len = k - j + 1;
            if (new_len > max_len) {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};

int main() {
    return 0;
}