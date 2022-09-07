#include <busy.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUSY_DEVICE_PATH "/dev/busy"

void do_busy(u_int32_t count)
{
    for (volatile u_int32_t i = 0; i < count; i++)
        ;
}

int do_busy_in_kernel(u_int32_t count)
{
    const int fd = open(BUSY_DEVICE_PATH, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return -1;
    }

    read(fd, NULL, (size_t)count);

    close(fd);

    return 0;
}
