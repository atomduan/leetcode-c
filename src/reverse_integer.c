/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 * Input: 123
 * Output: 321
 *
 * Example 2:
 * Input: -123
 * Output: -321
 *
 * Example 3:
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the
 * 32-bit signed integer range: [−231,  231 − 1].
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */
#include <let_config.h>

static int
reverse(int x)
{
    int truck = 0;
    int xbase = x;
    int result = 0;
    int limit = ~(1<<31);
    if (x > (int)limit || x < 1-(int)limit) return 0;
    limit = limit/10;
    while(1) {
        truck = xbase % 10;
        if ((result>0&&result>limit) || (result<0&&result<-1*limit)) {
            return 0;
        } else {
            result = result*10 + truck;
        }
        xbase = xbase / 10;
        if (xbase == 0) break;
    }
    return result;
}

int
main(int argc,char **argv)
{
    printf("reverse is %d\n",reverse(1534236469));
    return 0;
}
