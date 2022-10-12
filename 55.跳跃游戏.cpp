/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJumpTo(vector<int>& nums,vector<bool>&vis, int target){
        vis[target] = true;
        if(target==0)return true;
        int jumpForm = target -1;
        while(jumpForm >=0){
            if(!vis[jumpForm]&&nums[jumpForm]>= target - jumpForm){
                if(canJumpTo(nums,vis, jumpForm))return true;
            }
            jumpForm--;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<bool> vis = vector<bool>();
        for(int i=0; i<nums.size();i++)vis.push_back(false);
        return canJumpTo(nums,vis, nums.size()-1);
    }
};
// @lc code=end

