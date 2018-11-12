/*
 * Runtime: 24ms
 * Score: 16.26%
 */

class Solution {
public:
    int reverse(int x) {
        bool is_negative = (x < 0);
        x = abs(x);
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long result = stol(s);
        if (result > INT_MAX)
            return 0;
        if (is_negative)
            result *= -1;
        return result;
    }
};
