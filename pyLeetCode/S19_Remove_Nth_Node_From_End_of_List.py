# Definition for singly-linked list.
from __future__ import print_function
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        res = ListNode(0)
        res.next = head
        tmphead = res
        while(n):
            head = head.next
            n -= 1
        while(head != None):
            tmphead = tmphead.next
            head = head.next
        tmphead.next = tmphead.next.next
        return res.next
    def create_LinkList(self, head):
        tmp = ListNode(2)
        head.next = tmp
        for i in range(3,6):
            newNode = ListNode(i)
            tmp.next = newNode
            tmp = tmp.next
        return head
    def travel_LinkList(self,head):
        while(head.next != None):
            print(head.val,end='')
            print('->',end='')
            head = head.next
        print(head.val)
if __name__ == "__main__":
    head = ListNode(1)
    solution = Solution()
    head = solution.create_LinkList(head)
    solution.travel_LinkList(head)
    solution.removeNthFromEnd(head,2)
    solution.travel_LinkList(head)
