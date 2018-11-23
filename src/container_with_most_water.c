/* *
 * Given n non-negative integers a1, a2, ..., an , 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line 
 * i is at (i, ai) and (i, 0). Find two lines, 
 * which together with x-axis forms a container, 
 * such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 * Example:
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * */
#include <linux_config.h>


int 
maxArea(int* height, int heightSize)
{
    int weigth,high,max,value = 0;
    int i,j = 0;
    for (i=0; i<heightSize; i++) {
        for (j=heightSize-1; j>i; j--) {
            weigth = j-i; 
            high = height[i] < height[j] ? height[i] : height[j];  
            value = high * weigth;
            max = value > max ? value : max;
        }
    }
    return max;        
}


int main(int argc, char **argv) 
{
    int contails[4] = {1, 2, 3, 5}; 
    printf("max value is %d\n", maxArea(contails, sizeof(contails)/sizeof(int)));
    return 0;
}
