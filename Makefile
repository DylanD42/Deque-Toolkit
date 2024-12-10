CC = g++
TARGET = run
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): deque.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o deque.o

deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) deque.cpp

main.o: main.cpp
	$(CC) $(CLFAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
