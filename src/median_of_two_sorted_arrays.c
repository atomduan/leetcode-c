/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 */
#include <linux_config.h>
#include <misc_utils.h>

double 
findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int m_index = (nums1Size + nums2Size)/2;        
    int i1 = 0;
    int i2 = 0;
    int is_odd = (nums1Size + nums2Size) % 2;
    int index = 0;
    int m_value = 0;
    int h_value = 0;
    double result = 0.0;
    while (index < (nums1Size + nums2Size)) {
        if (i1 < nums1Size && i2 < nums2Size) {
            if (index == m_index) {
                if (is_odd) {
                    result = (nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2])*1.0;
                    break;
                } else {
                    h_value = nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2];
                    result = (h_value*1.0 + m_value*1.0) / 2;
                    break;
                }
            }
            if (nums1[i1]<nums2[i2]) {
                m_value=nums1[i1++];
            } else {
                m_value=nums2[i2++];
            }
        } else if (i1 < nums1Size) {
            if (index == m_index) {
                if (is_odd) {
                    result = nums1[i1] * 1.0;
                    break;
                } else {
                    h_value = nums1[i1];
                    result = (h_value*1.0 + m_value*1.0) / 2;
                    break;
                }
            }
            m_value=nums1[i1++];
        } else {
            if (index == m_index) {
                if (is_odd) {
                    result = nums2[i2] * 1.0;
                    break;
                } else {
                    h_value = nums2[i2];
                    result = (h_value*1.0 + m_value*1.0) / 2;
                    break;
                }
            }
            m_value=nums2[i2++];
        }
        index++;
    }
    return result;
}

int main(int argc, char **argv) 
{
    int nums1[4] = {1, 2, 3, 5}; 
    int nums1Size = 4; 
    int nums2[3] = {2, 4, 6};
    int nums2Size = 3;
    double res = 0.0;
    res = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("the result is %f\n", res);
    return 0;
}
