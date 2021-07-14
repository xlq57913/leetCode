/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len_nums = nums.size(), i=0, j=0, tmp;
        if (len_nums<2)return;
        int* permutation = new int[len_nums-1];
        for (i = len_nums-1; i > 0; i--){
            permutation[i-1] = nums[i-1] - nums[i];
        }
        i = len_nums-2;
        while(i>=0 && permutation[i]>=0){
            i--;
        }
        if(i<0){
            sort(nums, 0, len_nums-1);
            return;
        }
        j=i;
        tmp = permutation[j];
        while(tmp<0 && i<len_nums-2){
            i++;
            tmp += permutation[i];
        }
        if(tmp<0){
            i++;
        }
        tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;

        sort(nums, j+1, len_nums-1);
        delete[] permutation;
    }

    void sort(vector<int>& nums, int left, int right){
            if(left==right)return;
            int tmp;
            while(left < right){
                tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                left++;
                right--;
            }
    }


};
// @lc code=end

