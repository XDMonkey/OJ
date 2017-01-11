class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s=s.strip()
        m = 0
        for i in range(s.__len__()):
            m += 1
            if s[i] == ' ':
                m = 0
        return m