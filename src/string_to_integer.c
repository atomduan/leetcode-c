/**
 * Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
 * Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
 * and interprets them as a numerical value.
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 * Only the space character ' ' is considered as whitespace character.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1].
 * If the numerical value is out of the range of representable values,
 * INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 * Example 1:
 * Input: "42"
 * Output: 42
 *
 * Example 2:
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus sign.
 *              Then take as many numerical digits as possible, which gets 42.
 *
 * Example 3:
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
 *
 * Example 4:
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a numerical
 *              digit or a +/- sign. Therefore no valid conversion could be performed.
 *
 * Example 5:
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
 *             Thefore INT_MIN (−231) is returned.
 */
#include <let_config.h>

int
myAtoi(char* str)
{
    int INIT_STAT = 0;
    int NUM_STAT = 2;
    int FIN_STAT = 3;

    char * ss = malloc(strlen(str)+3);
    memset(ss, 0 , strlen(str)+3);
    memcpy(ss, str, strlen(str));
    ss[strlen(str)] = 'z';
    ss[strlen(str)+1] = 'z';

    int stat = INIT_STAT;
    int result = 0;
    int test = 0;
    int sign = 1;
    int curr = 0;

    char *p = NULL;
    for (p=ss ; *p!='\0'; p++) {
        if(INIT_STAT == stat) {
            if (*p == ' ') {
                continue;
            }
            if (*p == '-') {
                sign = -1;
                stat = NUM_STAT;
                continue;
            }
            if (*p == '+') {
                stat = NUM_STAT;
                continue;
            }
            if (*p >= 48 && *p <= 57) {
                curr = (*p - 48);
                stat = NUM_STAT;
                continue;
            }
            stat = FIN_STAT;
            continue;
        }
        if(NUM_STAT == stat) {
            //test integer boundary...
            test = result*10 + curr;
            if (((test-curr)/10 == result) && (test>=0)) {
                result = test;
            } else {
                return sign>0 ? INT_MAX: INT_MIN;
                continue;
            }
            if (*p >= 48 && *p <= 57) {
                curr = (*p - 48);
                continue;
            } else {
                stat = FIN_STAT;
                continue;
            }
            stat = FIN_STAT;
            continue;
        }
        if(FIN_STAT == stat) {
            result = result * sign;
            break;
        }
    }
    return result;
}

int
main(int argc,char **argv)
{
    char *p = "   -42";
    printf("result is %d\n", myAtoi(p));
}
