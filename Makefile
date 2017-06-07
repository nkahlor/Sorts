#!/bin/bash
#file name: Makefile
CC = gcc
CFLAGS =-g -Wall
DEPS = sorts.h
OBJ = main.o sorts.o

#compile stage
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

#link stage -- prog = name of executable. You can change this.
run: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

#target for cleaning -- remove object and executable files
clean:
	rm *.o
	rm run 

