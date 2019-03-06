/*
 * Given a string s, find the longest palindromic substring in s.
 * You may assume that the maximum length of s is 1000.
 * Example 1:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 * Example 2:
 * Input: "cbbd"
 * Output: "bb"
 */
#include <linux_config.h>

static char *
scan_eve_palindrome(char *s,int *maxp)
{
    char * l=s;
    char * r=s+1;
    char * lt;
    char * lr;
    char * res;
    int length;
    while (1) {
        lt = l, lr = r;
        do {
             if(*lt - *lr == 0) {
                 length += 2; lt--, lr++;
             } else {
                 break;
             }
        } while(*lt!='\0' && *lr!='\0');
        if (length > *maxp) {
            res=lt+1, *maxp=length;
        }
        length=0, l++, r++;
        if (*r == '\0') break;
    }
    return res;
}

static char *
scan_odd_palindrome(char *s,int *maxp)
{
    char * m = s;
    char * lt;
    char * lr;
    char * res;
    int length = -1;
    while (1) {
        lt = m;
        lr = m;
        do {
             if(*lt - *lr == 0) {
                 length += 2; lt--, lr++;
             } else {
                 break;
             }
        } while(*lt!='\0' && *lr!='\0');
        if (length > *maxp) {
            res=lt+1, *maxp=length;
        }
        length=-1, m++;
        if (*m == '\0') break;
    }
    return res;
}

char*
longestPalindrome(char* s)
{
    char *ss = malloc(strlen(s)+2);
    char *eve = NULL;
    char *odd = NULL;
    int eve_len=0, odd_len=0;
    char *result = NULL;
    int len = 0;
    int max = 0;

    if (strlen(s) <= 1) return s;

    memset(ss, 0, strlen(s)+2);
    memcpy(ss+1, s, strlen(s));

    eve = scan_eve_palindrome(ss+1, &max), eve_len = max;
    max = 0;
    odd = scan_odd_palindrome(ss+1, &max), odd_len = max;

    result = eve_len > odd_len ? eve : odd;
    len = eve_len > odd_len ? eve_len : odd_len;
    result[len] = '\0';
    return result;
}

int
main(int argc,char **argv)
{
    char *s = "cbbd";
    printf("result is %s\n", longestPalindrome(s));
    return 0;
}
