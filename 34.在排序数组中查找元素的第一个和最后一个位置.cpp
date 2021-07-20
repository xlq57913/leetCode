/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = vector<int>();
        result.push_back(-1);
        result.push_back(-1);
        if(!nums.size()){
            return result;
        }
        if(nums.size()==1){
            if(nums[0] == target){
                result[0] = 0;
                result[1] = 0;
            }
            return result;
        }
        int left = 0, right = nums.size()-1, middle;
        while(left<right-1){
            middle = (left+right)/2;
            if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] >= target){
                right = middle;
            }
        }
        if(nums[left] == target) result[0] = left;
        else if(nums[right] == target) result[0] = right;
        else return result;

        right = nums.size()-1;
        while(left<right-1){
            middle = (left+right)/2;
            if(nums[middle] <= target){
                left = middle;
            }else if(nums[middle] > target){
                right = middle - 1;
            }
        }
        if(nums[right] == target) result[1] = right;
        else if(nums[left] == target) result[1] = left;
        return result;
    }
};
// @lc code=end

