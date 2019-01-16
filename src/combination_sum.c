/**
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 *   [7],
 *   [2,2,3]
 * ]
 * 
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 */
#include <linux_config.h>

typedef struct leet_queue_s leet_queue;
struct leet_queue_s {
    int val;
    leet_queue *next;
};

void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

inline leet_queue * 
leet_queue_append(leet_queue *curr, int val)
{
    leet_queue *res = leet_malloc(sizeof(leet_queue));
    res->val = val;
    if (curr != NULL) curr->next = res; 
    return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** 
combinationSum(int* candidates, int candidatesSize, int target, 
               int** columnSizes, int* returnSize) 
{
    return NULL; 
}

int
main(int argc, char **argv)
{
    return 0;
}
