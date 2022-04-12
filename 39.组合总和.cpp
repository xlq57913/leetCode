/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start

#include<algorithm>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        int len = candidates.size();
        if(candidates[0] <= target){
            result = getCombinationSum(candidates, 0, len, target);
        }
        return result;
    }

    vector<vector<int>> getCombinationSum(vector<int>& candidates, int index, int len, int target) {
        vector<vector<int>> result, tmp;
        int tmp_len=0;
        int j=0;
        if(candidates[index]==target){
            vector<int> answer;
            answer.push_back(candidates[index]);
            result.push_back(answer);
        }
        if(candidates[index] < target){
            tmp = getCombinationSum(candidates, index, len, target - candidates[index]);
            tmp_len = tmp.size();
            for(j=0;j<tmp_len;j++){
                tmp[j].push_back(candidates[index]);
                result.push_back(tmp[j]);
            }
            if(index<(len-1)){
                tmp = getCombinationSum(candidates, index+1, len, target);
                tmp_len = tmp.size();
                for(j=0;j<tmp_len;j++){
                    result.push_back(tmp[j]);
                }
            }
        }
        return result;
    }
};
// @lc code=end

