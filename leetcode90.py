class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.num=nums
        self.single=[]
        self.res=[[]]
        self.num.sort()
        for i in range(1,len(nums)+1):
            self.recursion(i,1,-1,len(nums))
        newRes=[[]]
        self.res.sort()
        for i in range(1,len(self.res)):
            if self.res[i]!=self.res[i-1]:
                newRes.append(self.res[i])
        return newRes
    def recursion(self,l,i,last,length):
        if i==l+1:
            self.res.append(copy.deepcopy(self.single))
            return
        for m in range(last+1,length-(l-i)):
            self.single.append(self.num[m])
            self.recursion(l,i+1,m,length)
            self.single.pop()