#ifndef VARIABLES_H
#define VARIABLES_H

// change self-defined variables here!
// currently it is disabled and have no use.
// #define BUFFER_SIZE 8
// #define PRODUCER_QUANTITY 2
// #define CONSUMER_QUANTITY 4
#define K 2
#ifdef _WIN32
#define PTHREAD_FORMAT "%#I64x"
#endif
#ifdef __gnu_linux__
#define PTHREAD_FORMAT "%#lx"
#endif
// #define TOTAL_OPERATION_COUNT (CONSUMER_QUANTITY*PRODUCER_QUANTITY*K)
// #define PRODUCER_OPERATION_COUNT (K*CONSUMER_QUANTITY)
// #define CONSUMER_OPERATION_COUNT (K*PRODUCER_QUANTITY)

#endif