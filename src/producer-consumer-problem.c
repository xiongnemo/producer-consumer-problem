// can be compiled under wsl
#include <unistd.h>
#include "producers.h"
#include "consumers.h"
#include "variables.h"

int main(void)
{
    print_time_information("main");
    printf("Main started.\n\n");

    // init
    srand((unsigned)time(NULL));
    buffer_t *real_buffer = create_buffer(BUFFER_SIZE);
    print_out_buffer_contents(real_buffer);
    producer_t *producer_list = create_producer_list(PRODUCER_QUANTITY);
    consumer_t *consumer_list = create_consumer_list(CONSUMER_QUANTITY);

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