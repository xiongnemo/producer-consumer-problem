#ifndef BUFFER_H
#define BUFFER_H

#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct buffer
{
    // semaphore mutex
    pthread_mutex_t lock;
    // semaphore can_be_written
    pthread_cond_t can_be_written;
    // semaphore can_be_read
    pthread_cond_t can_be_read;

    // real data
    int *data;
    // size of real data
    int size;
    // current element count
    int element_count;
    // read pointer
    int read_pos;
    // write pointer
    int write_pos;
} buffer_t;

// create a buffer struct with given size
buffer_t *create_buffer(int size);

// free a buffer
void free_buffer(buffer_t *buffer_to_free);

// print out buffer contents and pointers
void print_out_buffer_contents(buffer_t *buffer);

// is buffer empty?
bool is_buffer_empty(buffer_t *buffer);

// is buffer full?
bool is_buffer_full(buffer_t *buffer);

// put element into buffer
// this is a write operation.
// read sequentially
void put_into_buffer(buffer_t *buffer, int element);

// get element from index in buffer
// this is a read operation.
// write sequentially
int read_from_buffer(buffer_t *buffer);

#endif