# Makefile
#
# It uses implicit rules to compile .c files using the
# values assigned to macros CC and CFLAGS
#

#the compiler: g++ for C++ 
CC = g++

#compiler flags
CFLAGS = -std=c++11 -O3 -Wall

#The build target
TARGET = project

all: $(TARGET)

$(TARGET): $(TARGET).cpp
			$(CC) $(CFLAGS) -o gerador $(TARGET).cpp -lm


clean:
	rm gerador