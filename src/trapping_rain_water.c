/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 * 
 * Example:
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

#include <linux_config.h>

static void
leet_height_slice(int* height, int heightSize)
{
    int i;
    for (i=0; i<heightSize; i++) {
        height[i] = height[i]-1<0 ? 0:height[i]-1;
    }
}

static int
leet_count_pool_unit(int* height, int heightSize)
{
    int submit_count = 0;
    int commit_count = 0;
    int count_stat=0, i=0, hv;
    for (i=0; i<heightSize; i++) {
        hv = height[i];
        if (count_stat == 0) {
            if (hv > 0) {
                count_stat = 1;
                continue;
            }
        } else {
            if (hv > 0) {
                count_stat = 0;
                commit_count += submit_count;
                submit_count = 0;
                continue;
            } else {
                submit_count++; 
            }
        }
    }
    printf("slice count is %d\n", commit_count);
    return commit_count;
}


int trap(int* height, int heightSize) {
    int res_count = 0;
    int max, i;
    max = INT_MIN;
    for (i=0; i<heightSize; i++) {
        if (height[i] > max) max = height[i];
    }
    for (i=0; i<max; i++) {
        res_count += leet_count_pool_unit(height,heightSize);
        leet_height_slice(height,heightSize);
    }
    return res_count;        
}

int
main(int argc, char ** argv)
{
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(height)/sizeof(int);
    printf("return result is %d\n", trap(height, heightSize));
    return 0;
}
