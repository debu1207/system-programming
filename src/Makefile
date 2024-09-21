CC=gcc # preferred compiler

.PHONY: all clean

all: 

%.o: %.c
	$(CC) -c $< -o $@

%: %.o
	$(CC) $^ -o $@

clean:
	rm -f *.o
