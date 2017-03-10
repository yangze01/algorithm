
height = [1,2,3,4,5,6,7]
class Solution(object):
    def maxArea(self,height):
        max_val = 0
        for i in range(0,len(height)-1):
            for j in range(i+1,len(height)):
                print(i,j)
                tmp = (j-i)*min(height[i],height[j])
                if(tmp>max_val):
                    max_val = tmp
        return max_val
if __name__ == "__main__":
    solution = Solution()
    print(solution.maxArea(height))
