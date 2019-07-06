#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#
class Solution:

    def isPalindrome(self,s:str,start:int,end:int):
        if(start==end):
            return True
        else:
            for i in range((end-start+1)//2):
                if(s[start+i]!=s[end-i]):
                    return False
            return True
    
    def longestPalindrome(self, s: str) -> str:
        maxlen = 0
        maxstr = ''
        lens = len(s)
        for i in range(lens):
            for j in range(lens-1,-1,-1):
                if(maxlen>=(lens-i)):
                    break
                if(i>j):
                    continue
                if((j-i+1)<=maxlen):
                    continue
                if(self.isPalindrome(s,i,j)):
                    if((j-i+1)>maxlen):
                        maxlen = j-i+1
                        maxstr = s[i:j+1]
        return maxstr


