#ifndef VARIABLES_H
#define VARIABLES_H

// change self-defined variables here!
#define BUFFER_SIZE 8
#define PRODUCER_QUANTITY 2
#define CONSUMER_QUANTITY 4
#define K 2
#define TOTAL_OPERATION_COUNT (CONSUMER_QUANTITY*PRODUCER_QUANTITY*K)
#define PRODUCER_OPERATION_COUNT (K*CONSUMER_QUANTITY)
#define CONSUMER_OPERATION_COUNT (K*PRODUCER_QUANTITY)

#endif