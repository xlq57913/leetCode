/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include<math.h>

class Solution {
public:
    int reverse(int x) {
        long long signx,nx,i,tmpx,lenx=0;
        int bitx[11];
        if(x<0){
            if(x<-pow(10,9)&&(x%10<-2))return 0;
            signx=-1;
            nx=-x;
        }else{
            if(x>pow(10,9)&&(x%10>2))return 0;
            signx=1;
            nx=x;
        }
        tmpx = nx;
        while(tmpx>=1){
            bitx[lenx]=tmpx%10;
            tmpx/=10;
            lenx+=1;
        }
        for(int i=lenx-1;i>=0;i--){
            nx -= bitx[i]*pow(10,i);
            nx += bitx[i]*pow(10,lenx-i-1);
        }
        if(nx>pow(2,31))return 0;
        return signx*nx;
    }
};

