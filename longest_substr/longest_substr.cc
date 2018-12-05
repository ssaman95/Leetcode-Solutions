class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sidx = 0, ans = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); ++i) {
            if (m.find(s[i]) != m.end() && m[s[i]] >= sidx) {
                int l = i - sidx;
                ans = max(ans, l);
                sidx = m[s[i]] + 1;
            }
            m[s[i]] = i;
            if (i == s.length() - 1){
                int l = i - sidx + 1;
                ans = max(ans, l);
            }
        }
        return ans;
    }
};
