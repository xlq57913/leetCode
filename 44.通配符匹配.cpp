/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s=s.length(), len_p=p.length();
        int index = 0;
        while(len_p!=0&&len_s!=0&&p[len_p-1]!='*'){
            if(p[len_p-1]!=s[len_s-1]&&p[len_p-1]!='?')return false;
            else{
                len_p--;
                p.erase(len_p);
                len_s--;
                s.erase(len_s);
            }
        }
        while(index<len_p-1){
            if(p[index]=='*'&&p[index+1]=='*'){
                p.erase(index+1,1);
                len_p--;
            }else{index++;}
        }
        if(len_p==0)
        {
            if(len_s==0)return true;
            else return false;
        }
        if(len_s==0){
            if(p[0]=='*'&&len_p==1)return true;
            else return false;
        }
        return isMatch_sub(s,p,len_s,len_p,0,0);
    }

    bool isMatch_sub(string &s, string &p, int len_s, int len_p, int index_s, int index_p){
        while(len_p>index_p&&len_s>index_s&&p[index_p]!='*'){
            if(p[index_p]==s[index_s] || p[index_p]=='?'){
                index_p++;
                index_s++;
            }else{
                return false;
            }
        }
        if(len_p==index_p)
        {
            if(len_s==index_s)return true;
            else return false;
        }
        else if(len_s==index_s){
            if(p[index_p]!='*')return false;
            else return isMatch_sub(s,p,len_s,len_p,index_s,index_p+1);
        }
        else if(p[index_p]=='*'){
            if(len_p-index_p==1)return true;
            while(index_s < len_s){
                if((s[index_s]==p[index_p+1]||p[index_p+1]=='?') && isMatch_sub(s,p,len_s,len_p,index_s,index_p+1)){
                    return true;
                }else{
                    index_s++;
                }
            }
            return false;
        }else{
            return false;
        }
    }
};
// @lc code=end

