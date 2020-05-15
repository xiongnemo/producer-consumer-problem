CC = gcc
CFLAGS = -Wall -std=c11 -g -pthread
LDFLAGS= -pthread
PROG = producer-consumer-problem
DEPS = producer-consumer-problem.c buffer.c consumers.c producers.c utils.c buffer.h consumers.h producers.h utils.h variables.h
OBJ = producer-consumer-problem.o buffer.o consumers.o producers.o utils.o
 
$(PROG): $(OBJ)
		$(CC) -o $(PROG) $(OBJ) $(LDFLAGS)
		rm -rf $(OBJ)
             
%.o: %.c $(DEPS)
		$(CC) -c $< -o $@ $(CFLAGS)
             
clean:
		rm -rf $(OBJ) $(PROG)