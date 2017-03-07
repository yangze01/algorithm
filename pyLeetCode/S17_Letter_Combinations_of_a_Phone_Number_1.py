import copy
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        ret = list()
        dig2str = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        for i in range(0,len(digits)):
            # 循环输入数字
            num = int(digits[i])
            tmp = []
            for j in range(0, len(dig2str[num])):
                # 循环数字代表字母
                if len(ret):
                    print("=============================================")

                    for k in range(0, len(ret)):
                        print(i,j,k)
                        print(ret)
                        print(tmp)
                        # 循环待返回list
                        tmp.append(ret[k] + dig2str[num][j])
                else:
                    print("----else----else----else----else-----")
                    print(ret)
                    print(tmp)
                    tmp.append(str(dig2str[num][j]))
            ret = copy.copy(tmp)
        return ret




if __name__ == "__main__":
    solution = Solution()
    print(solution.letterCombinations("234"))
    # tmp = ['a','c','d']
    # ret = copy.copy(tmp)
    # print(ret)
