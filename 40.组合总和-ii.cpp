/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        int len = candidates.size();
        if(candidates[0] <= target){
            result = getCombinationSum2(candidates, 0, len, target);
        }
        return result;
    }

    vector<vector<int>> getCombinationSum2(vector<int>& candidates, int index, int len, int target) {
        vector<vector<int>> result, tmp;
        int tmp_len=0;
        int j=0;
        if(candidates[index]==target){
            vector<int> answer;
            answer.push_back(candidates[index]);
            result.push_back(answer);
        }
        if(index < (len-1) && candidates[index] < target){
            tmp = getCombinationSum2(candidates, index+1, len, target - candidates[index]);
            tmp_len = tmp.size();
            for(j=0;j<tmp_len;j++){
                tmp[j].push_back(candidates[index]);
                result.push_back(tmp[j]);
            }
            while(index<(len-1) && candidates[index]==candidates[index+1]){
                index++;
            }
            if(index<(len-1)){
                tmp = getCombinationSum2(candidates, index+1, len, target);
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

