#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第N个节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        n1 = head;
        n2 = head;
        for i in range(n-1):
            n2 = n2.next;
        
        if(n2.next==None):
            return n1.next
        else:
            n2 = n2.next;
        
        while(n2.next!=None):
            n1 = n1.next;
            n2 = n2.next;
        

        n1.next = n1.next.next
        return head;
    
        
# @lc code=end

