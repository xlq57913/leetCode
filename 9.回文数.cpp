/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x<10)return true;
        string str = "";
        int tmp = x,size=0;
        while(tmp>0){
            str += (tmp%10+48);
            tmp/=10;
            size+=1;
        }
        for(int i=0;i<=size/2;i++){
            if(str[i]!=str[size-i-1])return false;
        }
        return true;
    }
};

