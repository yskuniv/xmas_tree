#ifndef _BUSY_H
#define _BUSY_H

#include <sys/types.h>

void do_busy(u_int32_t count);
int do_busy_in_kernel(u_int32_t count);

#endif
