/**
 * Given an unsorted integer array, find the smallest missing positive integer.
 * 
 * Example 1:
 * Input: [1,2,0]
 * Output: 3
 * 
 * Example 2:
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * Example 3:
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * Note:
 * Your algorithm should run in O(n) time and uses constant extra space.
 */
#include <linux_config.h>

void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

int 
firstMissingPositive(int* nums, int numsSize)
{
    int i, min, max, posn, *dict, idx;
    max = 0;
    min = INT_MAX;
    posn = 0;
    for (i=0; i<numsSize; i++) {
        if (nums[i]>0 && nums[i]>max) max = nums[i];
        if (nums[i]>0 && nums[i]<min) min = nums[i];
        if (nums[i]>0) posn++;
    }
    if (min > 1) return 1;
    if (min+posn-1 < max) {
        dict = leet_malloc((posn+1)*sizeof(int));
        for (i=0; i<numsSize; i++) {
            if (nums[i]<=0) continue;
            if (min+posn < nums[i]) continue;
            idx = nums[i] - min; 
            //printf("min:%d,max:%d,ival:%d,idx:%d,posn:%d\n",min,max,nums[i],idx,posn);
            dict[idx] = 1;
        }
        for (i=0;;i++)
           if (dict[i] == 0)  return i+min;
    } else {
        return max+1;
    }
}

int
main(int argc, char **argv)
{
    //int nums[] = {7,8,9,11,12};
    //int nums[] = {3,4,-1,1};
    //int nums[] = {0,1,2};
    int nums[] = {1,3};
    int numsSize = sizeof(nums)/sizeof(int);
    int result = firstMissingPositive(nums,numsSize);
    printf("result is :%d\n", result);
    return 0;
}
