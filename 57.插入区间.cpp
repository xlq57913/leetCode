/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include<cmath>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans = vector<vector<int>> ();
        bool isInserted = false;
        int left = newInterval[0], right = newInterval[1];
        for(int i=0; i<intervals.size(); i++){
            if(isInserted || intervals[i][1]<left){
                ans.push_back(intervals[i]);
            }else{
                if(intervals[i][0]>right){
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    isInserted = true;
                }else{
                    left = (left > intervals[i][0])?intervals[i][0]:left;
                    right = (intervals[i][1]>right)?intervals[i][1]:right;
                    while(i<intervals.size()-1){
                        if(intervals[i+1][0]<=right){
                            right = (intervals[i+1][1]>right)?intervals[i+1][1]:right;
                            i++;
                        }else break;
                    }
                    vector<int> tmp = vector<int>(2);
                    tmp[0]=left;
                    tmp[1]=right;
                    ans.push_back(tmp);
                    isInserted = true;
                }
            }
        }
        if(!isInserted){
            ans.push_back(newInterval);
        }
        return ans;
    }
};
// @lc code=end

