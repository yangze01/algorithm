class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums = sorted(nums)
        ret = None
        for i in range(0,len(nums)-1):
            left = i + 1
            right = len(nums)-1
            while(left < right):
                ssum =  nums[i] + nums[left] + nums[right]
                if(ret == None or abs(ssum - target) < abs(ret - target)):
                    ret = ssum
                if(ssum <= target):
                    left += 1
                else:
                    right -= 1
        return ret

if __name__ == "__main__":
    nums_list = [-1,2,1,-4]
    solution = Solution()
    print(solution.threeSumClosest([-1,2,1,-4],1))
