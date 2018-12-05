/*
*Given an array nums of n integers, are there elements a, b, c 
*in nums such that a + b + c = 0? 
*Find all unique triplets in the array which gives the sum of zero.
*Note:
*The solution set must not contain duplicate triplets.
*
*Example:
*Given array nums = [-1, 0, 1, 2, -1, -4],
*      A solution set is:
*      [
*        [-1, 0, 1],
*        [-1, -1, 2]
*      ]
*/

#include <linux_config.h>

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int *p
    int i=0,j=0,k=0;
    int vi=0,vj=0,vk=0;
    while (i < numsSize-2) {
        vj = vi-nums[i];
        j = i+1;
        while (j < numsSize-1) {
            vk = vj-nums[j];
            k = j+1;
            while (k < numsSize) {
                if(vk == nums[k]) {
                    printf("find one, %d, %d, %d, returnSize:%d\n", nums[i], nums[j], nums[k], *returnSize, nums);
                    (*returnSize)++;     
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return 0; 
}

int main(int argc, char **argv)
{
    int returnSize = 0;
    int nums[] = {-1,0,1,2,-1,-4};
    int numsSize = sizeof(nums)/sizeof(int);
    threeSum(nums, numsSize, &returnSize); 
    return 0;
}
