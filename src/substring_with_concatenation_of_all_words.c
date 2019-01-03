/**
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word in words
 * exactly once and without any intervening characters.
 *
 * Example 1:
 * Input:
 *   s = "barfoothefoobarman",
 *   words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 * Example 2:
 * Input:
 *   s = "wordgoodgoodgoodbestword",
 *   words = ["word","good","best","word"]
 * Output: []
 */
#include <linux_config.h>

static void *
leet_malloc(size_t size)
{
    void *res = NULL;
    res = malloc(size);
    memset(res,0,size);
    return res;
}

static int
check_bitmap(int *bitmap, int index) {
    int res = 0, bi, *buck, offset, bit_flag;
    //TODO need optimize, should we do not use divide
    bi = index / (sizeof(int)*8); 
    offset = index % (sizeof(int)*8);
    buck = bitmap+bi;
    bit_flag = 0x1 << offset; 
    if (!(*buck & bit_flag)) {
        *buck = *buck | bit_flag;
        res = 1;
    }
    return res;
}

static int
match_word(char *s, char *word)
{
    int res = 1;
    while (*word != '\0') {
        if (*s != *word) {
            res = 0; break;
        }
        s++; word++;
    }
    return res;
}

static int
match_substring(char* s,char** words,int wordsSize)
{
    int word_len, *bit_map, bit_size;
    int i, j, res=1, match_flag=0;

    word_len = strlen(*words);
    bit_size = wordsSize/(sizeof(int)*8) + 1;
    bit_map = leet_malloc(bit_size);
    
    for (i=0; i<wordsSize; i++) {
        for (j=0; j<wordsSize; j++) {
            if (match_word(s,words[j])) {
                if (check_bitmap(bit_map,j)) {
                    match_flag = 1;  
                    break;
                }
            }
        }
        if (!match_flag) {
            goto fail_handle;
        }
        s += word_len; match_flag = 0;
    }

    //must work all words
    if (i < wordsSize-1) goto fail_handle;
    goto success_handle;

fail_handle:
    res = 0;
success_handle:
    free(bit_map);
    return res;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
findSubstring(char* s,char** words,int wordsSize,int* returnSize)
{
    char *tmp_s;
    int *res, *res_tmp, index, word_len;
    res = res_tmp = leet_malloc(sizeof(int)*strlen(s));

    if (words == NULL) return res; 
    if (*words == NULL) return res; 

    tmp_s = s; index = 0;
    word_len = strlen(*words);
    if (word_len == 0) return res; 

    while (*tmp_s != '\0') {
        if (match_substring(tmp_s,words,wordsSize)) {
            *res_tmp++ = index; 
            (*returnSize)++;
        }
        tmp_s += word_len;
        index += word_len;
    }
    return res;
}

int
main(int argc, char **argv)
{
    char *s = "aaaaaaaaaaaaaaaaaaaa";
    char *warr[] = {"a","a"};
    char **words = warr;
    int wordsSize = 2;
    int returnSize = 0, i;
    int *result;

    result = findSubstring(s,words,wordsSize,&returnSize);
    if (result != NULL) {
        printf("result print:\n");
        for (i=0; i<returnSize; i++) {
            printf(",%d", result[i]);
        }
        printf("\n");
    } else {
        printf("return result is NULL\n");
    }
    return 0;
}
