/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size()==1){
            return nums[0]>=target?0:1;
        }
        if(nums[0]>=target)return 0;
        if(nums[nums.size()-1]<=target)return nums[nums.size()-1]<target? nums.size():nums.size()-1;
        int left=0, right=nums.size()-1, middle;
        while(left<right-1){
            middle = (left+right)/2;
            if(nums[middle]==target)return middle;
            else if(nums[middle]<target) left = middle;
            else right = middle-1;
        }
        return nums[right]<target? right+1 : right;
    }
};
// @lc code=end

