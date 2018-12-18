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


static void *
leet_malloc(size_t memn)
{
    void *res = NULL;
    if (memn > 0) {
        res = malloc(memn);
        memset(res,0,memn);
    }
    return res;
}

static int 
leet_swap(int *nums, const int dest_idx, const int src_idx)
{
    int tmp = nums[dest_idx];
    nums[dest_idx] = nums[src_idx];
    nums[src_idx] = tmp;
    return dest_idx;
}

static int *
int_tuple()
{
    return leet_malloc(sizeof(int)*4);
}

static int **
res_default()
{
    int *r = int_tuple();
    int **res = leet_malloc(sizeof(int *)*2);
    *res = r;
    return res;
}

//quick sort
void
nums_sort(int *nums, int numsSize)
{
    int m_idx, m_val, i, j;
    m_idx = numsSize/2;
    m_val = nums[m_idx];
    i=0, j=numsSize-1;
    while (i < j) {
        for (; i <m_idx; i++) {
            if (nums[i] > m_val) {
                m_idx = leet_swap(nums, i, m_idx);                
                break;
            }
        }
        for (; j>=m_idx; j--) {
            if (nums[j] < m_val) {
                m_idx = leet_swap(nums, j, m_idx);                
                break;
            }
        }
    }
    if (m_idx>0) {
        nums_sort(nums,m_idx);
    }
    if (m_idx < numsSize-1) {
        nums_sort(nums+m_idx,numsSize-m_idx);
    }
}

int
result_contain(int **res, int *res_ele)
{
    int **res_tmp = res, *res_val, count;
    while (res_tmp != NULL && *res_tmp != NULL) {
        res_val = *res_tmp; 
        if (*res_val++ == res_ele[0]) count++;
        if (*res_val++ == res_ele[1]) count++;
        if (*res_val++ == res_ele[2]) count++;
        if (*res_val++ == res_ele[3]) count++;
        if (count == 4) {
            return 1;
        }
        count = 0;
        res_tmp++;
    }
    return 0;
}

int** 
fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    int **res = NULL, *res_ele, **res_tmp;
    int i,j,k,l,sum;

    *returnSize = 0;
    nums_sort(nums, numsSize); 
    //bad case, quick retrun 
    if (numsSize < 4) return res; 
    if (nums[numsSize-1] < 0 && target > 0) return res;
    if (nums[0] > 0 && target < 0) return res;
    if (nums[0] == nums[numsSize-1] && nums[0] == 0 && target != 0) return res;
    //all zero, quick return
    if (nums[0] == nums[numsSize-1] && nums[0] == 0 && target == 0) {
        res = res_default();
        *returnSize += 1;
        return res;
    }
    //compute
    res = res_tmp = leet_malloc(1024*1024);
    i=j=k=l=0;
    for (i=0;i<numsSize-3;i++) {
        for (j=i+1;j<numsSize-2;j++) {
            for (k=j+1;k<numsSize-1;k++) {
                for (l=k+1;l<numsSize;l++) {
                    sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if (sum == target) {
                        res_ele = leet_malloc(sizeof(int)*4);
                        res_ele[0] = nums[i];
                        res_ele[1] = nums[j];
                        res_ele[2] = nums[k];
                        res_ele[3] = nums[l];
                        if (!result_contain(res, res_ele)) {
                            *res_tmp++ = res_ele;
                            (*returnSize)++;     
                        } else {
                            free(res_ele);
                        }
                    }
                }
            }
        }
    }
    return res; 
}

int main(int argc, char **argv) 
{
    int vi=0,vj=0,vk=0,vl=0,i=0,*pi=NULL;
    int target = 0;
    int returnSize = 0;
    int nums[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    int numsSize = sizeof(nums)/sizeof(int);
    int ** res = fourSum(nums, numsSize, target, &returnSize);
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
