/*
 *@lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution { //TODO: could be better
public:
    bool checkMatch(string s, string p,int lens,int lenp,int indexs,int indexp) {
        char tmp = p[indexp];
        if(indexp==lenp){
            if(indexs!=lens)return false;
        }
        else if(indexs == lens){
            if(indexp==lenp-1)return false;
            else if(p[indexp+1]==42)return checkMatch(s,p,lens,lenp,indexs,indexp+2);
            else return false;
        }
        else{
            if(indexp==lenp-1){
                if(s[indexs]==tmp||tmp==46)return checkMatch(s,p,lens,lenp,indexs+1,indexp+1);
                else return false;
            }
            else {
                if(p[indexp+1]==42){
                    if(tmp!=46&&s[indexs]!=tmp)return checkMatch(s,p,lens,lenp,indexs,indexp+2);
                    else if(tmp!=46){
                        while(indexs<lens){
                            if(s[indexs]==tmp){
                                if(checkMatch(s,p,lens,lenp,indexs,indexp+2))return true;
                                indexs+=1;
                            }else break;
                        }return checkMatch(s,p,lens,lenp,indexs,indexp+2);
                    }else{
                        while(indexp<lenp-3&&p[indexp+3]==42)indexp+=2;
                        while(indexs<lens){
                            if(checkMatch(s,p,lens,lenp,indexs,indexp+2))return true;
                            indexs+=1;
                        }
                        return checkMatch(s,p,lens,lenp,indexs,indexp+2);
                    }
                }else{
                    if(s[indexs]!=tmp&&tmp!=46)return false;
                    return checkMatch(s,p,lens,lenp,indexs+1,indexp+1);
                }
            }
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int lens = s.size(),lenp = p.size();
        return checkMatch(s,p,lens,lenp,0,0);
    } 
};

