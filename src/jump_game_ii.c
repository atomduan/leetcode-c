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
    int i,j,r, step, maxr, maxri;
    for (i=0,step=0; i<numsSize;) {
        maxr = INT_MIN;
        r = nums[i]; maxri=i+1;
        for (j=i+1; j<=i+r && j<numsSize; j++) {
            if (nums[j] >= maxr) {
                maxr = nums[j];
                maxri = j; 
            }
        }
        i = maxri; step++; 
        if (i >= numsSize-1) break;
    }
    return step;    
}

int 
main(int argc, char **argv) 
{
    int nums[] = {2,3,1,1,4};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("jump result is %d\n", jump(nums,numsSize));
    return 0; 
}
