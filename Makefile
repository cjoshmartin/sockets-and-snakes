# Author: Nathaniel Cantwell
# Makefile for ECE 282 project 1

# Compiler
CC = gcc

# Compiler flags
CFS =

# Linker flags
#CLNTLFS = -lcurses
SERVLFS = 

# Include directories
INC = -I include

# Binary directory and name
BINDIR = binary
CLIENT = $(BINDIR)/snakeclnt

# Server binary
SERVER = $(BINDIR)/snakeserv

# Primary source code directory and names
SOURCEDIR = Source
CLNTSRC = $(SOURCEDIR)/timeclnt.c
SERVSRC = $(SOURCEDIR)/nat-timeserv.c

# Object file directories and names
BUILDDIR = build
CLNTOBJS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(CLNTSRC))
SERVOBJS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SEVSRC))

# Directory for test executables
TESTDIR = test
TESTS = $(wildcard $(TESTDIR)/*.c)
TESTOBJS = $(patsubst $(TESTDIR)/%.c, $(BUILDDIR)/%.o, $(TESTS))

all: $(CLIENT) $(SERVER)

# Binary executable recipe
$(CLIENT): $(CLNTOBJS)
	$(CC) $^ -o $(TARGET) $(CLNTLFS) $(CFS)

# Binary executable recipe for server
$(CLIENT): $(SERVOBJS)
	$(CC) $^ -o $(TARGET) $(CLNTLFS) $(CFS)

# Object recipes, defined generically
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(INC) $(CFS) -c -o $@ $<

# Testing code object recipes, defined generically
$(BUILDDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(INC) $(CFS) -c -o $@ $<

# Tests



.PHONY: clean
clean:
	rm -f $(BUILDDIR)/* $(BINDIR)/*
