/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len_nums = nums.size();
        if(len_nums == 1){
            return nums[0]==target? 0:-1;
        }
        int left = 0, right = len_nums-1, middle = (left+right)/2;
        if(len_nums > 2 && nums[left] > nums[right]){
            while(left < right-1){
                if(nums[middle] > nums[left]){
                    left = middle;
                }
                if(nums[middle] < nums[right]){
                    right = middle;
                }
                middle = (left+right)/2;
            }
            if(target >= nums[0]){
                right = left;
                left = 0;
            }
            else if(target <= nums[len_nums-1]){
                left = right;
                right = len_nums-1;
            }else{
                return -1;
            }
        }
        middle = (left+right)/2;
        while(left < right-1){
            if(nums[middle] > target){
                right = middle;
            }else if(nums[middle] < target){
                left = middle;
            }else{
                return middle;
            }
            middle = (left+right)/2;
        }
        if(nums[left] == target)return left;
        if(nums[right] == target)return right;
        return -1;
    }
};
// @lc code=end

