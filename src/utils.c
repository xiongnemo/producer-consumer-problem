#include "utils.h"

void print_time_information(char *name)
{
    struct timeval tp;
    gettimeofday(&tp, 0);
    time_t curtime = tp.tv_sec;
    struct tm *t = localtime(&curtime);
    printf("[INFO] [%d/%d/%d %02d:%02d:%02d.%03ld] %s: \t", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, tp.tv_usec / 1000, name);
}

void print_error_information(char *name, char *information)
{
    struct timeval tp;
    gettimeofday(&tp, 0);
    time_t curtime = tp.tv_sec;
    struct tm *t = localtime(&curtime);
    fprintf(stderr, "[ERROR] [%d/%d/%d %02d:%02d:%02d.%03ld] %s\t: %s", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, tp.tv_usec / 1000, name, information);
}