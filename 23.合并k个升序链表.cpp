/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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

    struct NodeList{
        ListNode* head;
        int length;
        NodeList(ListNode* node, int x): head(node), length(x){}
        bool operator<(const NodeList& other){
            return length < other.length;
        }
        bool operator<=(const NodeList& other){
            return length <= other.length;
        }
    };

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }else if(lists.size()==1){
            return lists[0];
        }
        vector<NodeList> nodeList = vector<NodeList>();
        NodeList result = NodeList(nullptr,0);
        for (int i=0; i<lists.size(); i++){
            nodeList.push_back(NodeList(lists[i], getLength(lists[i])));
        }
        std::sort(nodeList.begin(), nodeList.end());
        while (nodeList.size() > 1){
            result = mergeTwoLists(nodeList[0], nodeList[1]);
            nodeList.insert(nodeList.begin()+2, result);
            nodeList.erase(nodeList.begin(),nodeList.begin()+2);
        }
        return result.head;
    }

    NodeList mergeTwoLists(NodeList& list1, NodeList& list2){
        if (list1.length == 0)return list2;
        if (list2.length == 0)return list1;
        ListNode* head = nullptr;
        ListNode* tmp = nullptr;
        ListNode* tmp1 = list1.head;
        ListNode* tmp2 = list2.head;
        if(tmp1->val > tmp2->val){
            head = tmp2;
            tmp2 = tmp2->next;
        }else{
            head = tmp1;
            tmp1 = tmp1->next;
        }
        tmp = head;
        while(tmp1 != nullptr && tmp2 != nullptr) {
            if(tmp1->val > tmp2->val){
                tmp->next= tmp2;
                tmp = tmp2;
                tmp2 = tmp2->next;
            }else{
                tmp->next = tmp1;
                tmp = tmp1;
                tmp1 = tmp1->next;
            }
        }
        if(tmp1 == nullptr){
            tmp->next = tmp2;
        }else{
            tmp->next = tmp1;
        }
        return NodeList(head, list1.length + list2.length);
    }

};
// @lc code=end

