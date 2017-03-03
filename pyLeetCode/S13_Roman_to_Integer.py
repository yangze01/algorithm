class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums = [1000,500,100,50,10,5,1]
        roms = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
        Roman = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
        }
        ssum = Roman[s[-1]]
        for index in range(0,len(s)-1)[::-1]:
            if (Roman[s[index]] < Roman[s[index+1]]):
                ssum -= Roman[s[index]]
            else:
                ssum += Roman[s[index]]
        return ssum
if __name__ == "__main__":
    solution = Solution()
    print(solution.romanToInt("MMMCMXCIX"))
