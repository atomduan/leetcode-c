/* 
 *
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * */
#include <linux_config.h>
#include <misc_utils.h>

struct char_dict {
    char *cp;
    int index;
};

static int hash(char c) {
    return (int) c;
}

int lengthOfLongestSubstring(char* s) 
{
    int slen = strlen(s);
    if (slen == 0) return 0;

    struct char_dict **dict = malloc(sizeof(struct char_dict)*256);
    memset(dict, 0, sizeof(struct char_dict)*256);
    struct char_dict *cv = NULL;

    char *curr = s;
    int curr_index = 0;
    int max = 1;
    int length = 1;
    int begin = 0;

    cv = malloc(sizeof(struct char_dict));
    dict[hash(*curr)] = cv;
    cv->cp = curr;
    cv->index = curr_index;

    while (1) {
        curr++, curr_index++;
        if (curr_index >= slen) break;
        cv = dict[hash(*curr)];
        if (cv == NULL) {
            length++;
            cv = malloc(sizeof(struct char_dict));
            dict[hash(*curr)] = cv;
            cv->cp = curr;
            cv->index = curr_index;
        } else {
            begin = (cv->index+1) > begin ? (cv->index+1):begin;
            length = curr_index - begin + 1;
            cv->cp = curr;
            cv->index = curr_index;
        }
        length > max ? max = length : 0;
    }

    return max;
}

int main(int argc, char **argv)
{
    //char *p = "bbbbbbb";
    //char *p = "abcabcbb";
    char *p = "pwwkew";
    //char *p = "aab";
    //char *p = "abba";
    int res = lengthOfLongestSubstring(p);
    printf("result is %d\n", res);
}
