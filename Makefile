# Author: Nathaniel Cantwell
# Makefile for ECE 282 project 1

# Compiler
CC = gcc

# Compiler flags
CFS =

# Include directories
INC = -I Include

# Binary directory and name
BINDIR = Binary
TARGET = $(BINDIR)/note

# Primary source code directory and names
SOURCEDIR = Source
SRCS = $(wildcard $(SOURCEDIR)/*.c)

# Object file directories and names
BUILDDIR = Build
OBJS = $(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Directory for test executables
TESTDIR = Test
TESTS = $(wildcard $(TESTDIR)/*.c)
TESTOBJS = $(patsubst $(TESTDIR)/%.c, $(BUILDDIR)/%.o, $(TESTS))

all: $(TARGET)

# Binary executable recipe
$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET)

# Object recipes, defined generically
$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c
	$(CC) $(INC) $(CFS) -c -o $@ $<

# Testing code object recipes, defined generically
$(BUILDDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(INC) $(CFS) -c -o $@ $<

# Tests
backendtests: $(TESTOBJS) $(OBJS)
	$(CC) $(INC) $(CFS) -o $(BINDIR)/$@ $(BUILDDIR)/backend.o $(BUILDDIR)/backend_tests.o

.PHONY: clean
clean:
	rm -f $(BUILDDIR)/* $(BINDIR)/*
