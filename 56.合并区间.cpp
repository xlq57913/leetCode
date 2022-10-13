/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <algorithm>
bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<int> record = vector<int>(intervals[intervals.size()-1][1]+1);
        for(int i=0; i<record.size();i++)record[i]=0;
        for(int i=0; i<intervals.size(); i++){
            for(int j=intervals[i][0]; j <= intervals[i][1]; j++){
                if(j<intervals[i][1])record[j]+=2;
                else {
                    if(record[j]!=1)record[j]+=1;
                }
            }
        }
        vector<vector<int>> ans = vector<vector<int>>();
        int left=0, right=0;
        bool onRecord = false;
        for(int i=0; i<record.size();i++){
            if(record[i]>0){
                if(record[i]>=2){
                    if(!onRecord){
                        onRecord = true;
                        left = i;
                    }
                }else{
                    if(onRecord){
                        onRecord = false;
                        right = i;
                        vector<int> tmp = vector<int>(2);
                        tmp[0]=left;
                        tmp[1]=right;
                        ans.push_back(tmp);
                    }else{
                        vector<int> tmp = vector<int>(2);
                        tmp[0]=i;
                        tmp[1]=i;
                        ans.push_back(tmp);
                    }
                }
            }else{
                if(onRecord){
                    onRecord = false;
                    right = i-1;
                    vector<int> tmp = vector<int>(2);
                    tmp[0]=left;
                    tmp[1]=right;
                    ans.push_back(tmp);
                }
            }
        }
        if(onRecord){
            right = record.size()-1;
            vector<int> tmp = vector<int>(2);
            tmp[0]=left;
            tmp[1]=right;
            ans.push_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

