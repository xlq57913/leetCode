/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:

    int strToInt(string num){
        int len = num.length();
        int result=0, index=0;
        char tmp;
        while(index<len && num[index] == '0')index++;
        while(index<len){
            result = result*10 + num[index++]-48;
        }
        return result;
    }

    string intTable(int num){
        string str;
        if(num==0)str="0";
        else if(num==1)str="1";
        else if(num==2)str="2";
        else if(num==3)str="3";
        else if(num==4)str="4";
        else if(num==5)str="5";
        else if(num==6)str="6";
        else if(num==7)str="7";
        else if(num==8)str="8";
        else if(num==9)str="9";
        return str;
    }

    string intToStr(int num){
        string result = "";
        if(num==0)result="0"
        while(num != 0){
            result = intTable(num%10) + result;
            num = num/10;
        }
        return result;
    }

    string multiply(string num1, string num2) {
        return intToStr(strToInt(num1)*strToInt(num2));
    }
};
// @lc code=end

