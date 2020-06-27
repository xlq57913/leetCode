#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#

# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        l = len(nums)
        minError = 1e23;
        for i in range(l-2):
            j = i+1;
            k = l-1;
            while(j<k):
                tmpError = nums[i]+nums[j]+nums[k]-target;
                if(tmpError<0):
                    j = j+1
                elif(nums[i]+nums[j]+nums[k]>target):
                    k = k-1;
                else:
                    return target
                if(abs(tmpError)<abs(minError)):
                        minError=tmpError
        return minError+target
# @lc code=end

