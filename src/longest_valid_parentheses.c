/**
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * Example 1:
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 *
 * Example 2:
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 *
 */
#include <linux_config.h>

int
parenthese_scan(char *s)
{
    int count = 0, index = 0, res = 0, last = 0;
    char *ts = s;
    while (*ts != '\0') {
        if (*ts == '(') {
            count++;
        } else
        if (*ts == ')') {
            count--;
        }
        if (count < 0)  {
            index++;
            goto result_fin;
        }
        if (count == 0) {
            res += (index - last + 1);
            last = index+1;
        }
        ts++; index++;
    }
result_fin:
    return res;
}

int
longestValidParentheses(char* s)
{
    int max = 0, size = 0;
    char *ts = s;
    while (*ts != '\0') {
        size = parenthese_scan(ts);
        max = size > max ? size : max;
        ts += size > 0 ? size : 1;
    }
    return max;
}

int
main(int argc,char **argv)
{
    char *s = ")()())";
    //char *s = "(()";
    //char *s = "()((())()";
    printf("result is %d\n",longestValidParentheses(s));
    return 0;
}
