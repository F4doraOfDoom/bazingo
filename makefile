# Bazingo shell - makefile
# 
# Makefile for the bazingo shell
#
# By @F4doraOfDoom and @Mr-M33533K5	
# 20-12-18

CC=g++ -g -Wall -ansi -pedantic
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUT=out.txt
TARGET=bazingo


$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ 
	
%.o: %.c %.h
	$(CC) -c $<

%.o: %.c
	$(CC) -c $<

out: $(TARGET)
	-./bazingo 2>$(OUTPUT)
	
clean:
	rm -f *.o
