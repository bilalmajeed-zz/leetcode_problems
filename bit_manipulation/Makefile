# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

all: $(file)

$(file): $(file).c
	$(CC) $(CFLAGS) -o $(file) $(file).c

clean:
	$(RM) $(file)
