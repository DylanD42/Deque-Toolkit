CC = g++
TARGET = run
CFLAGS = -c -Wall -Wextra

all: $(TARGET)

$(TARGET): main.o
	$(CC) -g -Wall -Wextra -o $(TARGET) main.o

main.o: main.cpp
	$(CC) $(CLFAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
