#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * 确定两个字符串(字母构成)的所含字母集完全相同
 * 使用hash表查找, 时间复杂度O(1), 空间复杂度 O(n)
 */
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;

        unordered_map<char, int> count; // 默认值为0

        for (const auto &c : s) {
            ++count[tolower(c)];
        }

        for (const auto &c : t) {
            --count[tolower(c)];

            if (count[tolower(c)] < 0) {
                return false;
            }
        }
        return true;
    }

    bool solve2(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;

    }
};

int main() {

    return 0;
}