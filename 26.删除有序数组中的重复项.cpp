/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length >= 2){
            int real_index = 0;
            int index = 1;
            while(real_index < length-1){
                if(nums[real_index] != nums[real_index+1]){
                    nums[index] = nums[real_index+1];
                    index++;
                }
                real_index++;
            }
            return index;
        }else{
            return length;
        }
    }
};
// @lc code=end

