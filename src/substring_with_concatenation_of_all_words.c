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


void *
leet_malloc(size_t size)
{
    void *res = NULL;
    res = malloc(size);
    memset(res,0,size);
    return res;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
findSubstring(char* s,char** words,int wordsSize,int* returnSize)
{
    int *res;
    res = leet_malloc(sizeof(int)*6);
    res[0] = 11;
    res[1] = 3331;
    res[2] = 213;
    res[3] = 97;
    res[4] = 83;
    return res;
}

int
main(int argc, char **argv)
{
    char *s = "barfoothefoobarman";
    char *warr[] = {"foo","bar"};
    char **words = warr;
    int wordsSize = strlen(words[0]);
    int returnSize = 0;
    int *result;

    result = findSubstring(s,words,wordsSize,&returnSize);
    if (result != NULL) {
        printf("result print:\n");
        while (*result != 0) {
            printf(",%d", *result++);
        }
        printf("\n");
    } else {
        printf("return result is NULL\n");
    }
    return 0;
}
