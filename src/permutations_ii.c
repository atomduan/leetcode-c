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

#include <let_config.h>

typedef leet_queue_s leet_queue;
struct leet_queue_s {
    int *nums; 
    leet_queue *next;
};

void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

void
leet_queue_append(leet_queue **head, int *nums)
{
    leet_queue *res;
    leet_queue *node = leet_malloc(sizeof(leet_queue));
    node->nums = nums;
    if (*head == NULL) {
        *head = node;
    } else {
        res = *head;
        while (1) {
            if (res == NULL) break;
            if (res->next == NULL) {
                res->next = node;
                break;
            } else {
                res = res->next;
                continue;
            }
        }
    }
}

int
leet_head_size(int numsSize)
{
    int res = 1, i;
    for (i=0; i<numsSize; i++) {
        res *= i+1; 
    }
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int**
permuteUnique(int* nums, int numsSize, int* returnSize)
{
    int head_size = (leet_head_size(numsSize)+1)*sizeof(int*);
    int **head == leet_malloc(head_size);
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
