/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *   return [0, 1].
 *  Note: The returned array must be malloced, assume caller calls free().
 */
#include <let_config.h>

int *
twoSum(int* nums,int numsSize,int target)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int *r = malloc(sizeof(i)*2);
    int *result = r;
    for (i=0; i<numsSize; i++, nums++) {
        a = *nums;
        for (j=i+1; j<numsSize; j++) {
            if (target-a == nums[j-i]) {
                *r++ = i, *r = j;
                break;
            }
        }
    }
    return result;
}
