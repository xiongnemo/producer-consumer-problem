// can be compiled under wsl
#include <unistd.h>
#include "producers.h"
#include "consumers.h"
#include "variables.h"

int buffer_size, producer_quantity, consumer_quantity;

int main(void)
{
    print_time_information("main");
    printf("Main started.\n\n");

    // init
    srand((unsigned)time(NULL));

    // prompt for input
    printf("Input your buffer size, quantity of the producer and consumer: ");
    scanf("%d %d %d", &buffer_size, &producer_quantity, &consumer_quantity);
    printf("\n\n");
    print_time_information("main");
    printf("Get input: buffer_size = %d, producer_quantity = %d, consumer_quantity = %d.\n\n", buffer_size, producer_quantity, consumer_quantity);
    if (buffer_size <= 0 || producer_quantity <= 0 || consumer_quantity <= 0)
    {
        print_error_information("main", "Input doesn't fulfill requirements.");
        exit_("main", -2);
    }
    buffer_t *real_buffer = create_buffer(buffer_size);
    print_out_buffer_contents(real_buffer);
    producer_t *producer_list = create_producer_list(producer_quantity);
    consumer_t *consumer_list = create_consumer_list(consumer_quantity);

    // produce and consume
    create_and_run_producers(producer_list, real_buffer);
    create_and_run_consumers(consumer_list, real_buffer);
    join_producer_threads(producer_list);
    join_consumer_threads(consumer_list);

    sleep(1);
    // clean up
    print_time_information("clean_up");
    printf("Begin to cleanup\n\n");
    free_producer_list(producer_list);
    free_consumer_list(consumer_list);
    print_out_buffer_contents(real_buffer);
    free_buffer(real_buffer);
    print_time_information("clean_up");
    printf("cleanup finishes.\n\n");
    print_time_information("main");
    printf("Bye.\n\n");
    return 0;
}