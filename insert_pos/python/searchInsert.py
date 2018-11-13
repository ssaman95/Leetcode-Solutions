class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        lo = 0
        hi = len(nums)-1
        while lo <= hi:
            mid = lo + (hi - lo)//2
            if target < nums[mid]:
                hi = mid-1
            elif target > nums[mid]:
                lo = mid+1
            else:
                return mid
        return lo
