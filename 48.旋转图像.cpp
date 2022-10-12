/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(),m,tmp;
        if(n==1)return;
        int isOdd = (n%2==0)?0:1;
        m = n/2 + isOdd;
        for(int i=0; i<m; i++){
            for (int j=0; j<m; j++){
                if(isOdd==1 && i==m-1)continue;
                tmp = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = tmp;
                tmp = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[i][j];
                matrix[i][j] = tmp;
                tmp = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }
        return;
    }
};
// @lc code=end

