/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.
 * 
 * Example 1:
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * Example 5:
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

#include <linux_config.h>

char *sig[10] = {"Z", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char *des[10] = {"Z", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char *had[10] = {"Z", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char *thu[10] = {"Z", "M", "MM", "MMM"};

static int
get_value(char *token)
{
    if(0==strncmp(token,"III",strlen("III"))) return 3;
    if(0==strncmp(token,"II",strlen("II"))) return 2;
    if(0==strncmp(token,"I",strlen("I"))) return 1;

    if(0==strncmp(token,"IV",strlen("IV"))) return 4;
    if(0==strncmp(token,"VIII",strlen("VIII"))) return 8;
    if(0==strncmp(token,"VII",strlen("VII"))) return 7;
    if(0==strncmp(token,"VI",strlen("VI"))) return 6;
    if(0==strncmp(token,"V",strlen("V"))) return 5;

    if(0==strncmp(token,"IX",strlen("IX"))) return 9;
    if(0==strncmp(token,"XXX",strlen("XXX"))) return 30;
    if(0==strncmp(token,"XX",strlen("XX"))) return 20;
    if(0==strncmp(token,"X",strlen("X"))) return 10;

    if(0==strncmp(token,"XL",strlen("XL"))) return 40;
    if(0==strncmp(token,"LXXX",strlen("LXXX"))) return 80;
    if(0==strncmp(token,"LXX",strlen("LXX"))) return 70;
    if(0==strncmp(token,"LX",strlen("LX"))) return 60;
    if(0==strncmp(token,"L",strlen("L"))) return 50;

    if(0==strncmp(token,"XC",strlen("XC"))) return 90;
    if(0==strncmp(token,"CCC",strlen("CCC"))) return 300;
    if(0==strncmp(token,"CC",strlen("CC"))) return 200;
    if(0==strncmp(token,"C",strlen("C"))) return 100;

    if(0==strncmp(token,"CD",strlen("CD"))) return 400;
    if(0==strncmp(token,"DCCC",strlen("DCCC"))) return 800;
    if(0==strncmp(token,"DCC",strlen("DCC"))) return 700;
    if(0==strncmp(token,"DC",strlen("DC"))) return 600;
    if(0==strncmp(token,"D",strlen("D"))) return 500;

    if(0==strncmp(token,"CM",strlen("CM"))) return 900;
    if(0==strncmp(token,"MMM",strlen("MMM"))) return 3000;
    if(0==strncmp(token,"MM",strlen("MM"))) return 2000;
    if(0==strncmp(token,"M",strlen("M"))) return 1000;
    return 0;
}

int
romanToInt(char* s)
{
    char *p = s;
    int sum,i,n=0;
    char *token=NULL;

    for (i=3; i>=0; i--) {
        token = thu[i];
        n=strncmp(token, p, strlen(token));
        if (n == 0) {
            sum += get_value(token);
            p += strlen(token);
        }
    }

    for (i=9; i>=0; i--) {
        token = had[i];
        n=strncmp(token, p, strlen(token));
        if (n == 0) {
            sum += get_value(token);
            p += strlen(token);
        }
    }

    for (i=9; i>=0; i--) {
        token = des[i];
        n=strncmp(token, p, strlen(token));
        if (n == 0) {
            sum += get_value(token);
            p += strlen(token);
        }
    }

    for (i=9; i>=0; i--) {
        token = sig[i];
        printf("token is %s, p is %s\n", token, p);
        n=strncmp(token, p, strlen(token));
        if (n == 0) {
            sum += get_value(token);
            p += strlen(token);
        }
    }
    return sum;
}

int
main(int argc,char **argv)
{
    //printf("romanToInt %d\n", romanToInt("MCMXCIV"));
    printf("romanToInt %d\n", romanToInt("III"));
    return 0;
}
