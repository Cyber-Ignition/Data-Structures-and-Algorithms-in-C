CC = gcc
CFLAGS = -Wall -g

EXEC_CQ = circularQueue
EXEC_Q = queue
EXEC_S = stack

SRC_CQ = circularQueue.c
SRC_Q = queue.c
SRC_S = stack.c

all: $(EXEC_CQ) $(EXEC_Q) $(EXEC_S)

$(EXEC_CQ): $(SRC_CQ)
	$(CC) $(CFLAGS) -o $(EXEC_CQ) $(SRC_CQ)

$(EXEC_Q): $(SRC_Q)
	$(CC) $(CFLAGS) -o $(EXEC_Q) $(SRC_Q)

$(EXEC_S): $(SRC_S)
	$(CC) $(CFLAGS) -o $(EXEC_S) $(SRC_S)

run: all
	./$(EXEC_CQ) &
	./$(EXEC_Q) &
	./$(EXEC_S) &

clean:
	rm -f $(EXEC_CQ) $(EXEC_Q) $(EXEC_S)
