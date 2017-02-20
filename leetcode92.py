# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m==n:
            return head
        res=head
        rec=head
        for i in range(1,m-1):
            head=head.next
        start=head
        if not m==1:
           head=head.next
        start1=head
        for i in range(1,n):
            rec=rec.next
        end1=rec
        end=rec.next
        self.recursion(head,m,n)
        start.next=end1
        start1.next=end
        if not m==1:
            return res
        else:
            return end1
    def recursion(self,head,m,n):
        if m<n:
            self.recursion(head.next,m+1,n)
            head.next.next=head