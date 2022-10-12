/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <cmath>
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        bool is_negative = n<0;
        while(n!=0){
            if(n%2!=0){
                ans = ans * x;
            }
            x=x*x;
            n/=2;
        }
        if(is_negative) ans = 1/ans;
        return ans;
    }
};
// @lc code=end
