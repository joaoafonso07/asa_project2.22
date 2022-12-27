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

test :
	
	./gerador < tests/test1.txt >> tests/out1.txt
	diff tests/correct1.txt tests/out1.txt

	./gerador < tests/test2.txt >> tests/out2.txt
	diff tests/correct2.txt tests/out2.txt

	rm tests/out1.txt
	rm tests/out2.txt
	echo "Sucess"
clean:
	rm gerador