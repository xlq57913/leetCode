#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lens = len(s)
        if(not lens):
            return 0
        if(lens==1):
            return 1
        maxLen = 0
        tmpLen = 0
        start = 0
        tmpstr = ''
        i=0
        while(i < lens):
            index = tmpstr.find(s[i])
            if(index==-1):
                tmpLen+=1
                tmpstr+=s[i]
                i+=1
            else:
                start = start + index + 1
                if(tmpLen>maxLen):
                    maxLen=tmpLen
                i = start
                tmpLen = 0
                tmpstr = ''
        if(tmpLen>maxLen):
            maxLen=tmpLen
        return maxLen

