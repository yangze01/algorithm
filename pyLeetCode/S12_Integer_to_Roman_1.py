class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ints = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        roms = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        i = 0
        s = ""
        for i in range(0,len(ints)):
            while(num - ints[i] >= 0):
                num -= ints[i]
                s += roms[i]
        return s
if __name__ == "__main__":
    solution = Solution()
    print(solution.intToRoman(3999))
