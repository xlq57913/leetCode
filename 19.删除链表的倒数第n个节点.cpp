/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *n1 = head;
        ListNode *n2 = head;
        ListNode *tmp = nullptr;
        for(int i=1;i<n;i++){
            n2 = n2->next;
        }
        if(n2->next==nullptr){
            tmp = head;
            n1 = n1->next;
            delete tmp;
            return n1;
        }else{
            n2 = n2->next;
        }
        while(n2->next!=nullptr){
            n1 = n1->next;
            n2 = n2->next;
        }

        tmp = n1->next;
        n1->next = tmp->next;
        delete tmp;
        return head;
    }
};
// @lc code=end

