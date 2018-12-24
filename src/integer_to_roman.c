/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. 
 * Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right. However, 
 * the numeral for four is not IIII. Instead, the number four is written as IV. 
 * Because the one is before the five we subtract it making four. 
 * The same principle applies to the number nine, which is written as IX. 
 * There are six instances where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Example 1:
 * Input: 3
 * Output: "III"
 *
 * Example 2:
 * Input: 4
 * Output: "IV"
 *
 * Example 3:
 * Input: 9
 * Output: "IX"
 *
 * Example 4:
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 *
 * Example 5:
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

#include <linux_config.h>

char *sig[10] = {"Z", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char *des[10] = {"Z", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char *had[10] = {"Z", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char *thu[10] = {"Z", "M", "MM", "MMM"};

char *
intToRoman(int num)
{
    char *res = malloc(1024);
    memset(res, 0, 1024);
    char *p = res;
    int thu_idx = num/1000;
    if (thu_idx > 0) {
        memcpy(p,thu[thu_idx], strlen(thu[thu_idx]));
        p = p+strlen(thu[thu_idx]);
    }
    num = num%1000;

    int had_idx = num/100;
    if (had_idx > 0) {
        memcpy(p,had[had_idx], strlen(had[had_idx]));
        p = p+strlen(had[had_idx]);
    }
    num = num%100;

    int des_idx = num/10;
    if (des_idx > 0) {
        memcpy(p,des[des_idx], strlen(des[des_idx]));
        p = p+strlen(des[des_idx]);
    }
    num = num%10;

    int sig_idx = num;
    if (sig_idx > 0) {
        memcpy(p,sig[sig_idx], strlen(sig[sig_idx]));
        p = p+strlen(sig[sig_idx]);
    }
    return res;
}

int
main(int argc,char **argv)
{
    printf("intToRoman %s\n", intToRoman(1994));
    return 0;
}
