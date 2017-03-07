class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def dfs(num,string,ret):
            if num == length:
                ret.append(string)
                return ret
            for letter in dict[digits[num]]:
                dfs(num+1,string+letter,ret)

        dict = {'2':['a','b','c'],
                '3':['d','e','f'],
                '4':['g','h','i'],
                '5':['j','k','l'],
                '6':['m','n','o'],
                '7':['p','q','r','s'],
                '8':['t','u','v'],
                '9':['w','x','y','z']
                }
        length = len(digits)
        ret = []
        if length == 0:
            return ret
        else:
            dfs(0,'',ret)
            return ret
if __name__ == "__main__":
    solution = Solution()
    print(solution.letterCombinations("23"))
    # tmp = ['a','c','d']
    # ret = copy.copy(tmp)
    # print(ret)
