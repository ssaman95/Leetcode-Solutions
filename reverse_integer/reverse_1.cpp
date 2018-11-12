/*
 * Runtime: 28ms
 * Score: 6.8%
 */

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            int tmp = x%10;
            res = res*10 + tmp;
            if (res < INT_MIN || res > INT_MAX)
                return 0;
            x /= 10;
        }
        return res;
    }
};
