TARGET = after2
CC = g++
CFLAGS = -std=c++11 -g -Wall -O1

.PHONY: default all clean
default: $(TARGET)
all: default

HEADERS = *.h
OBJECTS = after2.o

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< 

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean: 
	-rm -f *.o
	-rm -f $(filter-out,$(wildcard *.h))
	-rm -f $(filter-out,$(wildcard *.hpp))
	-rm -f $(filter-out,$(wildcard *.cpp))
	-rm -f $(TARGET)