# Bazingo shell - makefile
# 
# Makefile for the bazingo shell
#
# By @F4doraOfDoom and @Mr-M33533K5 and mostly by @5quirr31_10rd
# 20-12-18

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

CC=g++ -Wall -ansi -pedantic -std=c++17
SOURCES=$(call rwildcard, ./, *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
OUTPUT=out.txt
TARGET=bazingo


$(TARGET): $(OBJECTS)
	$(CC) -g -o $@ $^ 
	
%.o: %.c %.h
	$(CC) -g -c $<

%.o: %.c
	$(CC) -g -c $<

out: $(TARGET)
	-./bazingo 2>$(OUTPUT)
	
clean:
	rm -rf *.o
