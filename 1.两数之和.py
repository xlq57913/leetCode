#
# @lc app=leetcode.cn id=1 lang=python
#
# [1] 两数之和
#
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i1 in range(len(nums)):
            for i2 in range(i1,len(nums)):
                if(i1==i2):
                    continue
                else:
                    if(nums[i1]+nums[i2]==target):
                        return [i1,i2]
        

