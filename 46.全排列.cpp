/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        if(len==1){
            result = vector<vector<int>>();
            result.push_back(nums);
        }else{
            int num = nums[len-1];
            nums.pop_back();
            result = permute(nums);
            int len_result = result.size();
            vector<int> tmp;
            vector<int>::iterator it;
            for(int i=0; i<len_result; i++){
                for(int j=0; j<result[i].size();j++){
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
};
// @lc code=end

