/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * Example:
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include <linux_config.h>

char *dict[10][3] =  {
    {" "},
    {"_"},
    {"a","b","c"},
    {"d","e","f"},
    {"g","h","i"},
    {"j","k","l"},
    {"m","n","o"},
    {"p","q","s"},
    {"t","u","v"},
    {"x","y","x"}
};

int
leet_ctoi(char *c)
{
    char c = *c;
    return c - 48;
}

int
res_size(char *digits)
{
    char *p = digits;
    int count = 1;
    while (*p != '\0') {
        count *= 3;
    }
    return count;
}

char **
do_letter_combination(char *digits, int *returnSize, int digtLen, int pos)
{
    char **res = NULL, r;
    char *digt;
    char *tmp,rs;
    int index,i;

    tmp = digits;
    digt = digits+1;

    for (i=0; i<3; i++) {
        index = leet_ctoi(tmp);
        if (digt != '\0') {
            if (res == NULL) {
                
            }
            r = do_letter_combination(digt, returnSize, digtLen, digtLen, pos+1); 
            rs = *r;
            while (rs != NULL) {
                rs[pos] = *dict[index][i];
                rs = *r++;
            }
        } else {
            if (res == NULL) {
                res = calloc(sizeof(char*)*4);
                r = res;
            }
            rs = calloc(digtLen+1);
            rs[pos] = *dict[index][i];
            *r++ = rs;
            returnSize++;
        }
    }
    return res;
}

/* 
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** 
letterCombinations(char* digits, int* returnSize) 
{
    char **res,digt;
    int curr_idx;
    int digt_len;
    int res_size;

    digt_len = strlen(digits);
    rsz = res_size(digits);

    res = calloc(sizeof(char *)*(rsz+1));

    do_letter_combination(digits, returnSize, digt_len, res, 0);

    return res;


    if (digt != NULL) {
        for (i=0; i<3; i++) {
            **r = letterCombinations(digt, returnSize);
        }
    } else {
        for (i=0; i<3; i++) {
            tmp = malloc(digt_len+1);
            memset(tmp, 0, digt_len+1);
            tmp[0] = *dict[curr_idx][i];
            res = malloc(sizeof(char *)*4);
            memset(res, 0, sizeof(char *)*4);
            res[i] = tmp;
        }
    }
    return res; 
}

int 
main(int argc, char **argv)
{
    char *digits = "23";
    int returnSize = 0;
    char ** res = letterCombinations(digits, &returnSize);
    if (res != NULL) {
        printf("[");
        for (;*res != NULL; res++) {
            printf("%s,", *res);
        }
        printf("]\n");
    } else {
        printf("the res is NULL pointer......\n");
    }
    return 0;
}
