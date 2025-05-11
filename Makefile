CC=gcc
CFLAGS=-Wall -g -std=c99
LDFLAGS=-lm

PROGRAM_NAME = quadtree
SOURCE_FILES = main.c tasks.c utilities.c 
OBJECT_FILES = $(patsubst %.c,%.o,$(SOURCE_FILES))

.PHONY: build clean run

build: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(PROGRAM_NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)

clean:
	rm -f $(PROGRAM_NAME) $(OBJECT_FILES)