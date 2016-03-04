#############################################################
##
## Authors: Drew Rife and Brad Olah
## Professor: Dr. Wellington
## Class: SWE 300-01
##
## A standard makefile compile the source code
##
#############################################################
CC = gcc
CFLAGS = -g
DEPS = C_STATE.h
OBJ = C_STATE.o 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

cState: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ) cState