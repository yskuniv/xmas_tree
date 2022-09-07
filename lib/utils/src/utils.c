#include <utils.h>
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sched.h>

void bind_on_cpu(int cpu)
{
    cpu_set_t cpu_set;

    CPU_ZERO(&cpu_set);
    CPU_SET(cpu, &cpu_set);

    sched_setaffinity(0, sizeof(cpu_set_t), &cpu_set);
}

int abs(int x)
{
    return (x >= 0) ? x : -x;
}
