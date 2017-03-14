class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if(len(nums) == 1 or len(nums) == 0):
            return len(nums)
        count = 1
        for i in range(1,len(nums)):
            if(nums[i] == nums[i-1]):
                continue
            else:
                nums[count] = nums[i]
                count += 1
        # print(nums)
        return count

if __name__ == "__main__":
    a = [1,1,2,2,5,6,7,7,9]
    solution = Solution()
    print(solution.removeDuplicates(a))
