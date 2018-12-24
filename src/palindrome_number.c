/**
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 * 
 * Example 1:
 * Input: 121
 * Output: true
 * 
 * Example 2:
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 * 
 * Example 3:
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 * Follow up:
 * Coud you solve it without converting the integer to a string?
 */
#include <linux_config.h>

static int
isPalindrome(int x) {
    int result = 0;
    int orgx = x;
    if (x < 0) return 0;
    while (1) {
        result = result * 10 + (x % 10);
        x /= 10;
        if (x == 0) break;
    }
    return result == orgx;
}

int
main(int argc,char **argv)
{
    printf("result is %d\n", isPalindrome(1111));
}
