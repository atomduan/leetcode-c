#include <linux_config.h>

int
check_bitmap_bk(int *bitmap, int index) {
    int res = 0, bi, *buck, offset, bit_flag;
    //TODO need optimize, should we do not use divide
    //TODO has problem, bigEndiean
    bi = index / (sizeof(int)*8); 
    offset = index % (sizeof(int)*8);
    buck = bitmap+bi;
    bit_flag = 0x1 << offset; 
    if (!(*buck & bit_flag)) {
        *buck = *buck | bit_flag;
        res = 1;
    }
    return res;
}
