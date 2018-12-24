/**
 * Given an array nums of n integers and an integer target,
 * find three integers in nums such that the sum is closest to target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 * Example:
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

#include <linux_config.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    int i=0, j=0, k=0, s=0, d=0, sum=0, diff=-1;
    for (i=0; i<numsSize-2; i++) {
        for (j=i+1; j<numsSize-1; j++) {
            for (k=j+1; k<numsSize; k++) {
                s = nums[i] + nums[j] + nums[k];
                d = target-s<0? s-target : target-s;
                if (d == 0) {
                    return s;
                } else {
                    if (d < diff || diff == -1) {
                        diff = d;
                        sum = s;
                    }
                }
            }
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 1;
    int sum = threeSumClosest(nums, numsSize, target);
    printf("result sum is %d\n", sum);
    return 0;
}
