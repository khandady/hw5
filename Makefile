CC=g++
CFLAGS=-Wall -ansi

TARGET=main
HEADERS=ListNode.h LinkedList.h VectorList.h
SOURCES=main.cpp 

$(TARGET): $(SOURCES) $(HEADERS) 		
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) 

