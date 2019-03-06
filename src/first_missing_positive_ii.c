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

static int
leet_swap(int *nums,const int dest_idx,const int src_idx)
{
    int tmp = nums[dest_idx];
    nums[dest_idx] = nums[src_idx];
    nums[src_idx] = tmp;
    return dest_idx;
}

static void
leet_quick_sort(int *nums,int numsSize)
{
    int m_idx, m_val, i, j;
    m_idx = numsSize/2; //compute partition index
    m_val = nums[m_idx];
    i=0, j=numsSize-1;
    while (i < j) {
        for (; i <m_idx; i++) {
            if (nums[i] > m_val) {
                m_idx = leet_swap(nums, i, m_idx);
                break; //to for loop not to outter while
            }
        }
        for (; j>=m_idx; j--) {
            if (nums[j] < m_val) {
                m_idx = leet_swap(nums, j, m_idx);
                break;
            }
        }
    }
    //devide by m_idx
    if (m_idx>0) {
        leet_quick_sort(nums,m_idx);
    }
    if (m_idx < numsSize-1) {
        leet_quick_sort(nums+m_idx,numsSize-m_idx);
    }
}

int
firstMissingPositive(int* nums, int numsSize)
{
    int i, cv, pv, st;
    leet_quick_sort(nums,numsSize);
    if(nums[0] > 1) return 1;

    for (i=0,st=0; i<numsSize; i++) {
        if (nums[i] <= 0) continue;
        if (st == 0) {
            st = 1;
            if(nums[i] > 1) return 1;
            cv = nums[i];
            pv = nums[i];
        } else {
            if (nums[i] == pv) continue;
            cv += 1;
            if (cv != nums[i]) return cv;
            pv = nums[i];
        }
    }
    return nums[numsSize-1] + 1;
}

int
main(int argc, char **argv)
{
    //int nums[] = {7,8,9,11,12};
    //int nums[] = {3,4,-1,1};
    int nums[] = {0,1,2};
    //int nums[] = {1,3,3};
    int numsSize = sizeof(nums)/sizeof(int);
    int result = firstMissingPositive(nums,numsSize);
    printf("result is :%d\n", result);
    return 0;
}
