/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        int i,j,l,ls,num;
        string tmp;
        if(n==1){
            s.push_back("()");
            return s;
        }else if(n==2){
            s.push_back("(())");
            s.push_back("()()");
            return s;
        }

        s.push_back("(1");
        for(i=2;i<2*n;i++){
            l = s.size();
            for(j=0;j<l;j++){
                ls = s[j].length();
                num = int(s[j][ls-1]-'0');
                if(num==0){
                    s[j].replace(ls-1,1,"(");
                    s[j].append("1");
                }else{
                    tmp = s[j];
                    s[j].replace(ls-1,1,")");
                    s[j].append(to_string(num-1));
                    if(num+(ls-1-num)/2<n){
                        tmp.replace(ls-1,1,"(");
                        tmp.append(to_string(num+1));
                        s.push_back(tmp);
                    }
                }
            }
        }
        l = s.size();
        for (j=0;j<l;j++){
            s[j].replace(2*n-1,1,")");
        }
        return s;
    }

};
// @lc code=end

