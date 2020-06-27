/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int l = s.length();
        int* records = new int[l];
        int index = 0;
        for (int i=0;i<l;i++)
        {
            switch (s[i])
            {
            case '(':
                records[index++] = i;
                break;
            case '[':
                records[index++] = i;
                break;
            case '{':
                records[index++] = i;
                break;
            default:
                if(index==0)return false;
                if(!isPair(s[records[--index]],s[i]))
                    return false;
                break;
            }
        }
        delete[] records;
        if(index!=0)return false;
        return true;
    }

    bool isPair(char s1, char s2){
        switch (s1)
        {
        case '(':
            if(s2==')')return true;
            break;
        case '[':
            if(s2==']')return true;
            break;
        case '{':
            if(s2=='}')return true;
            break;
        default:
            return false;
            break;
        }
        return false;
    }
};
// @lc code=end

