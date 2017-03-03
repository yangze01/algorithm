class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        str_prefix = ""
        for i in range(0, len(strs[0])):
            for astr in strs:
                if(len(astr) < i + 1 or astr[i] != strs[0][i]):
                    return str_prefix
            str_prefix += strs[0][i]
        return str_prefix

if __name__ == "__main__":
    solution = Solution()
    print(solution.longestCommonPrefix(["avaasd","avasd"]))
