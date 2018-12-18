/** 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */

#include <linux_config.h>

void *
leet_malloc(size_t size)
{
    void *res = NULL;
    if (size > 0) {
        res = malloc(size); 
        memset(res,0,size);
    }
    return res;
}

char *
alloc_str_block(int n)
{
    return leet_malloc(2*n+1);
}

size_t
compute_res_size(char **res)
{
    char **rp = res;
    size_t size = 0;
    while (rp != NULL) {
        size++; rp++;
    }
    return size;
}

char **
merge_result_arr(char **lr, char **rr, int index)
{
    int i=0;
    size_t lr_size = compute_res_size(lr);
    size_t rr_size = compute_res_size(rr);
    char **res = leet_malloc(sizeof(char*)*(lr_size+rr_size+1));
    while (lr != NULL) {
        res[i] = *lr;
        *lr[index] = '(';
        lr++;
    }
    while (rr != NULL) {
        res[i] = *rr;
        *rr[index] = ')';
        rr++;
    }
    return res;
}

char **
generate_parenthe_element(int n, int p_size)
{
    char **lr, **rr, **rt;
    int index;
    index = p_size-n;
    if (n > 0) {
        lr = generate_parenthe_element(n-1,p_size);
        rr = generate_parenthe_element(n-1,p_size);
        return merge_result_arr(lr,rr,index);
    } else {
        rt = leet_malloc(sizeof(char **)*2);
        rt[0] = alloc_str_block(p_size);
        return rt;
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** 
generateParenthesis(int n, int* returnSize)
{
    char **init_res;
    init_res = generate_parenthe_element(n,n);
    return init_res;
}

int
main(int argc, char **argv)
{
    char **res = NULL;
    int returnSize = 0;
    int n=10, i;
    res = generateParenthesis(n, &returnSize);
    printf("returnSize is %d\n", returnSize);
    if (res != NULL) {
        for (i=0; i<returnSize; i++) {
            printf("res ele is: %s\n",res[i]);
        }
        free(res);
    } else {
        printf("return res is: NULL\n");
    }
    return 0;
}
