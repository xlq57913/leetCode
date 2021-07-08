/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

    int getLength(ListNode* head){
        if(head == nullptr) return 0;
        int length = 1;
        ListNode* tail = head->next;
        while(tail != nullptr){
            tail = tail->next;
            length++;
        }
        return length;
    }

    ListNode* reverseKGroupOnce(ListNode* head, int k){
        if(k<2) return head;
        if(k==2){
            ListNode* left = head;
            head = left->next;
            left->next = head->next;
            head->next = left;
            return head;
        }else if(k==3){
            ListNode* left = head;
            ListNode* middle = head->next;
            head = middle->next;
            left->next = head->next;
            head->next = middle;
            middle->next = left;
            return head;
        }
        ListNode* left = head;
        ListNode* left_next = head->next;
        ListNode* prev_right = left_next->next;
        for (int i=0; i<k-4;i++)prev_right = prev_right->next;
        head = prev_right->next;
        left->next = head->next;
        prev_right->next = left;
        head->next = reverseKGroupOnce(left_next, k-2);
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k<2){
            return head;
        }

        int group_length = getLength(head);

        if(group_length < k){
            return head;
        }

        int epochs = group_length / k;

        ListNode* left = head;
        ListNode* right = nullptr;

        head = reverseKGroupOnce(left, k);
        right = left;
        left = left->next;

        for(int i=1; i<epochs; i++){
            right->next = reverseKGroupOnce(left, k);
            right = left;
            left = left->next;
        }
        return head;
    }
};
// @lc code=end

