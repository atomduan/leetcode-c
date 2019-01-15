/*
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 */
#include <linux_config.h>

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* 
searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    return NULL; 
}

int
main(int argc, char **argv)
{
    int nums[] = {5,7,7,8,8,10};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 8;
    int returnSize = 2;
    int *res, i;
    res = searchRange(nums,numsSize,target,&returnSize);
    if (res != NULL) {
        printf("result is : [");
        for (i=0; i<returnSize; i++) {
            printf("%d,",res[i]);
        }
        printf("]\n");
    } else {
        printf("res is NULL");
    }
    return 0;
}
