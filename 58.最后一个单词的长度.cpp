/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int headOfWord, endOfWord;
        endOfWord = s.length()-1;
        while(s[endOfWord]==' '){
            endOfWord--;
        }
        headOfWord=endOfWord;
        while(headOfWord>=0 && s[headOfWord]!=' '){
            headOfWord--;
        }
        return endOfWord-headOfWord;
    }
};
// @lc code=end

