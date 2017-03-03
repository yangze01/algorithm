class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg = 1
        if x < 0:
            neg = -1
            xx = -x
        else:
            xx = x
        ret = 0
        while(xx!=0):
            ret = ret*10 + (xx%10)
            xx = xx // 10
        if(ret < -(1<<31) or ret > (1<<31)-1):
            return 0
        return ret*neg

if __name__ == "__main__":
    solution = Solution()
    s = solution.reverse(1534236469)
    print(s)
