/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        int lens = s.size();
        if(lens<=numRows)return s;
        int period = 2*numRows-2;
        int turn = lens/(period);
        int left = lens%(period);
        string rs="";
        int i,j;
        for(i=0;i<numRows;i++){
            if(i==0){
                for(j=0;j<turn;j++){
                    rs+=s[j*period];
                }
                if(left>0) rs+=s[turn*period];
            }else if(i==(numRows-1)){
                for(j=0;j<turn;j++){
                    rs+=s[j*period+i];
                }
                if(left>=numRows) rs+=s[turn*period+numRows-1];
            }else{
                for(j=0;j<turn;j++){
                    rs+=s[j*period+i];
                    rs+=s[(j+1)*period-i];
                }
                if(left>i) rs+=s[(turn)*period+i];
                if(left>=period-i+1) rs+=s[(turn+1)*period-i];
            }
        }
    return rs;
    }
};

