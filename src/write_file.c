/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 * Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *   return [0, 1].
 *  Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <let_config.h>

int
main(int argc, char **argv)
{
    FILE *fp;
    char str[100];
    int i=0;
    if ((fp=fopen("/tmp/test.txt","a+")) == NULL) {
        printf("cannot open the file\n");
        exit(0);
    }
    printf("please input a string:\n");
    gets(str);
    while (str[i] != '!') {
       if (str[i]>='a' && str[i]<='z') {
            str[i] = str[i] -32;
            fputc(str[i], fp);
       }
       i++;
    }
    fclose(fp);
    return 0;
}
