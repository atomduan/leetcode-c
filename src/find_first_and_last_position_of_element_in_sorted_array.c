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

inline void *
leet_malloc(size_t size)
{
    void *res = NULL;
    res = malloc(size);
    memset(res,0,size);
    return res;
}

void
binary_serach(int *nums, int si, int ei, int *res, int target)
{
    int mi = (si+ei)/2;
    if (ei - si <= 1) {
        if (nums[si] == target) {
            if (res[0]==-1 || res[0]>=si) res[0] = si;
            if (res[1]==-1 || res[1]<=si) res[1] = si;
        }
        if (nums[ei] == target) {
            if (res[0]==-1 || res[0]>=ei) res[0] = ei;
            if (res[1]==-1 || res[1]<=ei) res[1] = ei;
        }
        return;
    }
    binary_serach(nums,si,mi,res,target);
    binary_serach(nums,mi+1,ei,res,target);
}

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *res = leet_malloc(sizeof(int)*2);
    res[0] = res[1] = -1;
    if (numsSize > 0) {
        binary_serach(nums,0,numsSize-1,res,target);
    }
    *returnSize = 2;
    return res;
}

int
main(int argc, char **argv)
{
    int nums[] = {5,7,7,8,8,10};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 10;
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
