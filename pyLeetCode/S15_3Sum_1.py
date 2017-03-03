
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        res = list()
        for i in range(0,len(nums)-2):
            if i and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = len(nums) - 1
            while(left < right):
                print(i,left,right)
                print(nums[left],nums[right],nums[i])
                print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
                if( nums[left] + nums[right] + nums[i] == 0):
                    res.append([nums[i],nums[left],nums[right]])
                    left += 1
                    right -= 1
                    while(left < right and nums[left] == nums[left-1]):
                        left += 1
                    while(left < right and nums[right] == nums[right + 1]):
                        right -= 1
                elif(nums[left] + nums[right] + nums[i] > 0):
                    right -= 1
                else:
                    left +=1
        return res

if __name__ == "__main__":
    a = [-2, 0, 0, 2, 2]
    solution = Solution()
    print(solution.threeSum(a))
