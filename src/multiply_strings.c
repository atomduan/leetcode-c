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

#define leet_ctoi(c)    c-48
#define leet_itoc(i)    i+48
#define TMP_SIZE        1024*4 

inline void *
leet_malloc(size_t size)
{
    void *res = malloc(size);
    memset(res,0,size);
    return res;
}

char*
multiply_deci_shift(char *num, char *tmp, int shift_step)
{
    char *res, *np=num;
    int num_size, i;
    memset(tmp,0,TMP_SIZE);
    for (num_size=0; *np!='\0'; np++, num_size++);
    res = leet_malloc(num_size+1+shift_step);
    for (i=0; i<num_size; i++) {
        res[i] = num[i];
    }
    for (i=0; i<shift_step; i++) {
        res[num_size+i] = '0';
    }
    return res;
}


char*
multiply_deci_sigal(char *num, char *sig, char *tmp)
{
    char *res, *np=num;
    int sigv, crgv, mulr, num_size, i=0, j=0;
    int dsts=0, ssts=0;

    memset(tmp,0,TMP_SIZE);
    for (num_size=0; *np!='\0'; np++, num_size++); np--;
    res = leet_malloc(num_size+1);

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
    return res;
}

char*
sum_two_layer_nums(char *upper, char *lower, char *tmp)
{
    int u_sz=0, l_sz=0, i, j, ts, t=0, num_size=0;
    int dsts=0, ssts=0;
    char *unp=upper, *lnp=lower, *res; 
    for (;*unp!='\0'; unp++) u_sz++;
    for (;*lnp!='\0'; lnp++) l_sz++;

    memset(tmp,0,TMP_SIZE);
    i = u_sz - 1;
    j = l_sz - 1;
    while (1) {
        if (i >=0 && j >=0) {
            ts = leet_ctoi(upper[i--])+leet_ctoi(lower[j--])+dsts;
        } else
        if (i >=0 && j < 0) {
            ts = leet_ctoi(upper[i--])+dsts;
        } else
        if (i <0 && j >= 0) {
            ts = leet_ctoi(lower[j--])+dsts;
        } else
        if (i <0 && j < 0) {
            if (dsts > 0) tmp[t++] = leet_itoc(dsts);
            break;
        }
        dsts = ts/10;
        ssts = ts%10;
        tmp[t++] = leet_itoc(ssts);
    }
    
    num_size = (u_sz>l_sz? u_sz:l_sz)+1;
    res = leet_malloc(num_size);
    for (i=num_size,j=0; i>=0; i--) {
        if (tmp[i]=='\0') continue;
        res[j++] = tmp[i];
    }
    return res;
}

char*
multiply(char* num1, char* num2)
{
    char *tmp = leet_malloc(TMP_SIZE);
    char *res=NULL, *rtp, *rtp_tmp, *res_tmp, *n2p;
    int num2_sz=0, i, shift_step=0;
    for (n2p=num2; *n2p!='\0'; n2p++) num2_sz++;
    for (i=num2_sz-1; i>=0; i--, shift_step++) {
        rtp = multiply_deci_sigal(num1,&num2[i],tmp);
        if (res == NULL) {
            res = rtp;
        } else {
            rtp_tmp = multiply_deci_shift(rtp,tmp,shift_step);
            res_tmp = sum_two_layer_nums(res,rtp_tmp,tmp);
            free(rtp); free(res); free(rtp_tmp);
            res = res_tmp;
        }
    }
    free(tmp);
    return res;
}

/** 
 * TODO need implemented
 */
int
main(int argc,char **argv)
{
    char *num1 = "12312";
    char *num2 = "456";
    printf("multiply result is %s\n", multiply(num1, num2)); 
    return 0;
}
