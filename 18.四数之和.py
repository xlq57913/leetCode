#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#

# @lc code=start
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        result = []
        l = 0
        r = n-1
        while (r-l>=3):
            ml = l+1
            mr = r-1
            while (mr>ml):
                tmp = nums[l]+nums[ml]+nums[mr]+nums[r]
                if(tmp>target):
                    while(mr>ml and nums[mr-1]==nums[mr]):
                        mr-=1
                    mr -= 1
                elif(tmp<target):
                    while (ml<mr and nums[ml]==nums[ml+1]):
                        ml+=1
                    ml += 1
                else:
                    #if([nums[l],nums[ml],nums[mr],nums[r]] not in result):
                    result.append([nums[l],nums[ml],nums[mr],nums[r]])
                    while (ml<mr and nums[ml]==nums[ml+1]):
                        ml+=1
                    ml += 1
            while (r>l and nums[r-1]==nums[r]):
                r-=1
            r-=1;
            if(r-l<3):
                r=n-1
                while(l<r and nums[l]==nums[l+1]):
                    l+=1
                l+=1
        return result
# @lc code=end

