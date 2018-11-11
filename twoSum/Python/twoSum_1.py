"""
Run time: 44ms
Score: 65.97
"""
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = {}
        n = len(nums)
        for i in range(n):
            diff = target - nums[i]
            if diff in m:
                return [m[diff], i]
            else:
                m[nums[i]] = i
