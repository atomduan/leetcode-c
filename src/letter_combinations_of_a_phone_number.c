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

char *dict[10] =  {
    " ",
    "_",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuvw",
    "xyz"
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
span_dict_str(char *ds) 
{
    char *ss;
    char **res, rp;
    int ds_len,i;
    ds_len = strlen(ds);
    res = rp = calloc(sizeof(char *)*(ds_len+1));
    for (i=0 ; i<ds_len; i++) {
        ss = calloc(sizeof(char)*2);
        ss = ds[i];
        *rp++ = ss;
    }
    return res;
}

int
compute_collect_size(void *clt)
{
    int count = 0;
    void *p = clt;
    while (p != NULL) {
        count++; 
    }
    return count;
}

char **
span_res_with_dict(char *ds, char **res) 
{
    char **result,rp,rt;
    char *ss,dp;
    int ds_size,res_size,total_size,ssize;

    ds_size = compute_res_size(ds);
    res_size = compute_res_size(res);
    total_size = ds_size * res_size + 1;
    result = rt = calloc(sizeof(char *)*total_size);

    rp = res;
    while(rp != NULL) {
        ss = *rp;    
        dp = ds;
        while (*dp != '\0') {
            ssize = strlen(ss);
            dp++;
        }
        rp++;
    }
    return result;
}

char **
do_letter_combination(char *digits)
{
    char **res;
    char *digt, ds;

    digt = digits+1;
    ds = dict[leet_ctoi(digits)];
    if (*digt == '\0') {
        res = span_dict_str(ds);
    } else {
        res = do_letter_combination(digt); 
        res = span_res_with_dict(ds,res);
    }
    return res;
}

int
compute_res_size(char **res)
{
    int size = 0;
    char **p = res;
    while (p != NULL) {
        size++;
    }
    return size;
}

char** 
letterCombinations(char* digits, int* returnSize) 
{
    char **res;
    res = do_letter_combination(digits);
    *returnSize = compute_res_size(res);
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
