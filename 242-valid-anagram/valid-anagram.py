class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        res1="".join(sorted(s))
        res2="".join(sorted(t))
        return res1==res2