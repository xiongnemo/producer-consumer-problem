#ifndef CONSUMERS_H
#define CONSUMERS_H

#include "buffer.h"
#include "utils.h"
#include "variables.h"


typedef struct consumer
{
    pthread_t *thread_id;
    int size;
} consumer_t;

// create a consumer struct with given size
consumer_t *create_consumer_list(int size);

// free a consumer list
void free_consumer_list(consumer_t *consumer_to_free);

// create consumer then detach and run
void create_and_run_consumers(consumer_t *consumer_list, buffer_t *buffer);

void join_consumer_threads(consumer_t *consumer_list);

// consume
// pthread_create needs a void*
void *consume(void *buffer);

#endif