/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> result;
        if(len==1){
            result = vector<vector<int>>();
            result.push_back(nums);
        }else{
            int num = nums[len-1];
            nums.pop_back();
            result = permuteUnique(nums);
            int len_result = result.size();
            bool FLAG = false;
            vector<int> tmp;
            vector<int>::iterator it;
            for(int j=0; j<result[0].size();j++){
                if(result[0][j]==num)
                {
                    FLAG = true;
                    break;
                }
            }
            for(int i=0; i<len_result; i++){
                for(int j=0; j<result[i].size();j++){
                    if(FLAG){
                        if(result[i][j]!=num||j==result[i].size()-1 || result[i][j+1]==num)continue;
                    }
                    tmp = vector(result[i]);
                    it = tmp.begin();
                    tmp.insert(it+j,num);
                    result.push_back(tmp);
                }
                result[i].push_back(num);
            }
        }
        return result;
    }
    void backtrace(vector<int> &nums, vector<vector<int>> &ans, int index, vector<int>perm, vector<bool>vis){
        
    }
};
// @lc code=end

