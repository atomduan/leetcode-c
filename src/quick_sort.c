/**
 * Quick sort DEMO
 */
#include <let_config.h>

static int
leet_swap(int *nums,const int dest_idx,const int src_idx)
{
    int tmp = nums[dest_idx];
    nums[dest_idx] = nums[src_idx];
    nums[src_idx] = tmp;
    return dest_idx;
}

//quick sort
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
main(int argc,char **argv)
{
    int i=0;
    int nums[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    int numsSize = sizeof(nums)/sizeof(int);
    leet_quick_sort(nums,numsSize);
    printf("sort result: ");
    for (i=0; i<numsSize; i++) {
        printf("%d,", nums[i]);
    }
    printf("\n");
    return 0;
}
