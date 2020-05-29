/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 *
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include <let_config.h>

char *dict[10] = {
    " ",
    "_",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

static inline int
leet_ctoi(char *c)
{
    return *c - 48;
}

static int
compute_res_size(char **res)
{
    int size = 0;
    char **p = res;
    while (*p++ != NULL) {
        size++;
    }
    return size;
}

static void *
leet_malloc(size_t memsize)
{
    void *res;
    res = malloc(memsize);
    memset(res,0,memsize);
    return res;
}

static char **
span_dict_str(char *ds)
{
    char *ss, **res, **rp;
    int ds_len,i;
    ds_len = strlen(ds);
    res = rp = leet_malloc(sizeof(char *)*(ds_len+1));
    for (i=0 ; i<ds_len; i++) {
        ss = leet_malloc(sizeof(char)*2);
        *ss = ds[i];
        *rp++ = ss;
    }
    return res;
}

static char **
span_res_with_dict(char *ds,char **res)
{
    char **result,**rp,**rt;
    char *ss,*dp,*ns,*nss;
    int ds_size,res_size,total_size,ssize,i;

    ds_size = strlen(ds);
    res_size = compute_res_size(res);
    total_size = ds_size * res_size + 1;
    result = rt = leet_malloc(sizeof(char *)*total_size);

    rp = res;
    while(rp != NULL && *rp != NULL) {
        dp = ds;
        while (*dp != '\0') {
            ss = *rp;
            ssize = strlen(ss);
            ns = nss = leet_malloc(ssize+2);
            *nss++ = *dp;
            for (i=0; i<ssize; i++) {
                *nss++ = *ss++;
            }
            *rt++ = ns;
            dp++;
        }
        free(*rp);
        rp++;
    }
    free(res);
    return result;
}

static char **
do_letter_combination(char *digits)
{
    char **res, *ds;
    ds = dict[leet_ctoi(digits)];
    if (*(digits+1) == '\0') {
        res = span_dict_str(ds);
    } else {
        res = do_letter_combination(digits+1);
        res = span_res_with_dict(ds,res);
    }
    return res;
}

char**
letterCombinations(char* digits,int* returnSize)
{
    char **res = NULL;
    *returnSize = 0;
    if (digits!=NULL && strlen(digits)>0) {
        res = do_letter_combination(digits);
        *returnSize = compute_res_size(res);
    }
    return res;
}

int
main(int argc,char **argv)
{
    //char *digits = "27";
    char *digits = "";
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
    printf("returnSize is %d\n", returnSize);
    return 0;
}
