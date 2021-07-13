/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <bitset>

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negativ = false;
        if(dividend<0 && divisor>0 || dividend>0 && divisor<0){
            negativ = true;
        }
        if(dividend == 0){
            return 0;
        }
        unsigned udividend = dividend < 0? -(dividend+1):(dividend-1);
        udividend++;
        unsigned udivisor = divisor < 0? -(divisor+1):(divisor-1);
        udivisor++;
        
        if(udividend<udivisor){
            return 0;
        }
        if(udividend == udivisor){
            return negativ? -1:1;
        }
        bitset<32> bit_dividend = bitset<32>(udividend);
        bitset<32> bit_divisor = bitset<32>(udivisor);
        int len_dividend=1, len_divisor=1, len_root;

        for (int i = 31; i >0 ; i--){
            if(bit_dividend[i]==1){
                len_dividend = i + 1;
                break;
            }
        }

        for (int i = 31; i >0 ; i--){
            if(bit_divisor[i]==1){
                len_divisor = i + 1;
                break;
            }
        }
        len_root = len_dividend - len_divisor + 1;
        bitset<32> bit_root = bitset<32>(0);

        for (int i = len_root-1; i>=0; i--){
            for(int j=len_dividend - i - 1 ; j>=0; j--){
                if(bit_dividend[j+i] > bit_divisor[j] || (bit_dividend[j+i] == bit_divisor[j] && j==0)){
                    bit_root[i]=1;
                    for(int k=0; k<len_divisor; k++){
                        if(bit_dividend[k+i]>=bit_divisor[k]){
                            bit_dividend[k+i] = bit_dividend[k+i] - bit_divisor[k];
                        }else{
                            bit_dividend[k+i] = 2 - bit_divisor[k];
                            int n=1;
                            while (bit_dividend[k+i+n] == 0)
                            {
                                bit_dividend[k+i+n] = 1;
                                n++;
                            }
                            bit_dividend[k+i+n] = bit_dividend[k+i+n] - 1;
                        }
                    }
                    break;
                }else if(bit_dividend[j+i] < bit_divisor[j]){
                    bit_root[i]=0;
                    break;
                }
            }
        }
        if(bit_root[31] == 1){
            if(!negativ){
                bit_root.set();
                bit_root[31] = 0;
            }
        }
        return negativ? (-(int)(bit_root.to_ulong()-1))-1: (int)(bit_root.to_ulong());
    }
};
// @lc code=end

