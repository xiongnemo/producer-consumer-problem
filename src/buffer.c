#include "buffer.h"
#include "utils.h"
#include "variables.h"

buffer_t *create_buffer(int size)
{
    print_time_information("create_buffer");
    printf("Buffer initialization starts. ");
    printf("Size to allocate: %d\n\n", size);

    // allocate buffer
    buffer_t *new_buffer = (buffer_t *)malloc(sizeof(buffer_t));
    if (new_buffer == NULL)
    {
        print_error_information("create_buffer", "Can't allocated memory for buffer struct.");
        exit(-1);
    }

    // initialize semaphores
    pthread_mutex_init(&(new_buffer->lock), NULL);
    pthread_cond_init(&(new_buffer->can_be_written), NULL);
    pthread_cond_init(&(new_buffer->can_be_read), NULL);

    // initialize data
    new_buffer->data = (int *)malloc(sizeof(int) * size);
    if (new_buffer->data == NULL)
    {
        print_error_information("create_buffer", "Can't allocated memory for real data.");
        exit(-1);
    }
    // all 114514 at initialization
    for (int i = 0; i < size; i++)
    {
        new_buffer->data[i] = 114514;
    }
    new_buffer->size = size;
    new_buffer->element_count = 0;
    new_buffer->read_pos = 0;
    new_buffer->write_pos = 0;

    print_time_information("create_buffer");
    printf("Buffer initialization ends.\n\n");
    return new_buffer;
}

void free_buffer(buffer_t *buffer_to_free)
{
    print_time_information("free_buffer");
    printf("Starting to free the buffer...\n\n");

    // free buffer
    free(buffer_to_free->data);
    free(buffer_to_free);

    print_time_information("free_buffer");
    printf("The buffer is successfully freed.\n\n");
}

// indicator
// contents
void print_out_buffer_contents(buffer_t *buffer)
{
    print_time_information("buffer_contents");
    printf("\n");
    const int data_size = buffer->size;
    const int read_pos = buffer->read_pos;
    const int write_pos = buffer->write_pos;
    for (int i = 0; i <= data_size; i++)
    {
        printf("+---------------");
    }
    printf("+\n");
    printf("| Indicator\t");
    for (int i = 0; i < data_size; i++)
    {
        if (i == read_pos && i == write_pos)
        {
            printf("| WR\t\t");
        }
        else if (i == read_pos)
        {
            printf("| R\t\t");
        }
        else if (i == write_pos)
        {
            printf("| W\t\t");
        }
        else
        {
            printf("| \t\t");
        }
    }
    printf("|\n");
    for (int i = 0; i <= data_size; i++)
    {
        printf("+---------------");
    }
    printf("+\n");
    printf("| Contents\t");
    for (int i = 0; i < data_size; i++)
    {
        int temp = buffer->data[i];
        if (temp != 114514)
        {
            printf("| %d\t\t", buffer->data[i]);
        }
        else
        {
            printf("| CLEARED\t");
        }
    }
    printf("|");
    printf("\n");
    for (int i = 0; i <= data_size; i++)
    {
        printf("+---------------");
    }
    printf("+\n");
}

bool is_buffer_empty(buffer_t *buffer)
{
    return (buffer->element_count == 0);
}

bool is_buffer_full(buffer_t *buffer)
{
    return (buffer->element_count == buffer->size);
}

void put_into_buffer(buffer_t *buffer, int element)
{
    pthread_t self_tid;
    self_tid = pthread_self();
    int pos_to_write = buffer->write_pos;
    buffer->data[pos_to_write] = element;
    print_time_information("put_into_buffer");
    printf("thread %#lx writes %d to buffer at pos %d.\n\n", self_tid, element, pos_to_write);
    // update pos
    buffer->write_pos = (pos_to_write + 1) % BUFFER_SIZE;
    (buffer->element_count)++;
    print_out_buffer_contents(buffer);
}

int read_from_buffer(buffer_t *buffer)
{
    pthread_t self_tid;
    self_tid = pthread_self();
    int pos_to_read = buffer->read_pos;
    int value = buffer->data[pos_to_read];
    print_time_information("read_from_buffer");
    printf("thread %#lx gets %d from buffer at pos %d.\n\n", self_tid, value, pos_to_read);
    // clear data at the pos
    buffer->data[pos_to_read] = 114514;
    // update pos
    buffer->read_pos = (pos_to_read + 1) % BUFFER_SIZE;
    (buffer->element_count)--;
    print_out_buffer_contents(buffer);
    return value;
}