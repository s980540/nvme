#include "main.h"
#include "thread.h"

foo_ts foo = {.mutex = (PTHREAD_MUTEX_INITIALIZER), .val = 0};

int main(int argc, char *argv[])
{
    printf("ssd_sim\n");
    srand(time(NULL));

    thread_init();
    thread_delete();

    return 0;
}