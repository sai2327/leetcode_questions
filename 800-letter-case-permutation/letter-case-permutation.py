class Solution(object):
    def letterCasePermutation(self, s):
        res=['']
        for ch in s:
            if ch.isalpha():
                res=[i+j for i in res for j in [ch.upper(),ch.lower()]]
            else:
                res=[i+ch for i in res]
        return res
        """
        :type s: str
        :rtype: List[str]
        """
        