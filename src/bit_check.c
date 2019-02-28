#include <linux_config.h>

int
main(int argc,char **argv)
{
    int i;
    int target = 1;
    int needle = 0x1;
    int count = 0;
    for (i=0; i<31; i++) {
        if ((target & needle) != 0) {
            count++;
        }
        needle = needle << 1;
        printf("needle is %d\n", needle);
    }
    if ((target & needle) != 0) {
        count++;
    }
    printf("result is %d\n", count);
    return 0;
}

