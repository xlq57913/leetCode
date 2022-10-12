/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<int> ans = vector<int>();
        int len = (m<n)?m:n;
        for(int i=0; i<=(len-1)/2; i++){
                int x=i,y=i;
                bool goright = false, godown = false;
                ans.push_back(matrix[x][y]);
                while(y<n-i-1){
                    goright = true;
                    y++;
                    ans.push_back(matrix[x][y]);
                }
                while(x<m-i-1){
                    godown = true;
                    x++;
                    ans.push_back(matrix[x][y]);
                }
                while(goright && godown && y>i){
                    y--;
                    ans.push_back(matrix[x][y]);
                }
                while(godown && goright && x>i+1){
                    x--;
                    ans.push_back(matrix[x][y]);
                }
        }
        return ans;
    }
};
// @lc code=end

