#include <sys/types.h>
#include <pthread.h>
#include <busy.h>
#include "utils.h"

#define TREE_WIDTH 11

#define NUM_THREADS TREE_WIDTH

void do_tree(int tree_rate)
{
    for (u_int64_t i = 0; i < 32768ULL; i++)
    {
        do_busy((65536ULL / 16) * tree_rate);
        do_busy_in_kernel((65536ULL / 16) * (16 - tree_rate));
    }
}

void *tree_thread(void *arg)
{
    const int th_num = *(int *)arg;

    bind_on_cpu(th_num);

    const int c = TREE_WIDTH / 2;
    const int d_ = c - th_num;
    const int d = (d_ >= 0) ? d_ : -d_;
    const int tree_rate = (c - d) * 16 / c;

    do_tree(tree_rate);

    return NULL;
}

int main(void)
{
    pthread_t ths[NUM_THREADS];
    int th_args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        th_args[i] = i;
        pthread_create(&ths[i], NULL, tree_thread, &th_args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(ths[i], NULL);
    }

    return 0;
}
