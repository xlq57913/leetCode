#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        r = []
        l = len(nums)
        i=0
        while i<l-2:
            if(nums[i]>1):
                break
            if(i>0 and nums[i]==nums[i-1]):
                i = i + 1
                continue
            j = i+1
            lastNum = l-1
            lastFound = False
            while j<l-1:
                if(nums[i]+2*nums[j]>0):
                    break
                if(j>i+1 and nums[j]==nums[j-1]) or nums[i]+nums[j]<-nums[l-1]:
                    j = j + 1
                    continue
                if(not lastFound):
                    k = j+1;
                    found = False
                    while k<l:
                        if(nums[i]+nums[j]+nums[k]==0):
                            tmp = [nums[i],nums[j],nums[k]];
                            r.append(tmp)
                            lastFound = True
                            lastNum = k
                            break
                        elif(nums[i]+nums[j]+nums[k]>0):
                            lastFound = True
                            lastNum = k
                            break
                        k = k + 1
                else:
                    k = lastNum
                    while k > j:
                        if(nums[i]+nums[j]+nums[k]==0):
                            tmp = [nums[i],nums[j],nums[k]];
                            r.append(tmp)
                            lastNum = k
                            break
                        elif(nums[i]+nums[j]+nums[k]<0):
                            lastNum = min(k+1,l-1)
                            break
                        k = k - 1
                j = j + 1
            i = i + 1
        return r
# @lc code=end

