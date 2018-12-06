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

int *register_pool(int vi, int vj, int vk, int **res_head) {
    //check whether tuple exsited in pool_head.
    int **p = res_head;
    int exist_flag = 0; 
    int count = 0;
    int *t = NULL;
    int *res = NULL;
    int i,j,tmp;
    
    int k[] = {vi, vj, vk};
    for (i=0; i<3; i++) {
        for (j=0; j<3-i-1; j++) {
            if (k[j] > k[j+1]) {
                tmp = k[j];
                k[j] = k[j+1];
                k[j+1] = tmp;
            }
        }
    }

    while (p != NULL && *p != NULL) {
        t = *p;
        if(*t++ == k[0]) count += 1; 
        if(*t++ == k[1]) count += 1; 
        if(*t++ == k[2]) count += 1; 
        if (count == 3) {
            exist_flag = 1;
            break;
        }
        count = 0;
        p++;
    }

    if (!exist_flag) {
        res = malloc(sizeof(int)*3);
        t = res;
        *t++ = k[0];
        *t++ = k[1];
        *t++ = k[2];
        for (i=0; i<3; i++) {
            for (j=0; j<3-i-1; j++) {
                if (res[j]>res[j+1]) {
                    tmp = res[j];      
                    res[j] = res[j+1];
                    res[j+1] = tmp;
                }
            }
        }
    }
    return res;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    int i=0,j=0,k=0;
    int vi=0,vj=0,vk=0;
    int *tmp = NULL;

    size_t res_size = sizeof(int *)*(numsSize*numsSize+1);
    int **res_head = malloc(res_size);
    int **res = res_head;
    *returnSize = 0;

    memset(res_head, 0, res_size);
    while (i < numsSize-2) {
        vj = vi-nums[i];
        j = i+1;
        while (j < numsSize-1) {
            vk = vj-nums[j];
            k = j+1;
            while (k < numsSize) {
                if (vk == nums[k]) {
                    tmp = register_pool(nums[i],nums[j],nums[k],res_head);
                    if (tmp != NULL) {
                        *res++ = tmp;
                        (*returnSize)++;     
                    }
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return res_head; 
}

int main(int argc, char **argv)
{
    int returnSize = 0;
    int nums[] = {-1,0,1,2,-1,-4,-1,0,1};
    //int nums[] = {-1,0,1,2,-1,-4};
    int numsSize = sizeof(nums)/sizeof(int);
    int **res = threeSum(nums, numsSize, &returnSize); 
    printf("returnSize is %d\n", returnSize);
    int vi=0, vj=0, vk=0, i=0, *pi = NULL;
    for (i=0; i<returnSize; i++) {
        pi = res[i];
        vi = pi[0];
        vj = pi[1];
        vk = pi[2];
        printf("result tuple is %d, %d, %d, \n", vi, vj, vk);
    }
    free(res);
    return 0;
}
