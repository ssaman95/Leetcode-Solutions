"""
Run time: 36s
Score: 99.68
"""

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = dict()
        for i, x in enumerate(nums):
            diff = target - x
            if diff in m:
                return [m[diff], i]
            else:
                m[x] = i
