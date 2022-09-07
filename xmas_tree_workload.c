#include <busy.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <utils.h>

#define TREE_WIDTH_MAX 16
#define TREE_RATE_MAX 256U

#define MAX_NUM_THREADS TREE_WIDTH_MAX

struct tree_thread_args
{
    int th_num;
    int tree_width;
};

void do_own_part_of_tree(const int tree_rate)
{
    for (;;)
    {
        do_busy((65536U / TREE_RATE_MAX) * tree_rate);
        do_busy_in_kernel((65536U / TREE_RATE_MAX) * (TREE_RATE_MAX - tree_rate));
    }
}

void *tree_thread(void *arg)
{
    const struct tree_thread_args *const th_args = (struct tree_thread_args *)arg;
    const int th_num = th_args->th_num;
    const int tree_width = th_args->tree_width;

    bind_on_cpu(th_num);

    const int c = (tree_width + 2) / 2;
    const int d = abs(c - (th_num + 1));
    const int tree_rate = (c - d) * TREE_RATE_MAX / c;

    do_own_part_of_tree(tree_rate);

    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fputs("Error: tree width not specified\n", stderr);
        exit(1);
    }
    else if (argc > 2)
    {
        fputs("Error: too many arguments\n", stderr);
        exit(1);
    }

    const int tree_width = atoi(argv[1]);

    if (tree_width <= 0 || tree_width > TREE_WIDTH_MAX)
    {
        fputs("Error: illegal tree width specified\n", stderr);
        exit(1);
    }

    const int num_threads = tree_width;

    pthread_t threads[MAX_NUM_THREADS];
    struct tree_thread_args th_args[MAX_NUM_THREADS];

    for (int i = 0; i < num_threads; i++)
    {
        th_args[i].th_num = i;
        th_args[i].tree_width = tree_width;

        pthread_create(&threads[i], NULL, tree_thread, &th_args[i]);
    }

    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
