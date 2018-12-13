/*
 * Given an array nums of n integers and an integer target, 
 * are there elements a, b, c, and d in nums such that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 * The solution set must not contain duplicate quadruplets.
 * Example:
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 */
#include <linux_config.h>

void *
leet_malloc(size_t memn)
{
    void *res = NULL;
    if (memn > 0) {
        res = malloc(memn);
        memset(res,0,memn);
    }
    return res;
}

int** 
fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    int **res = NULL;
    return res; 
}

int main(int argc, char **argv) 
{
    int target = 0;
    int returnSize = 0;
    int nums[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    int numsSize = sizeof(nums)/sizeof(int);
    int ** res = fourSum(nums, numsSize, target, &returnSize);
    int vi=0,vj=0,vk=0,vl=0,i=0,*pi=NULL;
    printf("returnSize is %d\n", returnSize);
    if (res != NULL) {
        for (i=0; i<returnSize; i++) {
            pi = res[i];
            vi = pi[0];
            vj = pi[1];
            vk = pi[2];
            vl = pi[3];
            printf("result tuple is %d,%d,%d,%d\n",vi,vj,vk,vl);
        }
        free(res);
    } else {
        printf("return res is NULL\n");
    }
    return 0;
}
