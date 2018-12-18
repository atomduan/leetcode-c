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

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** 
generateParenthesis(int n, int* returnSize)
{
    return NULL;    
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
