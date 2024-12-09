CC = g++
TARGET = run
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): dequeTest.o main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o dequeTest.o

deque.o: dequeTest.cpp deque.h
	$(CC) $(CFLAGS) dequeTest.cpp

main.o: main.cpp
	$(CC) $(CLFAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
