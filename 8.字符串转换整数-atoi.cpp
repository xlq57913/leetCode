/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include<math.h>

class Solution {
public:
    int myAtoi(string str) {
        const int lens = str.size();
        const int max = pow(2,31)-1;
        const int min = -pow(2,31);
        long long result = 0;
        int sign = 1;
        bool findNum = false;
        for(int i=0;i<lens;i++){
            if(str[i]<48 || str[i]>57 ){
                if(findNum)break;
                if(str[i]==45){
                    sign=-1;
                    findNum = true;
                }else if(str[i]==43){
                    findNum = true;
                }else if(str[i]!=32){
                    return 0;
                }
            }
            else{
                if(!findNum)findNum = true;
                result=result*10+str[i]-48;
                if(result>=max)break;
            }
        }
        if(sign>0){
            if(result>=max)return max;
        }else{
            if(result>max)return min;
        }
        return sign*result;
    }
};

