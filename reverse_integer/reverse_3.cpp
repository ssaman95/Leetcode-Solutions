/*
 * Runtime: 16ms
 * Score: 52.45%
 */

class Solution {
public:
    int reverse(int x) {
        bool is_negative = (x <0);
        int ans = 0;
        x = abs(x);
        
        while (x) {
            
            if (ans > INT_MAX / 10)
                return 0;
            ans *= 10;
            
            int tmp = x%10;
            if(ans > INT_MAX - tmp)
                return 0;
            ans += tmp;
            x /= 10;
        }
        
        if (is_negative)
            ans *= -1;
        
        return ans;
    }
};
