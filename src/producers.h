#ifndef PRODUCERS_H
#define PRODUCERS_H

#include "buffer.h"
#include "utils.h"
#include "variables.h"

typedef struct producer
{
    pthread_t *thread_id;
    int size;
} producer_t;

// create a producer struct with given size
producer_t *create_producer_list(int size);

// free a producer list
void free_producer_list(producer_t *producer_to_free);

// create producer then detach and run
void create_and_run_producers(producer_t *producer_list, buffer_t *buffer);

void join_producer_threads(producer_t *producer_list);

// produce
// pthread_create needs a void*
void *produce(void *buffer);

#endif