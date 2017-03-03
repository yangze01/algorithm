
class Solution:
    # @param {string} str
    # @return {integer}
    def myAtoi(self, str):
        INT_MAX = (1<<31)-1
        INT_MIN = -(1<<31)
        index = 0
        while(str[index] == " "):
            index += 1
        flag = 1
        if index < len(str) and str[index] == '-':
            index += 1
            flag = -1
        elif index< len(str) and str[index] == '+':
            index += 1
        res = 0
        while index <len(str):
            # print(res)
            if(str[index]<'0' or str[index]>'9'):
                return res * flag
            digit = ord(str[index])-ord('0')
            if flag == 1 and res*10+digit>INT_MAX:
                return INT_MAX
            if flag == -1 and res*10+digit>-INT_MIN:
                return INT_MIN
            res = res * 10 + digit
            index += 1
        return flag * res

if __name__ == "__main__":
    solution = Solution()
    ret = solution.myAtoi("  -0012a42")
    print(ret)
