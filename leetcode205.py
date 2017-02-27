class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        map={}
        map2={}
        for i in range(len(s)):
            if s[i] in map:
                if map[s[i]]!=t[i]:
                    return False
            else:
                map[s[i]]=t[i]
            if t[i] in map2:
                if map2[t[i]]!=s[i]:
                    return False
            else:
                map2[t[i]]=s[i]
        return True

