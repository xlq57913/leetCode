/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* nhead = nullptr;
        ListNode* tmp = nullptr;
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        if(l1->val < l2->val){
            nhead = l1;
            l1 = l1 -> next;
        }else{
            nhead = l2;
            l2 = l2 -> next;
        }
        tmp = nhead;
        while(true){
            if(l1 == nullptr){
                tmp -> next = l2;
                return nhead;
            }
            if(l2 == nullptr){
                tmp -> next = l1;
                return nhead;
            }
            if(l1->val < l2->val){
                tmp -> next = l1;
                tmp = tmp -> next;
                l1 = l1 -> next;
            }else{
                tmp -> next = l2;
                tmp = tmp -> next;
                l2 = l2 -> next;
            }
        }
        return nhead;
    }
};
// @lc code=end

