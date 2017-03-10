class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        p = x
        q = 0
        while(p>=10):
            q *= 10
            q += p%10
            p//=10
        return q == x//10 and p == x%10

class Solution2(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x<0:
            return False
        else:
            return x == self.reverse(x)

    def reverse(self,x):
        y = 0
        while(x!=0):
            y = y*10 + x%10
            x = x//10
        return y

if __name__ == "__main__":
    solution = Solution()
    print(solution.isPalindrome(121))
