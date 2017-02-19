class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.res=[]
        l=[]
        self.recursion(n,-1,1,k,l)
        return self.res

    def recursion(self,n,p,i,k,l):
        if i==k+1:
            return
        for m in range(p+1,n-(k-i)):
            l.append(m+1)
            if i==k:
                self.res.append(copy.deepcopy(l))
            self.recursion(n,m,i+1,k,l)
            l.pop()