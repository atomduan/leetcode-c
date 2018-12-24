#include <linux_config.h>

int
main(int argc,char **argv)
{
    int i=1,j=3,k=0;
    char *s = "abc";
    printf("print i:%d, j:%d, k:%d  \n", i,j,k);
    printf("strlen of abc is %ld\n", strlen(s));
    return 0;
}
