#include "consumers.h"

consumer_t *create_consumer_list(int size)
{
    print_time_information("create_consumer_list");
    printf("consumer list creation starts. ");
    printf("Size to allocate: %d\n\n", size);

    // allocate consumer list
    consumer_t *new_consumer_list = (consumer_t *)malloc(sizeof(consumer_t));
    if (new_consumer_list == NULL)
    {
        print_error_information("create_consumer_list", "Can't allocated memory for consumer list.");
        exit(-1);
    }
    // initialize data
    new_consumer_list->thread_id = (pthread_t *)malloc(sizeof(pthread_t) * size);
    if (new_consumer_list->thread_id == NULL)
    {
        print_error_information("create_consumer_list", "Can't allocated memory for consumers' thread id.");
        exit(-1);
    }
    new_consumer_list->size = size;

    print_time_information("create_consumer_list");
    printf("consumer list creation ends.\n\n");
    return new_consumer_list;
}

void free_consumer_list(consumer_t *consumer_to_free)
{
    print_time_information("free_consumer");
    printf("Start to free the consumer list...\n\n");

    // free buffer
    free(consumer_to_free->thread_id);
    free(consumer_to_free);

    print_time_information("free_consumer");
    printf("The consumer list is successfully freed.\n\n");
}

void create_and_run_consumers(consumer_t *consumer_list, buffer_t *buffer)
{
    int consumer_count = consumer_list->size;
    for (int i = 0; i < consumer_count; i++)
    {
        pthread_create(&(consumer_list->thread_id[i]), NULL, consume, buffer);
        print_time_information("create_and_run_consumers");
        printf("created thread with id %#lx for consumer\n\n", consumer_list->thread_id[i]);
    }
}

void join_consumer_threads(consumer_t *consumer_list)
{
    for (int i = 0; i < PRODUCER_QUANTITY; i++)
    {
        print_time_information("join_consumer_threads");
        printf("consumer thread id %#lx will be joined\n\n", consumer_list->thread_id[i]);
        pthread_join(consumer_list->thread_id[i], NULL);
    }
}

void *consume(void *buffer)
{
    // https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
    // https://zh.wikipedia.org/wiki/%E7%94%9F%E4%BA%A7%E8%80%85%E6%B6%88%E8%B4%B9%E8%80%85%E9%97%AE%E9%A2%98
    // no void*
    buffer_t *buffer_ptr = (buffer_t *)buffer;
    // long long long loop
    for (int i = 0; i < CONSUMER_OPERATION_COUNT; i++)
    {
        pthread_t self_tid;
        self_tid = pthread_self();
        // try to get lock
        pthread_mutex_lock(&(buffer_ptr->lock));
        // wait till there is something in the buffer!
        while (is_buffer_empty(buffer))
        {
            pthread_cond_wait(&(buffer_ptr->can_be_read), &(buffer_ptr->lock));
        }
        // get value from buffer
        print_time_information("consumer");
        printf("thread %#lx prepare to read\n\n", self_tid);
        int value = read_from_buffer(buffer_ptr);
        print_time_information("consumer");
        printf("thread %#lx got %d\n\n", self_tid, value);
        // after one value is read, the buffer can be written!
        pthread_cond_signal(&(buffer_ptr->can_be_written));
        // release lock
        pthread_mutex_unlock(&(buffer_ptr->lock));
    }
    return NULL;
}