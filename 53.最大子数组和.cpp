/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-1e4, sum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                if(sum < 0)sum=0;
                sum = sum + nums[i];
            }else{
                if(sum<nums[i])sum=nums[i];
                else sum+=nums[i];
            }
            if(sum > ans)ans = sum;
        }
        return ans;
    }
};
// @lc code=end

