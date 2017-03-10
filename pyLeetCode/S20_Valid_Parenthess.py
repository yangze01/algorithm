class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        a = {'(', '[', '{'}
        c = {"()", "[]", "{}"}
        res = []
        for i in s:
            if i in a:
                res.append(i)
            else:
                if(len(res) == 0 or (res.pop() + i not in c)):
                    return False
        if(len(res) == 0):
            return True
        else:
            return False
