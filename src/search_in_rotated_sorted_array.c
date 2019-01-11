/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */

#include <linux_config.h>

int bin_serach(int* nums, int si, int ei, int target) {
    int mi = (si+ei)/2, li, ri;
    if (si == ei)
        return nums[si]==target ? nums[si] : -1;
    if (si == mi)
        if (nums[si] == target) return si;
    if (mi == ei)
        if (nums[si] == target) return si;
    if (ei-si == 1) return -1;
    li = bin_serach(nums, si, mi, target);    
    if (li > 0) return li;
    ri = bin_serach(nums, mi, ei, target);    
    return ri;
}

int 
search(int* nums, int numsSize, int target)
{
    return bin_serach(nums,0,numsSize-1,target); 
}

int
main(int argc, char **argv)
{
    int nums[] = {4,5,6,7,0,1,2};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 0;
    printf("result is %d\n", search(nums,numsSize,target));
    return 0;
}
