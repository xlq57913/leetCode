#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个有序数组的中位数
#
class Solution:

    def getMedian(self,nums: List[int],m:int):
        if(m%2==0):
            return float(nums[m//2]+nums[m//2-1])/2
        else:
            return float(nums[(m-1)//2])


    def findMedian(self,nums1: List[int],m: int,nums2: List[int],n: int)-> float:
        if(m==0):
            if(n%2==0):
                return float(nums2[n//2]+nums2[n//2-1])/2
            else:
                    return float(nums2[(n-1)//2])
        elif(n==0):
            if(m%2==0):
                return float(nums1[m//2]+nums1[m//2-1])/2
            else:
                    return float(nums1[(m-1)//2])
        else:
            if(nums1[0]>=nums2[n-1]):
                if(m>n):
                    if((m+n)%2==0):
                        return float(nums1[(m+n)//2-n]+nums1[(m+n)//2-1-n])/2
                    else:
                        return float(nums1[(m+n-1)//2-n])
                elif(n>m):
                    if((m+n)%2==0):
                        return float(nums2[(m+n)//2]+nums2[(m+n)//2-1])/2
                    else:
                        return float(nums2[(m+n-1)//2])
                else:
                    return float(nums1[0]+nums2[n-1])/2
            elif(nums2[0]>nums1[m-1]):
                if(m>n):
                    if((m+n)%2==0):
                        return float(nums1[(m+n)//2]+nums1[(m+n)//2-1])/2
                    else:
                        return float(nums1[(m+n-1)//2])
                elif(n>m):
                    if((m+n)%2==0):
                        return float(nums2[(m+n)//2-m]+nums2[(m+n)//2-1-m])/2
                    else:
                        return float(nums2[(m+n-1)//2-m])
                else:
                    return float(nums1[m-1]+nums2[0])/2
            elif(abs(self.getMedian(nums1,m)-self.getMedian(nums2,n))<0.00001):
                return float(self.getMedian(nums1,m))
            else:
                if(m<=3 or n<=3):
                    if(m<=3):
                        for i in range(m):
                            nums2.append(nums1[i])
                        nums2.sort()
                        return self.getMedian(nums2,m+n)
                    else:
                        for i in range(n):
                            nums1.append(nums2[i])
                        nums1.sort()
                        return self.getMedian(nums1,m+n)
                if(m>n):
                    if(n==1):
                        nums1.append(nums2[0])
                        nums1.sort()
                        return self.getMedian(nums1,m+1)
                    tmp = (n+1)//2-1
                    if(self.getMedian(nums1,m)>self.getMedian(nums2,n)):
                        return self.findMedian(nums1[:m-tmp],m-tmp,nums2[tmp:],n-tmp)
                    else:
                        return self.findMedian(nums1[tmp:],m-tmp,nums2[:n-tmp],n-tmp)
                else:
                    if(m==1):
                        nums2.append(nums1[0])
                        nums2.sort()
                        return self.getMedian(nums2,n+1)
                    tmp = (m+1)//2-1
                    if(self.getMedian(nums1,m)>self.getMedian(nums2,n)):
                        return self.findMedian(nums1[:m-tmp],m-tmp,nums2[tmp:],n-tmp)
                    else:
                        return self.findMedian(nums1[tmp:],m-tmp,nums2[:n-tmp],n-tmp)



    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        return self.findMedian(nums1,m,nums2,n)
        

