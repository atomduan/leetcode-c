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
    int i=0,j=0,tmp=0;
    
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
    int i=0,j=0,t=0;
    int vi=0,vj=0,vk=0;
    int *tmp = NULL;
    int *numbers = NULL;
    int all_zero = 1;

    size_t res_size = sizeof(int *)*(numsSize*numsSize+1);
    int **res_head = malloc(res_size);
    int **res = res_head;
    *returnSize = 0;
    memset(res_head, 0, res_size);

    if (numsSize < 3) {
        return res_head;
    }

    numbers = malloc(sizeof(int)*numsSize);
    memset(numbers, 0, sizeof(int)*numsSize);

    for (i=0; i<numsSize; i++) {
        if (nums[i] != 0) {
            all_zero = 0;
        }
    }

    if (all_zero) {
        tmp = register_pool(0,0,0,res_head);
        if (tmp != NULL) {
            *res++ = tmp;
            (*returnSize)++;     
        }
        return res_head;
    }

    for (i=0; i<numsSize; i++) {
        numbers[i] = nums[i];
    }

    for (i=0; i<numsSize; i++) {
        for (j=0; j<numsSize-i-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                t = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = t;
            }
        }
    }

    if (numbers[0] > 0) {
        return res_head;
    }
    if (numbers[numsSize-1] < 0) {
        printf("b");
        return res_head;
    }

    int *bm = malloc(1024*1024);
    memset(bm, 0, 1024*1024);
    for (i=0; i<numsSize; i++) {
        if (numbers[i] > 0) {
            bm[numbers[i]] = 1;
        }
    }

    i=0,j=0,t=0;
    while (i < numsSize-2) {
        vj = vi-numbers[i];
        j = i+1;
        while (j < numsSize-1) {
            vk = vj-numbers[j];
            if (numbers[j]<0 || numbers[j]>0) {
                if (vk > 0) {
                    if (bm[vk]) {
                        if (vk != numbers[j]) {
                            tmp = register_pool(numbers[i],numbers[j],vk,res_head);
                            if (tmp != NULL) {
                                *res++ = tmp;
                                (*returnSize)++;     
                            }
                        } else {
                            if (numbers[j]==numbers[j+1]) {
                                tmp = register_pool(numbers[i],numbers[j],vk,res_head);
                                if (tmp != NULL) {
                                    *res++ = tmp;
                                    (*returnSize)++;     
                                }
                            }
                        }
                    }
                }
            } else {
                if (vk > 0) {
                    if (bm[vk]) {
                        if (vk != numbers[j]) {
                            tmp = register_pool(numbers[i],numbers[j],vk,res_head);
                            if (tmp != NULL) {
                                *res++ = tmp;
                                (*returnSize)++;     
                            }
                        } else {
                            if (numbers[j]==numbers[j+1]) {
                                tmp = register_pool(numbers[i],numbers[j],vk,res_head);
                                if (tmp != NULL) {
                                    *res++ = tmp;
                                    (*returnSize)++;     
                                }
                            }
                        }
                    }
                } else {
                    if (vk == numbers[j+1]) {
                        tmp = register_pool(numbers[i],numbers[j],numbers[j+1],res_head);
                        if (tmp != NULL) {
                            *res++ = tmp;
                            (*returnSize)++;     
                        }
                    }
                }
            }
            j++;
        }
        i++;
    }
    free(bm);
    free(numbers);
    return res_head; 
}

int main(int argc, char **argv)
{
    int returnSize = 0;
    int nums[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    //int nums[] = {-1,0,1,2,-1,-4,-1,0,1};
    //int nums[] = {-1,0,1,2,-1,-4};
    //int nums[] = {1,2,-2,-1};
    //int nums[] = {0,0,0,0,0,0,0,0,0,0};
    //int nums[] = {0,-1,1};

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
