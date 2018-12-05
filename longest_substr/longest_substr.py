class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start_i = ans = 0
        d = {}
        
        for i in range(len(s)):
            if s[i] in d and d[s[i]] >= start_i:
                l = i - start_i
                ans = max(ans, l)
                start_i = d[s[i]] + 1
                d[s[i]] = i
            
            d[s[i]] = i
            
            if i+1 == len(s):
                l = i - start_i + 1
                ans = max(ans, l)
                
        return ans
