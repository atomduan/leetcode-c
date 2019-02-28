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

typedef struct leet_vals_s leet_vals;
struct leet_vals_s {
    int val;
    leet_vals *next;
};

typedef struct leet_queue_s leet_queue;
struct leet_queue_s {
    leet_vals *vals;
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
leet_queue_append(leet_queue *curr, leet_queue *res)
{
    leet_queue *head;
    head = curr;
    if (head == NULL) {
        head = res;
    } else {
        while (curr != NULL) {
            if (curr->next == NULL) break;
            curr = curr->next; 
        }
        curr->next = res; 
    }
    return head;
}

inline leet_vals * 
leet_vals_append(leet_vals *curr, int val)
{
    leet_vals *head, *res;
    head = curr;
    res = leet_malloc(sizeof(leet_vals));
    res->val = val;
    if (head == NULL) {
        head = res;
    } else {
        while (curr != NULL) {
            if (curr->next == NULL) break;
            curr = curr->next; 
        }
        curr->next = res; 
    }
    return head;
}

static inline int
leet_compute_vals_size(leet_vals *curr)
{
    int res = 0;
    while (curr != NULL) {
        res++, curr = curr->next; 
    }
    return res;
}

static inline void
leet_padding_vals_res(int *vals_res, leet_vals *curr)
{
    printf("--------------------\n");
    while (curr != NULL) {
        *vals_res++ = curr->val;
        printf("%d\n", curr->val);
        curr = curr->next; 
    }
    printf("--------------------\n");
}

leet_queue *
leet_combination_sum(int* candidates, int candidatesSize, int target)
{
    leet_queue *res=NULL;
    int i, curr_val, ntarget;
    leet_queue *resq, *rc;
    leet_vals *vals;

    printf("target is %d\n",target);

    for (i=0; i<candidatesSize; i++) {
        resq = NULL;
        curr_val = candidates[i];
        ntarget = target - curr_val;
        if (ntarget > 0) {
            resq = leet_combination_sum(candidates,candidatesSize,ntarget);
            if (resq != NULL) {
                for (rc=resq; rc!=NULL; rc=rc->next)
                    rc->vals = leet_vals_append(rc->vals, curr_val);
            }
        } else
        if (ntarget == 0) {
            vals = leet_malloc(sizeof(leet_vals)); 
            vals->val = curr_val;
            resq = leet_malloc(sizeof(leet_queue));
            resq->vals = vals;
        }
        if (resq != NULL) {
            res = leet_queue_append(res, resq);
        }
    }
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
    int **res, **res_head, rsz=0, i, vals_sz=0, *vals_res;
    leet_queue *resq, *r;
    resq = leet_combination_sum(candidates, candidatesSize, target);
    for (r=resq; r!=NULL; r=r->next) rsz += 1;
    *returnSize = rsz;
    res = leet_malloc((rsz+1)*sizeof(int*));
    *columnSizes = leet_malloc((rsz+1)*sizeof(int));
    
    res_head = res;
    for (r=resq,i=0; r!=NULL; r=r->next, i++) {
        vals_sz = leet_compute_vals_size(r->vals); 
        (*columnSizes)[i] = vals_sz;
        vals_res = leet_malloc((vals_sz+1)*sizeof(int));
        leet_padding_vals_res(vals_res,r->vals);
        *res++ = vals_res;
    }
    return res_head;
}

int
main(int argc, char **argv)
{
    int candidates[] = {2,3,6,7};
    int candidatesSize = sizeof(candidates)/sizeof(int);
    int target = 7;
    int *columnSizes = NULL;
    int returnSize = 0;
    int **res,*arr,i,j,arr_len;
    res = combinationSum(candidates,candidatesSize,target,&columnSizes,&returnSize);
    if (res != NULL) {
        printf("res is : {\n");
        for (i=0; i<returnSize; i++) {
            arr_len = columnSizes[i];
            arr = res[i];
            printf("    [");
            for (j=0; j<arr_len; j++) {
                printf("%d,",arr[j]); 
            }
            printf("]\n");
        }
        printf("}\n");
    } else {
        printf("res is NULL\n");
    }
    return 0;
}
