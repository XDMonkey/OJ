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
        temp1 = self.recursion(1)
        temp2 = self.recursion(2)
        res=0
        for i in range(3,n+1):
            if self.s[i - 2:i] > "00" and self.s[i - 2:i] < "10":
                temp1=temp2
            elif self.s[i - 2:i] == "10" or self.s[i - 2:i] == "20":
                temp=temp1
                temp1=temp2
                temp2=temp
            elif self.s[i - 2:i] > "10" and self.s[i - 2:i] < "27":
                temp=temp1
                temp1=temp2
                temp2=temp+temp2
            elif self.s[i - 1] == '0' or self.s[i - 2] == '0':
                return 0
            else:
                temp1=temp2
        return temp2