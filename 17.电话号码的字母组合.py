#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        d = {"2":["a","b","c"],"3":["d","e","f"],"4":["g","h","i"],"5":["j","k","l"]
            ,"6":["m","n","o"],"7":["p","q","r","s"],"8":["t","u","v"],"9":["w","x","y","z"]}
        r = []
        for s in digits:
            nr = []
            if(len(r)==0):
                r = d[s]
            else:
                for i in d[s]:
                    for j in r:
                        nr.append(j+i)
                r = nr
            
        return r
# @lc code=end

