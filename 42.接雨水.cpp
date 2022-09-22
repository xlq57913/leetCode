/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0, right=0, index=0;
        int left_height=0, right_height=0;
        int block=0, tmp=0, sum=0;
        if(n==1) return 0;
        left_height = height[left];
        while(left<n-1 && left_height <= height[left+1]){
            left++;
            left_height = height[left];
        }
        if(left==n-1)return 0;
        right = left+1;
        right_height = height[right];
        index = right;
        tmp = right_height;
        while(index<n && left<n-1){
            index++;
            if(index == n){
                sum += (right-left-1)*right_height - block;
                if(right == n-1) break;
                left = right;
                left_height = right_height;
                right++;
                right_height = height[right];
                index = right;
                block=0;
                tmp = right_height;
            }else if(height[index]>=left_height){
                sum += (index-left-1)*left_height - tmp;
                if(index == n-1) break;
                left = index;
                left_height = height[index];
                while(left<n-1 && left_height <= height[left+1]){
                    left++;
                    left_height = height[left];
                }
                if(left == n-1)break;
                right = left+1;
                right_height = height[right];
                index = right;
                block=0;
                tmp = right_height;
            }else if(height[index]>=right_height){
                right = index;
                right_height = height[index];
                block = tmp;
                tmp += right_height;
            }else{
                tmp += height[index];
            }
        }
        return sum;
    }
};
// @lc code=end

