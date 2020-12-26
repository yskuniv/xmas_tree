#include <busy.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUSY_DEVICE_PATH "/dev/busy"

void do_busy(u_int64_t count)
{
    volatile u_int64_t i;

    for (i = 0; i < count; i++)
        ;
}

int do_busy_in_kernel(size_t count)
{
    int fd;

    fd = open(BUSY_DEVICE_PATH, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    read(fd, NULL, count);

    close(fd);

    return 0;
}
