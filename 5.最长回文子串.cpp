/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int lens = s.size();
        int tmp1,tmp2,i;
        bool isPalindrome = true;

        for(tmp1=lens;tmp1>0;tmp1--){
            for(tmp2=0;tmp2<lens;tmp2++){
                if(tmp2+tmp1>lens)break;
                if(tmp1!=1){
                    for(i=0;i<tmp1/2;i++){
                        if(s[tmp2+i]!=s[tmp2+tmp1-1-i]){
                            isPalindrome = false;
                            break;
                        }
                    }
                }
                if(isPalindrome)
                    return s.substr(tmp2,tmp1);
                else isPalindrome=true;
            }
        }
        return s;
    }
};

