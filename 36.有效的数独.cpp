/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool num_recorder_row[9];
        bool num_recorder_col[9];
        bool num_recorder_rect[9];
        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                num_recorder_row[j] = false;
                num_recorder_col[j] = false;
                num_recorder_rect[j] = false;
            }
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(num_recorder_row[board[i][j] - 49])return false;
                    num_recorder_row[board[i][j] - 49] = true;
                }
                if(board[j][i] != '.'){
                    if(num_recorder_col[board[j][i] - 49]) return false;
                    num_recorder_col[board[j][i] - 49] = true;
                }
                if(board[3*(i/3) + j/3][3*(i%3) + j%3] != '.'){
                    if(num_recorder_rect[board[3*(i/3) + j/3][3*(i%3) + j%3] - 49]) return false;
                    num_recorder_rect[board[3*(i/3) + j/3][3*(i%3) + j%3] - 49] = true;
                }
            }
        }
        return true;
    }
};
// @lc code=end

