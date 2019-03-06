#include <linux_config.h>

#define BITS_PER_BYTE       8
#define DIV_ROUND_UP(n, d)  (((n) + (d) - 1) / (d))
#define BITS_TO_LONGS(nr)   DIV_ROUND_UP(nr, BITS_PER_BYTE * sizeof(long))

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

inline void
bitmap_zero(unsigned long *dst, unsigned int nbits)
{
    unsigned int len = BITS_TO_LONGS(nbits) * sizeof(unsigned long);
    memset(dst, 0, len);
}

