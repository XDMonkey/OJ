class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        rec=[[1 for j in range(len(nums))] for i in range(len(nums))]
        for i in range(len(nums)):
            if nums[i]==1:
                rec[i][i]=1
            if nums[i]==0:
                rec[i][i]=-1
        max=0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[j]==1:
                    rec[i][j]=rec[i][j-1]+1
                else:
                    rec[i][j]=rec[i][j-1]-1
                if rec[i][j]==0:
                    if max<j-i+1:
                        max=j-i+1
        return max