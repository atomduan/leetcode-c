#include <linux_config.h>

#define RES_NANO_SEC    1000000000
#define RES_MICR_SEC    1000000
#define RES_MILI_SEC    1000

#define TEST_FOO        100
#define TEST_BAR        TEST_FOO


typedef struct timespec leet_timespec_t;


unsigned long
leet_time_mval(leet_timespec_t *rct,
        leet_timespec_t *old);

void
leet_time_mono(leet_timespec_t *ts);
