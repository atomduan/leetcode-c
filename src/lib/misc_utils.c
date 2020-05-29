#include <let_config.h>
#include <misc_utils.h>


/*
 * A micro seconds diff will return
 */
unsigned long
leet_time_mval(leet_timespec_t *rct,leet_timespec_t *old)
{
    unsigned long res = 0;
    /* 
    unsigned long sec_diff = 0;

    unsigned long nr = 0;
    unsigned long no = 0;
    if (rct->tv_sec >= old->tv_sec) {
        sec_diff = rct->tv_sec - old->tv_sec;
        nr = sec_diff * RES_NANO_SEC + rct->tv_nsec;
        no = old->tv_nsec;
        res = ((nr-no)*RES_MILI_SEC)/RES_NANO_SEC;
    }
    */
    return res;
}


void
leet_time_mono(leet_timespec_t *ts)
{
    /*
    clock_gettime(CLOCK_MONOTONIC_COARSE, ts);
    */
}
