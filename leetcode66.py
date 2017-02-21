class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        num=0
        for i in digits:
            num=num*10+i
        num+=1
        return map(int,str(num))