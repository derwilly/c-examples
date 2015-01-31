TARGET = main
CC = gcc
OBJ = main.o
CFLAGS = -c -Wall -O
 
all: $(TARGET)
 
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)
 
%.o: %.cpp
	$(CC) $(CFLAGS) $<
 

clean:
	rm -f $(TARGET)
	rm -f $(OBJ)
