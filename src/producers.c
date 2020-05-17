#include "producers.h"

producer_t *create_producer_list(int size)
{
    print_time_information("create_producer_list");
    printf("Producer list creation starts. ");
    printf("Size to allocate: %d\n\n", size);

    // allocate producer list
    producer_t *new_producer_list = (producer_t *)malloc(sizeof(producer_t));
    if (new_producer_list == NULL)
    {
        print_error_information("create_producer_list", "Can't allocated memory for producer list.");
        exit_("create_producer_list", -1);
    }
    // initialize data
    new_producer_list->thread_id = (pthread_t *)malloc(sizeof(pthread_t) * size);
    if (new_producer_list->thread_id == NULL)
    {
        print_error_information("create_producer_list", "Can't allocated memory for producers' thread id.");
        exit_("create_producer_list", -1);
    }
    new_producer_list->size = size;

    print_time_information("create_producer_list");
    printf("Producer list creation ends.\n\n");
    return new_producer_list;
}

void free_producer_list(producer_t *producer_to_free)
{
    print_time_information("free_producer");
    printf("Start to free the producer list...\n\n");

    // free buffer
    free(producer_to_free->thread_id);
    free(producer_to_free);

    print_time_information("free_producer");
    printf("The producer list is successfully freed.\n\n");
}

void create_and_run_producers(producer_t *producer_list, buffer_t *buffer)
{
    int producer_count = producer_list->size;
    for (int i = 0; i < producer_count; i++)
    {
        pthread_create(&(producer_list->thread_id[i]), NULL, produce, buffer);
        print_time_information("create_and_run_producers");
        printf("created thread with id ");
        printf(PTHREAD_FORMAT, producer_list->thread_id[i]);
        printf(" for producer\n\n");
    }
}

void join_producer_threads(producer_t *producer_list)
{
    int producer_count = producer_list->size;
    for (int i = 0; i < producer_count; i++)
    {
        print_time_information("join_producer_threads");
        printf("producer thread id ");
        printf(PTHREAD_FORMAT, producer_list->thread_id[i]);
        printf(" will be joined\n\n");
        pthread_join(producer_list->thread_id[i], NULL);
    }
}

void *produce(void *buffer)
{
    // https://en.wikipedia.org/wiki/Producer%E2%80%93producer_problem
    // https://zh.wikipedia.org/wiki/%E7%94%9F%E4%BA%A7%E8%80%85%E6%B6%88%E8%B4%B9%E8%80%85%E9%97%AE%E9%A2%98
    // no void*
    buffer_t *buffer_ptr = (buffer_t *)buffer;
    extern int consumer_quantity;
    // long long long loop
    for (int i = 0; i < K * consumer_quantity; i++)
    {
        pthread_t self_tid;
        self_tid = pthread_self();
        // try to get lock
        pthread_mutex_lock(&(buffer_ptr->lock));
        // wait till there is somewhere empty in the buffer!
        while (is_buffer_full(buffer))
        {
            pthread_cond_wait(&(buffer_ptr->can_be_written), &(buffer_ptr->lock));
        }
        // write value to buffer
        int value = rand() % 1000;
        print_time_information("producer");
        printf("thread ");
        printf(PTHREAD_FORMAT, self_tid);
        printf(" prepare to write %d\n\n", value);
        put_into_buffer(buffer_ptr, value);
        print_time_information("producer");
        printf("thread ");
        printf(PTHREAD_FORMAT, self_tid);
        printf(" successfully wrote %d\n\n", value);
        // after one value is written, the buffer can be read!
        pthread_cond_signal(&(buffer_ptr->can_be_read));
        // release lock
        pthread_mutex_unlock(&(buffer_ptr->lock));
    }
    return NULL;
}