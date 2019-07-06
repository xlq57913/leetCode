/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int itmp1 = 0, itmp2 = 0;
        itmp1 = (l1->val + l2->val)%10;
        itmp2 = (l1->val + l2->val)/10;
        ListNode* tmp ,*root = new ListNode(itmp1);
        tmp = root;
        l1 = l1->next;
        l2 = l2->next;
        while(l1!=NULL || l2!=NULL)
        {
            if(l1==NULL){
                itmp1 = (itmp2 + l2->val)%10;
                itmp2 = (itmp2 + l2->val)/10;
                tmp->next = new ListNode(itmp1);
                tmp = tmp->next;
                l2 = l2->next;
            }
            else if(l2== NULL){
                itmp1 = (itmp2 + l1->val)%10;
                itmp2 = (itmp2 + l1->val)/10;
                tmp->next = new ListNode(itmp1);
                tmp = tmp->next;
                l1 = l1->next;
            }
            else {
                itmp1 = (itmp2 + l1->val + l2->val)%10;
                itmp2 = (itmp2 + l1->val + l2->val)/10;
                tmp->next = new ListNode(itmp1);
                tmp = tmp->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        while(itmp2>0){
            itmp1 = itmp2%10;
            itmp2 = itmp2/10;
            tmp->next = new ListNode(itmp1);
            tmp = tmp->next;
        }
        return root;
    }
};

