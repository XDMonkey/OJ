class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.s = s
        if self.s == "":
            return 0
        return self.recursion(len(s))

    def recursion(self, n):
        if n == 1:
            if self.s[0] > '0':
                return 1
            else:
                return 0
        elif n == 2 and "10" < self.s[n - 2:n] < "27" and not self.s[n-2:n]=="20":
            return 2
        elif n == 2 and "00" < self.s[n - 2:n] < "10":
            return 0
        elif n == 2 and (self.s[n - 2:n] == "10" or self.s[n-2:n]=="20"):
            return 1
        elif n == 2 and (self.s[0] == '0' or self.s[1] == '0'):
            return 0
        elif n == 2:
            return 1
        elif self.s[n - 2:n] > "00" and self.s[n - 2:n] < "10":
            return self.recursion(n - 1)
        elif self.s[n - 2:n] == "10" or self.s[n - 2:n] == "20":
            return self.recursion(n - 2)
        elif self.s[n - 2:n] > "10" and self.s[n - 2:n] < "27":
            return self.recursion(n - 1) + self.recursion(n - 2)
        elif self.s[n - 1] == '0' or self.s[n - 2] == '0':
            return 0
        else:
            return self.recursion(n - 1)