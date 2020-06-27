/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    struct Node{
        Node* next;
        int left;
        int right;

        Node(int l,int r){left = l; right = r;}
        Node(){left=0;right=0;}
    };
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if(len==0)return 1;
        int i=0,num = 0;
        Node* head = new Node();
        Node* tmp = nullptr;
        Node* tmp2 = nullptr;
        while(num<1 && i<len){
            num = nums[i++];
            if(num<1){
                continue;
            }else if(num==1){
                head->left = 2;
                head->right = 2147483647;
            }else if(num == 2147483647){
                head->left = 1;
                head->right = 2147483647;
            }else
            {
                head->left = 1;
                head->right = num;
                head->next = new Node(num+1,2147483647);
            }
        }
        if(i==len && num<1)return 1;
        for (;i<len;i++){
            num = nums[i];
            if(num<1){
                continue;
            }else {
                tmp = head;
                while(tmp->left<num){
                    if(tmp->next == nullptr || tmp->right >= num){
                        break;
                    }
                    tmp = tmp->next;
                }
                if(tmp->left>num){
                    continue;
                }
                if(tmp->left==num){
                    if(tmp->right==num+1){
                        tmp2 = tmp->next;
                        tmp->left = tmp2->left;
                        tmp->right = tmp2->right;
                        tmp->next = tmp2->next;
                        delete tmp2;
                    }else{
                        tmp->left +=1;
                    }
                    continue;
                }else if(tmp->right==num){
                    continue;
                }else if(tmp->right==num+1){
                    tmp->right -=1;
                    continue;
                }
                tmp2 = tmp->next;
                tmp->next = new Node(num+1,tmp->right);
                tmp->right = num;
                tmp->next->next = tmp2;
            }
        }
        return head->left;
    }
};

// @lc code=end

