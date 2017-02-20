class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        temp1=1
        temp2=2
        if n<3:
            return n
        for i in range(3,n+1):
            temp=temp1
            temp1=temp2
            temp2+=temp
        return temp2