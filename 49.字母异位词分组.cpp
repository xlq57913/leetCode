/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    string sortStr(string str){
        int len = str.length(),i,j;
        if(len <= 1)return str;
        else if(len==2){
            if(str[0]>str[1]){
                char tmp = str[0];
                str[0] = str[1];
                str[1] = tmp;
            }
            return str;
        }
        else{
            string str1, str2;
            str1 = sortStr(str.substr(0,len/2));
            str2 = sortStr(str.substr(len/2,len-len/2));
            if(str2[0]>=str1[str1.length()-1]){
                str1 = str1 + str2;
                return str1;
            }
            for(i=0;i<str1.length();i++){
                if(str1[i]>=str2[str2.length()-1]){
                    str2 = str2 + str1.substr(i,str1.length()-i);
                    return str2;
                }
                for(j=0;j<str2.length();j++){
                    if(str1[i]<=str2[j]){
                        str2.insert(j,str1.substr(i,1));
                        break;
                    }
                }
            }
            return str2;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> ans = vector<vector<string>>();
        vector<string> sorted = vector<string>();
        if(len==1){
            ans.push_back(strs);
            return ans;
        }
        vector<string> tmp = vector<string>();
        string tmpStr;
        tmp.push_back(strs[0]);
        ans.push_back(tmp);
        sorted.push_back(sortStr(tmp[0]));
        for(int i=1; i<len; i++){
            tmpStr = sortStr(strs[i]);
            for (int j=0; j < ans.size(); j++){
                if(tmpStr.length()==sorted[j].length()){
                    if(strs[i].length()<=1||tmpStr == sorted[j]){
                        ans[j].push_back(strs[i]);
                        break;
                    }
                }
                if(j==ans.size()-1){
                    tmp = vector<string>();
                    tmp.push_back(strs[i]);
                    ans.push_back(tmp);
                    sorted.push_back(tmpStr);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

