class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        start = 0
        for i in nums:
            if(i != val):
                nums[start] = i
                start += 1
        return start
