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

static void *
leet_malloc(size_t size)
{
    void *res = NULL;
    if (size > 0) {
        res = malloc(size);
        memset(res,0,size);
    }
    return res;
}

static inline char *
alloc_str_block(int n)
{
    return leet_malloc(2*n+1);
}

static size_t
compute_res_size(char **res)
{
    char **rp = res;
    size_t size = 0;
    while (*rp != NULL) {
        size++; rp++;
    }
    return size;
}

static char **
merge_result_arr(char **lr,char **rr,int index)
{
    int i=0;
    char **lr_head = lr;
    char **rr_head = rr;
    size_t lr_size = compute_res_size(lr);
    size_t rr_size = compute_res_size(rr);
    char **res = leet_malloc(sizeof(char*)*(lr_size+rr_size+1));
    while (*lr != NULL) {
        res[i++] = *lr;
        (*lr)[index] = '(';
        lr++;
    }
    while (*rr != NULL) {
        res[i++] = *rr;
        (*rr)[index] = ')';
        rr++;
    }
    free(lr_head);
    free(rr_head);
    return res;
}

static char **
generate_parenthe_element(int n,int p_size,int *returnSize)
{
    char **lr, **rr, **rt;
    int index;
    index = p_size-n;
    if (n > 0) {
        lr = generate_parenthe_element(n-1,p_size, returnSize);
        rr = generate_parenthe_element(n-1,p_size, returnSize);
        return merge_result_arr(lr,rr,index);
    } else {
        rt = leet_malloc(sizeof(char *)*2);
        rt[0] = alloc_str_block(p_size);
        (*returnSize)++;
        return rt;
    }
}

static int
evaluate_res(char *r)
{
    int sum = 0;
    while (1) {
        if (*r == '\0') break;
        if (*r == '(') {
            sum++;
        } else {
            sum--;
        }
        if (sum < 0) return 1;
        r++;
    }
    return sum;
}


char **
generateParenthesis(int n,int *returnSize)
{
    char **init_res;
    char **res, **res_head;
    int p_size = n*2, i, valid_count=0;
    init_res = generate_parenthe_element(n*2,p_size,returnSize);
    res_head = res = leet_malloc(sizeof(char*)*(*returnSize+1));

    if (init_res != NULL) {
        for (i=0; i<*returnSize; i++) {
            if (0 == evaluate_res(init_res[i])) {
                *res++ = init_res[i];
                valid_count++;
            } else {
                free(init_res[i]);
            }
        }
    }
    free(init_res);
    *returnSize = valid_count;
    return res_head;
}

int
main(int argc,char **argv)
{
    char **res = NULL;
    int returnSize = 0;
    int n=3, i;
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
