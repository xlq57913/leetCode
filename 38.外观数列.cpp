/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        string tmp = "";
        int length = 0;
        int count = 0;
        for(int step=1; step<n; step++){
            length = str.size();
            for(int i=0; i<length; i++){
                count = 1;
                while(i<length && str[i]==str[i+1]){
                    count++;
                    i++;
                }
                tmp += std::to_string(count);
                tmp += str[i];
            }
            str = tmp;
            tmp = "";
        }
        return str;
    }
};
// @lc code=end

