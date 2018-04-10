#include <iostream>

using namespace std;

/**
 * 将字符串转换为数值类型
 * 注:
 *   0. 确定正负号
 *   1. 从第一个数字字符开始, 之前可能有多个空格
 *   2. 忽略之后的非数字字符
 *   3. 如果全是空格或者字符串为空就不需要转换, 输出0
 *   4. 如果转换后的结果超过32位有符号整型则输出 INT32_MAX(2147483647) or INT32_MIN(-2147483648)
 */
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;

        int i = 0, sign = 1; // sign默认为正号

        while (str[i] == ' ') i++; // 去除开头的空格

        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i] == '-'); // 判断正负号
            i++;
        }

        int n = 0;

        int max = INT32_MAX / 10;

        while (str[i] >= '0' && str[i] <= '9') {
            // 边界判断
            if ((n > max || (n == max && (str[i] - '0' > 7))) && sign == 1) {
                return INT32_MAX;
            }
            if ((n > max || (n == max && (str[i] - '0' > 8))) && sign == -1) {
                return INT32_MIN;
            }

            n = n * 10 + (str[i++] - '0');

        }


        return sign * n;
    }
};


int main() {
    std::cout << INT32_MIN / 10 << std::endl;
    return 0;
}