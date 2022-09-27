/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len<=1)return 0;
        if(nums[0]>=len-1)return 1;
        int i,j,k;
        bool **matrix = new bool*[len];
        for(i=0; i<len; i++){
            matrix[i] = new bool[len];
            for(j=0; j<len;j++){
                matrix[i][j]=false;
            }
        }
        for(i=0;i<=nums[0];i++){
            matrix[0][i]=true;
        }
        for(j=1;j<len;j++){
            k=0;
            while(matrix[j-1][k]){
                for(i=0;i<=nums[k];i++){
                    if(k+i>=len)break;
                    matrix[j][k+i]=true;
                }
                k++;
            }
            if(matrix[j][len-1])break;
        }
        for(i=0; i<len; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
        return j+1;

    }
};
// @lc code=end

