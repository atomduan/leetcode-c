/**
 * Given two non-negative integers num1 and num2 represented as strings, 
 *       return the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0 itself.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

#include <linux_config.h>

#define leet_ctoi(c)  c-48
#define leet_itoc(i)  i+48

inline void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

char*
multiply_deci(char *num, char *sig)
{
    char *res, *tmp, *np = num;
    int sigv, crgv, mulr, num_size, i=0,j=0;
    int dsts=0, ssts=0;
    
    for (num_size=0; *np!='\0'; np++, num_size++); np--;
    res = leet_malloc(num_size+1);
    tmp = leet_malloc(num_size+1);

    sigv = leet_ctoi(*sig);
    do {
        crgv = leet_ctoi(*np--); 
        mulr = crgv*sigv + dsts;
        dsts = mulr/10;  
        ssts = mulr%10;
        tmp[i++] = leet_itoc(ssts);
    } while(i<num_size);

    if (dsts > 0)
        tmp[i] = leet_itoc(dsts);

    for (i=num_size,j=0; i>=0; i--) {
        if (tmp[i]=='\0') continue;
        res[j++] = tmp[i];
    }
    free(tmp);
    return res;
}

char*
multiply(char* num1, char* num2)
{
    return multiply_deci("12123412342342142341234123423143241234233", "8"); 
}

/** 
 * TODO need implemented
 */
int
main(int argc,char **argv)
{
    char *num1 = "123";
    char *num2 = "456";
    printf("multiply result is %s\n", multiply(num1, num2)); 
    return 0;
}
