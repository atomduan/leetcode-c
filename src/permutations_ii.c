/**
 * Given a collection of numbers that might contain duplicates,
 * return all possible unique permutations.
 * 
 * Example:
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */
#include <linux_config.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int**
permuteUnique(int* nums, int numsSize, int* returnSize)
{
    return NULL; 
}

int
main(int argc,char **argv)
{
    int i,j;
    int nums[] = {1,1,2};
    int numsSize = sizeof(nums)/sizeof(int);
    int returnSize = 0;
    int **res = permuteUnique(nums,numsSize,&returnSize);
    for (i=0; i<returnSize; i++) {
        printf("[");
        for (j=0; j<numsSize; j++) {
            printf("%d,",res[i][j]);
        }
        printf("]\n");
    }
    return 0;
}
