#
# Makefile for Chapter 11
#
# Type  make    to compile all the programs
# in the chapter 
#
all: tclient tserver dummy

clean:
	rm -f tclient tserver

tclient: client.c
	cc -o tclient client.c
	
dummy: dummyclient.c
	cc -o dummy dummyclient.c

tserver: server.c
	cc -o tserver server.c utilities.c

