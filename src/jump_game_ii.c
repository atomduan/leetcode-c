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

int INIT_SIZE=0;

void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

int
do_jump(int* nums, int numsSize, int skip_len, int *dict, int s)
{
    int range, i, min_step, step;
    if (numsSize == 1) return 0;
    if (nums[0] >= numsSize-1) return 1;
    if (nums[0] == 0) return INIT_SIZE;

    range = nums[0];
    min_step = INIT_SIZE;
    for (i=1; i<=range && i<numsSize; i++) {
        if (i > skip_len) {
            if (dict[s+i] == 0) {
                step = do_jump(&nums[i],numsSize-i,nums[0]-i,dict,s+i);
                dict[s+i] = step;
            } else {
                step = dict[s+i];
            }
            if (step < min_step) min_step = step;
        }
    }
    return min_step+1;
}

int
jump(int* nums, int numsSize)
{
    INIT_SIZE = numsSize;
    int *dict = leet_malloc((numsSize+1)*sizeof(int));
    return do_jump(nums,numsSize,0,dict,0);
}

int
main(int argc, char **argv)
{
    //int nums[] = {2,3,1,1,4};
    //int nums[] = {4,1,1,3,1,1,1};
    //int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    //int nums[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8};
    //int nums[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4};
    int nums[] = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    //int nums[] = {5,8,1,8,9,8,7,1,7,5,8,6,5,4,7,3,9,9,0,6,6,3,4,8,0,5,8,9,5,3,7,2,1,8,2,3,8,9,4,7,6,2,5,2,8,2,7,9,3,7,6,9,2,0,8,2,7,8,4,4,1,1,6,4,1,0,7,2,0,3,9,8,7,7,0,6,9,9,7,3,6,3,4,8,6,4,3,3,2,7,8,5,8,6,0};
    int numsSize = sizeof(nums)/sizeof(int);
    printf("jump result is %d\n", jump(nums,numsSize));
    return 0;
}
