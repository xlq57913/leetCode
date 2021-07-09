/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")return 0;
        if(haystack == "") return -1;
        int len_haystack = haystack.length(), len_needle = needle.length(), i=0, j=0;
        for (i = 0; i<len_haystack-len_needle+1; i++) {
            j = 0;
            while(j<len_needle){
                if(haystack[i+j]==needle[j]){
                    if(j == len_needle-1){
                        return i;
                    }
                    j++;
                }else{
                    break;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

