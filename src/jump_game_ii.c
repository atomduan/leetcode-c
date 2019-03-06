/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 *     Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Note:
 * 
 * You can assume that you can always reach the last index.
 */

#include <linux_config.h>

int
jump(int* nums, int numsSize)
{
    int range, i, min_step, step;
    if (numsSize == 1) return 0;
    if (nums[0] >= numsSize-1) return 1;
    if (nums[0] == 0) return 10000;

    range = nums[0];
    min_step = 10000;
    for (i=1; i<=range && i<numsSize; i++) {
        step = jump(&nums[i], numsSize-i); 
        if (step < min_step) min_step = step;
    }
    return min_step+1;
}

/**
 * TODO need implemented
 */
int 
main(int argc, char **argv) 
{
    //int nums[] = {2,3,1,1,4};
    //int nums[] = {4,1,1,3,1,1,1};
    //int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    //int nums[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("jump result is %d\n", jump(nums,numsSize));
    return 0; 
}
